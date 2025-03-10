//--------------------------------------------------------------------------------------
// File: Player.cpp
//
//--------------------------------------------------------------------------------------
#include "pch.h"
#include "Player.h"
#include "Game/Screen.h"

// �R���X�g���N�^
Player::Player()
	: m_texture{}
	, m_position{}
	, m_velocity{}
{
}

// �f�X�g���N�^
Player::~Player()
{
}

// �������֐�
void Player::Initialize(int texture, POINT position)
{
	// �e�N�X�`���n���h��
	m_texture = texture;

	// �ʒu
	m_position = position;
}

// �X�V�֐�
void Player::Update(int keyCondition, int keyTrigger, BulletManager* pBulletManager)
{
	// ���E�L�[�Ńv���C���[���ړ�
	m_velocity = POINT{ 0, 0 };
	if (keyCondition & PAD_INPUT_RIGHT)
	{
		m_velocity.x = Player::SPEED;
	}
	if (keyCondition & PAD_INPUT_LEFT)
	{
		m_velocity.x = -Player::SPEED;
	}

	// �ʒu�ɑ��x�𑫂�
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// �v���C���[����ʊO�֏o�Ȃ��悤�Ɉʒu�𒲐�
	if (m_position.x < 0)
	{
		m_position.x = 0;
	}
	if (m_position.x > Screen::WIDTH - Player::SIZE)
	{
		m_position.x = Screen::WIDTH - Player::SIZE;
	}

	// �X�y�[�X�L�[�Œe�𔭎�
	if (keyTrigger & PAD_INPUT_10)
	{
		// �e���v���C���[�̒������甭�˂���
		POINT position = m_position;
		position.x += (Player::SIZE - Bullet::SIZE) / 2;
		pBulletManager->Shot(position);
	}
}

// �`��֐�
void Player::Render()
{
	// �v���C���[�̕`��
	DrawRectExtendGraph( m_position.x, m_position.y
					   , m_position.x + Player::SIZE, m_position.y + Player::SIZE
					   , 0, 0, 32, 32, m_texture, TRUE);
}

