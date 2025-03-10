//--------------------------------------------------------------------------------------
// File: Enemy.cpp
//
//--------------------------------------------------------------------------------------
#include "pch.h"
#include "Enemy.h"
#include "Game/Screen.h"

// コンストラクタ
Enemy::Enemy()
	: m_isActive{ false }
	, m_texture{}
	, m_position{}
	, m_velocity{}
	, m_frameCount{}
{
}

// デストラクタ
Enemy::~Enemy()
{
}

// 初期化関数
void Enemy::Initialize(int texture)
{
	// テクスチャハンドル
	m_texture = texture;

	// 速度
	m_velocity.x = 0;
	m_velocity.y = Enemy::SPEED;
}

// 更新関数
void Enemy::Update(BulletManager* pBulletManager)
{
	// アクティブでないなら更新しない
	if (!IsActive()) return;

	// フレーム数を加算
	m_frameCount++;

	// 位置に速度を足す
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// 一定間隔で弾を発射
	if (m_frameCount % SHOT_INTERVAL == 0)
	{
		// 弾を敵の中央から発射する
		POINT position = m_position;
		position.x += (Enemy::SIZE - Bullet::SIZE) / 2;
		position.y += Enemy::SIZE - Bullet::SIZE;
		pBulletManager->Shot(position);
	}

	// 画面外なら
	if ( (m_position.x < -Enemy::SIZE) || (m_position.x > Screen::WIDTH)
	  || (m_position.y < -Enemy::SIZE) || (m_position.y > Screen::HEIGHT)
	   )
	{
		// 非アクティブに設定
		m_isActive = false;
	}
}

// 描画関数
void Enemy::Render()
{
	if (m_isActive)
	{
		DrawRectExtendGraph( m_position.x, m_position.y
						   , m_position.x + Enemy::SIZE, m_position.y + Enemy::SIZE
						   , 32 * 3, 0, 32, 32, m_texture, TRUE );
	}
}

// 敵を出現させる関数
void Enemy::Appear(POINT position)
{
	// アクティブ
	m_isActive = true;

	// 位置
	m_position = position;
}

// 衝突判定の取得関数
RECT Enemy::GetCollider()
{
	RECT rect{};

	rect.left = m_position.x;
	rect.right = m_position.x + Enemy::SIZE;
	rect.top = m_position.y;
	rect.bottom = m_position.y + Enemy::SIZE;

	return rect;
}
