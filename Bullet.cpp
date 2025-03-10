//--------------------------------------------------------------------------------------
// File: Bullet.cpp
//
//--------------------------------------------------------------------------------------
#include "pch.h"
#include "Bullet.h"
#include "Game/Screen.h"

// �R���X�g���N�^
Bullet::Bullet()
	: m_isActive{ false }
	, m_texture{}
	, m_position{}
	, m_velocity{}
	, m_type{ Type::None }
{
}

// �f�X�g���N�^
Bullet::~Bullet()
{
}

// �������֐�
void Bullet::Initialize(int texture, Bullet::Type type)
{
	// �e�N�X�`���n���h��
	m_texture = texture;

	// ���x
	m_velocity = Bullet::SPEED[static_cast<int>(type)];

	// �^�C�v
	m_type = type;
}

// �X�V�֐�
void Bullet::Update()
{
	// �A�N�e�B�u�łȂ��Ȃ�X�V���Ȃ�
	if (!IsActive()) return;

	// �ʒu�ɑ��x�𑫂�
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// ��ʊO�Ȃ�
	if ( (m_position.x < -Bullet::SIZE) || (m_position.x > Screen::WIDTH)
	  || (m_position.y < -Bullet::SIZE) || (m_position.y > Screen::HEIGHT)
	   )
	{
		// ��A�N�e�B�u�ɐݒ�
		m_isActive = false;
	}
}

// �`��֐�
void Bullet::Render()
{
	// �A�N�e�B�u�łȂ��Ȃ�X�V���Ȃ�
	if (!IsActive()) return;

	if (m_type == Type::Player)
	{
		// ���F�̒e
		DrawRectExtendGraph( m_position.x, m_position.y
						   , m_position.x + Bullet::SIZE, m_position.y + Bullet::SIZE
						   , 64, 32, 16, 16, m_texture, TRUE );
	}
	else if (m_type == Type::Enemy) {
		// �Ԏ��̒e
		DrawRectExtendGraph( m_position.x, m_position.y
						   , m_position.x + Bullet::SIZE, m_position.y + Bullet::SIZE
						   , 64 + 16, 32, 16, 16, m_texture, TRUE );
	}
}

// �e�𔭎˂���֐�
void Bullet::Shot(POINT position)
{
	// �A�N�e�B�u
	m_isActive = true;

	// �ʒu
	m_position = position;
}

