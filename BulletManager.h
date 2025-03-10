//--------------------------------------------------------------------------------------
// File: BulletManager.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Bullet.h"

// �e�̃}�l�[�W���[
class BulletManager
{
	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �Ǘ��ł���e�̐�
	int m_bulletCount;

	// �e�̃I�u�W�F�N�g�ւ̃|�C���^
	Bullet* m_pBullet;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	BulletManager();

	// �f�X�g���N�^
	~BulletManager();

	// �������֐�
	void Initialize(int bulletCount, int texture);

	// �X�V�֐�
	void Update();

	// �`��֐�
	void Render();

	// �Ǘ��ł���e�̐����擾����֐�
	int GetBulletCount() { return m_bulletCount; }

	// �e�𔭎˂���֐�
	void Shot(POINT position);

};

