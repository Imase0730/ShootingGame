//--------------------------------------------------------------------------------------
// File: Player.cpp
//
//--------------------------------------------------------------------------------------
#include "pch.h"
#include "Player.h"
#include "Game/Screen.h"

// コンストラクタ
Player::Player()
	: m_texture{}
	, m_position{}
	, m_velocity{}
{
}

// デストラクタ
Player::~Player()
{
}

// 初期化関数
void Player::Initialize(int texture, POINT position)
{
	// テクスチャハンドル
	m_texture = texture;

	// 位置
	m_position = position;
}

// 更新関数
void Player::Update(int keyCondition, int keyTrigger, BulletManager* pBulletManager)
{
	// 左右キーでプレイヤーを移動
	m_velocity = POINT{ 0, 0 };
	if (keyCondition & PAD_INPUT_RIGHT)
	{
		m_velocity.x = Player::SPEED;
	}
	if (keyCondition & PAD_INPUT_LEFT)
	{
		m_velocity.x = -Player::SPEED;
	}

	// 位置に速度を足す
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// プレイヤーが画面外へ出ないように位置を調整
	if (m_position.x < 0)
	{
		m_position.x = 0;
	}
	if (m_position.x > Screen::WIDTH - Player::SIZE)
	{
		m_position.x = Screen::WIDTH - Player::SIZE;
	}

	// スペースキーで弾を発射
	if (keyTrigger & PAD_INPUT_10)
	{
		// 弾をプレイヤーの中央から発射する
		POINT position = m_position;
		position.x += (Player::SIZE - Bullet::SIZE) / 2;
		pBulletManager->Shot(position);
	}
}

// 描画関数
void Player::Render()
{
	// プレイヤーの描画
	DrawRectExtendGraph( m_position.x, m_position.y
					   , m_position.x + Player::SIZE, m_position.y + Player::SIZE
					   , 0, 0, 32, 32, m_texture, TRUE);
}

