//--------------------------------------------------------------------------------------
// File: Player.cpp
//
//--------------------------------------------------------------------------------------
#include "pch.h"
#include "Player.h"

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
void Player::Update(int keyCondition, int keyTrigger)
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
}

// �`��֐�
void Player::Render()
{
	// �v���C���[�̕`��
	DrawRectExtendGraph( m_position.x, m_position.y
					   , m_position.x + Player::SIZE, m_position.y + Player::SIZE
					   , 0, 0, 32, 32, m_texture, TRUE);
}

