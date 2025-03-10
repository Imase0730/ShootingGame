//--------------------------------------------------------------------------------------
// File: Enemy.cpp
//
//--------------------------------------------------------------------------------------
#include "pch.h"
#include "Enemy.h"
#include "Game/Screen.h"

// �R���X�g���N�^
Enemy::Enemy()
	: m_isActive{ false }
	, m_texture{}
	, m_position{}
	, m_velocity{}
	, m_frameCount{}
{
}

// �f�X�g���N�^
Enemy::~Enemy()
{
}

// �������֐�
void Enemy::Initialize(int texture)
{
	// �e�N�X�`���n���h��
	m_texture = texture;

	// ���x
	m_velocity.x = 0;
	m_velocity.y = Enemy::SPEED;
}

// �X�V�֐�
void Enemy::Update(BulletManager* pBulletManager)
{
	// �A�N�e�B�u�łȂ��Ȃ�X�V���Ȃ�
	if (!IsActive()) return;

	// �t���[���������Z
	m_frameCount++;

	// �ʒu�ɑ��x�𑫂�
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// ���Ԋu�Œe�𔭎�
	if (m_frameCount % SHOT_INTERVAL == 0)
	{
		// �e��G�̒������甭�˂���
		POINT position = m_position;
		position.x += (Enemy::SIZE - Bullet::SIZE) / 2;
		position.y += Enemy::SIZE - Bullet::SIZE;
		pBulletManager->Shot(position);
	}

	// ��ʊO�Ȃ�
	if ( (m_position.x < -Enemy::SIZE) || (m_position.x > Screen::WIDTH)
	  || (m_position.y < -Enemy::SIZE) || (m_position.y > Screen::HEIGHT)
	   )
	{
		// ��A�N�e�B�u�ɐݒ�
		m_isActive = false;
	}
}

// �`��֐�
void Enemy::Render()
{
	if (m_isActive)
	{
		DrawRectExtendGraph( m_position.x, m_position.y
						   , m_position.x + Enemy::SIZE, m_position.y + Enemy::SIZE
						   , 32 * 3, 0, 32, 32, m_texture, TRUE );
	}
}

// �G���o��������֐�
void Enemy::Appear(POINT position)
{
	// �A�N�e�B�u
	m_isActive = true;

	// �ʒu
	m_position = position;
}

// �Փ˔���̎擾�֐�
RECT Enemy::GetCollider()
{
	RECT rect{};

	rect.left = m_position.x;
	rect.right = m_position.x + Enemy::SIZE;
	rect.top = m_position.y;
	rect.bottom = m_position.y + Enemy::SIZE;

	return rect;
}
