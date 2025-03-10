//--------------------------------------------------------------------------------------
// File: TitleScene.cpp
//
//--------------------------------------------------------------------------------------
#include "TitleScene.h"
#include "Game/Game.h"

// �R���X�g���N�^
TitleScene::TitleScene(Game* pGame)
	: m_pGame{ pGame }
{

}

// �f�X�g���N�^
TitleScene::~TitleScene()
{

}

// ����������
void TitleScene::Initialize()
{

}

// �X�V����
void TitleScene::Update(int keyCondition, int keyTrigger)
{
	// �X�y�[�X�L�[�ŃQ�[���v���C�V�[����
	if (keyTrigger & PAD_INPUT_10)
	{
		m_pGame->RequestSceneChange(Game::SceneID::GAMEPLAY);
	}
}

// �`�揈��
void TitleScene::Render()
{
	DrawFormatString(10, 30, GetColor(255, 255, 255), L"�^�C�g���V�[��");
}

// �I������
void TitleScene::Finalize()
{

}

