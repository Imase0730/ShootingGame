//--------------------------------------------------------------------------------------
// File: Enemy.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "BulletManager.h"

// �G
class Enemy
{
	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �傫��
	static constexpr int SIZE = 64;

	// �ړ��̑���
	static constexpr int SPEED = 5;

	// �e�̔��ˊԊu
	static constexpr int SHOT_INTERVAL = 60;

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �A�N�e�B�u�Ȃ�true��ݒ�
	bool m_isActive;

	// �e�N�X�`���n���h��
	int m_texture;

	// �ʒu
	POINT m_position;

	// ���x
	POINT m_velocity;

	// �t���[����
	int m_frameCount;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	Enemy();

	// �f�X�g���N�^
	~Enemy();

	// �������֐�
	void Initialize(int texture);

	// �X�V�֐�
	void Update(BulletManager* pBulletMagager);

	// �`��֐�
	void Render();

	// �G���o��������֐�
	void Appear(POINT position);

	// �f�[�^���L�������ׂ�֐�
	bool IsActive() { return m_isActive; }

	// ���ł�����֐�
	void OnHit() { m_isActive = false; }

};

