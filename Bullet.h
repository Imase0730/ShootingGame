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

	// �e�̃^�C�v
	enum class Type { None, Player, Enemy, TypeNum };

	// �e�̑傫��
	static constexpr int SIZE = 16;

	// �e�^�C�v���̒e�̑���
	static constexpr POINT SPEED[static_cast<int>(Type::TypeNum)] =
	{
		{ 0, 0 }, { 0, -10 }, { 0, 10 }
	};

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

	// �^�C�v
	Type m_type;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	Bullet();

	// �f�X�g���N�^
	~Bullet();

	// �������֐�
	void Initialize(int texture, Bullet::Type type);

	// �X�V�֐�
	void Update();

	// �`��֐�
	void Render();

	// �e�𔭎˂���֐�
	void Shot(POINT position);

	// �f�[�^���L�������ׂ�֐�
	bool IsActive() { return m_isActive; }

};

