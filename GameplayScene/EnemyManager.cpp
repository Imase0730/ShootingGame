//--------------------------------------------------------------------------------------
// File: EnemyManager.cpp
//
//--------------------------------------------------------------------------------------
#include "pch.h"
#include "EnemyManager.h"
#include "Game/Screen.h"

// �R���X�g���N�^
EnemyManager::EnemyManager()
	: m_enemyCount{ 0 }
	, m_pEnemy{ nullptr }
	, m_spawnCounter{ 0 }
{
}

// �f�X�g���N�^
EnemyManager::~EnemyManager()
{
	// ���������������
	if (m_pEnemy) delete[] m_pEnemy;
}

// �������֐�
void EnemyManager::Initialize(int enemyCount, int texture)
{
	// �Ǘ�����G�̐�
	m_enemyCount = enemyCount;

	// ������x���������m�ۂ���Ă�����������
	if (m_pEnemy) delete[] m_pEnemy;

	// �G�̐������������m�ۂ���
	m_pEnemy = new Enemy[enemyCount];
	for (int i = 0; i < enemyCount; i++)
	{
		// �G��������
		m_pEnemy[i].Initialize(texture);
	}
}

// �X�V�֐�
void EnemyManager::Update(BulletManager* pBulletManager)
{
	for (int i = 0; i < m_enemyCount; i++)
	{
		m_pEnemy[i].Update(pBulletManager);
	}

	// �G�̏o���p�J�E���^�[�̉��Z
	m_spawnCounter++;

	// ���̊Ԋu�œG���o��������
	if (m_spawnCounter > SPAWN_INTERVAL)
	{
		m_spawnCounter = 0;
		// �����_���Ȉʒu�ɉ�ʏ㕔�ɓG���o��������
		POINT pos = { GetRand(Screen::WIDTH - Enemy::SIZE), -Enemy::SIZE };
		AppearEnemy(pos);
	}
}

// �`��֐�
void EnemyManager::Render()
{
	for (int i = 0; i < m_enemyCount; i++)
	{
		m_pEnemy[i].Render();
	}
}

// �G���o��������֐�
void EnemyManager::AppearEnemy(POINT position)
{
	for (int i = 0; i < m_enemyCount; i++)
	{
		// �A�N�e�B�u�łȂ��G���g�p����
		if (!m_pEnemy[i].IsActive())
		{
			// �G���o��������
			m_pEnemy[i].Appear(position);
			return;
		}
	}
}

// �G���擾����֐�
Enemy* EnemyManager::GetEnemy(int idx)
{
	if (idx < 0 || idx >= m_enemyCount || !m_pEnemy[idx].IsActive()) return nullptr;
	return &m_pEnemy[idx];
}

