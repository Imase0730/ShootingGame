//--------------------------------------------------------------------------------------
// File: EnemyManager.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Enemy.h"
#include "BulletManager.h"

// �G�̃}�l�[�W���[
class EnemyManager
{
	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �G�̏o���Ԋu
	static constexpr int SPAWN_INTERVAL = 10;

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �Ǘ��ł���G�̐�
	int m_enemyCount;

	// �G�̃I�u�W�F�N�g�ւ̃|�C���^
	Enemy* m_pEnemy;

	// �G�̏o���p�J�E���^�[
	int  m_spawnCounter;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	EnemyManager();

	// �f�X�g���N�^
	~EnemyManager();

	// �������֐�
	void Initialize(int enemyCount, int texture);

	// �X�V�֐�
	void Update(BulletManager* pBulletManager);

	// �`��֐�
	void Render();

	// �G���o��������֐�
	void AppearEnemy(POINT position);

};

