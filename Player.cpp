//--------------------------------------------------------------------------------------
// File: Player.cpp
//
//--------------------------------------------------------------------------------------
#include "pch.h"
#include "Player.h"

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
void Player::Update(int keyCondition, int keyTrigger)
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
}

// 描画関数
void Player::Render()
{
	// プレイヤーの描画
	DrawRectExtendGraph( m_position.x, m_position.y
					   , m_position.x + Player::SIZE, m_position.y + Player::SIZE
					   , 0, 0, 32, 32, m_texture, TRUE);
}

