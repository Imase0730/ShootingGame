//--------------------------------------------------------------------------------------
// File: GameplayScene.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Player.h"
#include "EnemyManager.h"
#include "BulletManager.h"

// �N���X�̑O���錾
class Game;

// �Q�[���v���C�V�[��
class GameplayScene
{

// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �v���C���[��Y���W
	static constexpr int PLAYER_POSITION_Y = 600;

	// �G�̍ő吔
	static const int ENEMY_MAX = 10;

	// �v���C���[�̒e�̍ő吔
	static constexpr int PLAYER_BULLET_MAX = 3;

	// �G�̒e�̍ő吔
	static constexpr int ENEMY_BULLET_MAX = 100;


// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// ���̃V�[�����܂ރQ�[���I�u�W�F�N�g�ւ̃|�C���^
	Game* m_pGame;

	// �v���C���[
	Player m_player;

	// �G�̃}�l�[�W���[
	EnemyManager m_enemyManager;

	// �v���C���[�̒e�̃}�l�[�W���[
	BulletManager m_playerBulletManager;

	// �G�̒e�̃}�l�[�W���[
	BulletManager m_enemyBulletManager;


// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	GameplayScene(Game* pGame);

	// �f�X�g���N�^
	~GameplayScene();

	// ����������
	void Initialize();

	// �X�V����
	void Update(int keyCondition, int keyTrigger);

	// �`�揈��
	void Render();

	// �I������
	void Finalize();

private:

	// �Q�[���̃e�N�X�`���n���h��
	int m_texture;

	// AABB�̏Փ˔���֐�
	bool IsHit(RECT a, RECT b);

	// �v���C���[�̒e�ƓG�̏Փ˔���
	void HitCheck_PlayerBulletToEnemy();

	// �G�̒e�ƃv���C���[�̏Փ˔���
	void HitCheck_EnemyBulletToPlayer();

};
