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

	// �A�N�e�B�u�Ȃ�true��ݒ�
	bool m_isActive;

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

	// �Փ˔���̎擾�֐�
	RECT GetCollider();

	// �f�[�^���L�������ׂ�֐�
	bool IsActive() { return m_isActive; }

	// ���ł�����֐�
	void OnHit() { m_isActive = false; }

};

