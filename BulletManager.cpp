//--------------------------------------------------------------------------------------
// File: BulletManager.cpp
//
//--------------------------------------------------------------------------------------
#include "pch.h"
#include "BulletManager.h"

// �R���X�g���N�^
BulletManager::BulletManager()
	: m_bulletCount{ 0 }
	, m_pBullet{ nullptr }
{
}

// �f�X�g���N�^
BulletManager::~BulletManager()
{
	// ���������������
	if (m_pBullet) delete[] m_pBullet;
}

// �������֐�
void BulletManager::Initialize(int bulletCount, int texture)
{
	// �Ǘ�����e�̐�
	m_bulletCount = bulletCount;

	// ������x���������m�ۂ���Ă�����������
	if (m_pBullet) delete[] m_pBullet;

	// �e�̐������������m�ۂ���
	m_pBullet = new Bullet[bulletCount];
	for (int i = 0; i < bulletCount; i++)
	{
		// �e��������
		m_pBullet[i].Initialize(texture);
	}
}

// �X�V�֐�
void BulletManager::Update()
{
	for (int i = 0; i < m_bulletCount; i++)
	{
		if (m_pBullet[i].IsActive())
		{
			m_pBullet[i].Update();
		}
	}
}

// �`��֐�
void BulletManager::Render()
{
	for (int i = 0; i < m_bulletCount; i++)
	{
		if (m_pBullet[i].IsActive())
		{
			m_pBullet[i].Render();
		}
	}
}

// �e�𔭎˂���֐�
void BulletManager::Shot(POINT position)
{
	for (int i = 0; i < m_bulletCount; i++)
	{
		// �A�N�e�B�u�łȂ��e���g�p����
		if (!m_pBullet[i].IsActive())
		{
			// �e�𔭎˂���
			m_pBullet[i].Shot(position);
			return;
		}
	}
}

