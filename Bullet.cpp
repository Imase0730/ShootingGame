//--------------------------------------------------------------------------------------
// File: Bullet.cpp
//
//--------------------------------------------------------------------------------------
#include "pch.h"
#include "Bullet.h"
#include "Game/Screen.h"

// コンストラクタ
Bullet::Bullet()
	: m_isActive{ false }
	, m_texture{}
	, m_position{}
	, m_velocity{}
	, m_type{ Type::None }
{
}

// デストラクタ
Bullet::~Bullet()
{
}

// 初期化関数
void Bullet::Initialize(int texture, Bullet::Type type)
{
	// テクスチャハンドル
	m_texture = texture;

	// 速度
	m_velocity = Bullet::SPEED[static_cast<int>(type)];

	// タイプ
	m_type = type;
}

// 更新関数
void Bullet::Update()
{
	// アクティブでないなら更新しない
	if (!IsActive()) return;

	// 位置に速度を足す
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// 画面外なら
	if ( (m_position.x < -Bullet::SIZE) || (m_position.x > Screen::WIDTH)
	  || (m_position.y < -Bullet::SIZE) || (m_position.y > Screen::HEIGHT)
	   )
	{
		// 非アクティブに設定
		m_isActive = false;
	}
}

// 描画関数
void Bullet::Render()
{
	// アクティブでないなら更新しない
	if (!IsActive()) return;

	if (m_type == Type::Player)
	{
		// 黄色の弾
		DrawRectExtendGraph( m_position.x, m_position.y
						   , m_position.x + Bullet::SIZE, m_position.y + Bullet::SIZE
						   , 64, 32, 16, 16, m_texture, TRUE );
	}
	else if (m_type == Type::Enemy) {
		// 赤紫の弾
		DrawRectExtendGraph( m_position.x, m_position.y
						   , m_position.x + Bullet::SIZE, m_position.y + Bullet::SIZE
						   , 64 + 16, 32, 16, 16, m_texture, TRUE );
	}
}

// 弾を発射する関数
void Bullet::Shot(POINT position)
{
	// アクティブ
	m_isActive = true;

	// 位置
	m_position = position;
}

