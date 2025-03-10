//--------------------------------------------------------------------------------------
// File: Player.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "BulletManager.h"

// �v���C���[
class Player
{
	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �傫��
	static constexpr int SIZE = 64;

	// �ړ��̑���
	static constexpr int SPEED = 5;

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �e�N�X�`���n���h��
	int m_texture;

	// �ʒu
	POINT m_position;

	// ���x
	POINT m_velocity;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	Player();

	// �f�X�g���N�^
	~Player();

	// �������֐�
	void Initialize(int texture, POINT position);

	// �X�V�֐�
	void Update(int keyCondition, int keyTrigger, BulletManager* pBulletManager);

	// �`��֐�
	void Render();

	// �ʒu�̎擾�֐�
	POINT GetPosition() { return m_position; }

};

