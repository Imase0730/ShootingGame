//--------------------------------------------------------------------------------------
// File: Bullet.h
//
//--------------------------------------------------------------------------------------
#pragma once

// �e
class Bullet
{
	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �e�̑傫��
	static constexpr int SIZE = 16;

	// �e�^�C�v���̒e�̑���
	static constexpr POINT SPEED = { 0, -10 };

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
	Bullet();

	// �f�X�g���N�^
	~Bullet();

	// �������֐�
	void Initialize(int texture);

	// �X�V�֐�
	void Update();

	// �`��֐�
	void Render();

	// �e�𔭎˂���֐�
	void Shot(POINT position);

	// �f�[�^���L�������ׂ�֐�
	bool IsActive() { return m_isActive; }

};

