//--------------------------------------------------------------------------------------
// File: GameplayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GameplayScene.h"
#include "Game/Game.h"
#include "Game/Screen.h"

// �R���X�g���N�^
GameplayScene::GameplayScene(Game* pGame)
	: m_pGame{ pGame }
	, m_texture{}
{

}

// �f�X�g���N�^
GameplayScene::~GameplayScene()
{

}

// ����������
void GameplayScene::Initialize()
{
	// �e�N�X�`���̓ǂݍ���
	m_texture = LoadGraph(L"Resources/Textures/ShootingGame.png");

	// �v���C���[�̏������iX���W�͉�ʂ̒����ցj
	POINT position = { (Screen::WIDTH - Player::SIZE) / 2, PLAYER_POSITION_Y };
	m_player.Initialize(m_texture, position);

	// �G�̃}�l�[�W���[�̏�����
	m_enemyManager.Initialize(ENEMY_MAX, m_texture);

	// �v���C���[�̒e�̃}�l�[�W���[�̏�����
	m_playerBulletManager.Initialize(PLAYER_BULLET_MAX, m_texture, Bullet::Type::Player);

	// �G�̒e�̃}�l�[�W���[�̏�����
	m_enemyBulletManager.Initialize(ENEMY_BULLET_MAX, m_texture, Bullet::Type::Enemy);
}

// �X�V����
void GameplayScene::Update(int keyCondition, int keyTrigger)
{
	// �v���C���[�̍X�V
	m_player.Update(keyCondition, keyTrigger, &m_playerBulletManager);

	// �G�̃}�l�[�W���[�̍X�V
	m_enemyManager.Update(&m_enemyBulletManager);

	// �v���C���[�̒e�̃}�l�[�W���[�̍X�V
	m_playerBulletManager.Update();

	// �G�̒e�̃}�l�[�W���[�̍X�V
	m_enemyBulletManager.Update();

	// �v���C���[�̒e�ƓG�̏Փ˔���
	HitCheck_PlayerBulletToEnemy();
	
	// �G�̒e�ƃv���C���[�̏Փ˔���
	HitCheck_EnemyBulletToPlayer();
}

// �`�揈��
void GameplayScene::Render()
{
	// �v���C���[�̕`��
	m_player.Render();

	// �G�̕`��
	m_enemyManager.Render();

	// �v���C���[�̒e�̕`��
	m_playerBulletManager.Render();

	// �G�̒e�̕`��
	m_enemyBulletManager.Render();

	DrawFormatString(10, 30, GetColor(255, 255, 255), L"�Q�[���v���C�V�[��");
}

// �I������
void GameplayScene::Finalize()
{
	// �e�N�X�`���f�[�^������������폜
	DeleteGraph(m_texture);
}

// AABB�̏Փ˔���֐�
bool GameplayScene::IsHit(RECT a, RECT b)
{
	if ( (a.left < b.right && b.left < a.right)
	  && (a.top < b.bottom && b.top < a.bottom)
	   )
	{
		return true;
	}
	return false;
}

// �v���C���[�̒e�ƓG�̏Փ˔���
void GameplayScene::HitCheck_PlayerBulletToEnemy()
{
	// �v���C���[�̒e�ƓG�̏Փ˔���
	for (int j = 0; j < m_playerBulletManager.GetBulletCount(); j++)
	{
		// �v���C���[�̒e���L���Ȃ�
		Bullet* pBullet = m_playerBulletManager.GetBullet(j);
		if (pBullet)
		{
			for (int i = 0; i < m_enemyManager.GetEnemyCount(); i++)
			{
				// �G���L���Ȃ�
				Enemy* pEnemy = m_enemyManager.GetEnemy(i);
				if (pEnemy)
				{
					// �Փ˂��Ă�����
					if (IsHit(pBullet->GetCollider(), pEnemy->GetCollider()))
					{
						// �Փˎ��̊֐����Ăяo��
						pBullet->OnHit();
						pEnemy->OnHit();
					}
				}
			}
		}
	}
}

// �G�̒e�ƃv���C���[�̏Փ˔���
void GameplayScene::HitCheck_EnemyBulletToPlayer()
{
	// �G�̒e�ƃv���C���[�̏Փ˔���
	if (m_player.IsActive())
	{
		for (int i = 0; i < m_enemyBulletManager.GetBulletCount(); i++)
		{
			// �G�̒e���L���Ȃ�
			Bullet* pBullet = m_enemyBulletManager.GetBullet(i);
			if (pBullet)
			{
				// �Փ˂��Ă�����
				if (IsHit(m_player.GetCollider(), pBullet->GetCollider()))
				{
					// �Փˎ��̊֐����Ăяo��
					m_player.OnHit();
					pBullet->OnHit();
					m_pGame->RequestSceneChange(Game::SceneID::TITLE);
				}
			}
		}
	}
}
