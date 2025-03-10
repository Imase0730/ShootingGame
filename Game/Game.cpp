//--------------------------------------------------------------------------------------
// File: Game.cpp
//
//--------------------------------------------------------------------------------------
#include "Game.h"
#include "Game/Screen.h"

// コンストラクタ
Game::Game()
	: m_frameTimer{}
	, m_currentSceneID{ SceneID::NONE }
	, m_requestedSceneID{ SceneID::NONE }
	, m_key{}
	, m_oldKey{}
	, m_gameplayScene{ this }
	, m_titleScene{ this }
{
	// 乱数の初期値を設定
	SRand(static_cast<int>(time(NULL)));
}

// デストラクタ
Game::~Game()
{
}

// 初期化処理
void Game::Initialize()
{
	SetStartScene(SceneID::TITLE);
}

// 更新処理
void Game::Update()
{
	// フレームタイマーの更新
	m_frameTimer.Update();

	// キー入力の取得
	m_oldKey = m_key;
	m_key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// シーンの切り替えリクエストがある？
	if (m_requestedSceneID != SceneID::NONE)
	{
		// シーンを切り替える
		ChangeScene();
	}

	// 現在のシーンを更新
	UpdateCurrentScene(m_key, ~m_oldKey & m_key);
}

// 描画処理
void Game::Render()
{
	// 現在のシーンを描画
	RenderCurrentScene();

	// FPSの描画
	DrawFormatString(10, 10, GetColor(255, 255, 255), L"%3.0ffps", m_frameTimer.GetFrameRate());
}

// 終了処理
void Game::Finalize()
{
	// ゲームの終了処理

	// 現在のシーンの終了処理
	FinalizeCurrentScene();

}

// シーン変更の要求
void Game::RequestSceneChange(SceneID nextSceneID)
{
	m_requestedSceneID = nextSceneID;
}

// 開始シーンの設定
void Game::SetStartScene(SceneID startSceneID)
{
	m_currentSceneID = startSceneID;
	InitializeCurrentScene();
}

// シーンの変更
void Game::ChangeScene()
{
	// 現在のシーンを終了させる
	FinalizeCurrentScene();
	// シーンIDの変更
	m_currentSceneID = m_requestedSceneID;
	// 新しいシーンを初期化する
	InitializeCurrentScene();
	// シーンの変更が終わったので変更要求をリセット
	m_requestedSceneID = SceneID::NONE;
}

// 現在のシーンの初期化処理
void Game::InitializeCurrentScene()
{
	switch (m_currentSceneID)
	{
		// タイトルシーン
	case SceneID::TITLE:
		m_titleScene.Initialize();
		break;
		// プレイシーン
	case SceneID::GAMEPLAY:
		m_gameplayScene.Initialize();
		break;
		// リザルトシーン
	case SceneID::RESULT:
		//m_resultScene.Initialize();
		break;
	default:
		break;
	}
}

// 現在のシーンの更新処理
void Game::UpdateCurrentScene(int keyCondition, int keyTrigger)
{
	switch (m_currentSceneID)
	{
		// タイトルシーン
	case SceneID::TITLE:
		m_titleScene.Update(keyCondition, keyTrigger);
		break;
		// プレイシーン
	case SceneID::GAMEPLAY:
		m_gameplayScene.Update(keyCondition, keyTrigger);
		break;
		// リザルトシーン
	case SceneID::RESULT:
		//m_resultScene.Update(m_joypad);
		break;
	default:
		break;
	}
}

// 現在のシーンの描画処理
void Game::RenderCurrentScene()
{
	switch (m_currentSceneID)
	{
		// タイトルシーン
	case SceneID::TITLE:
		m_titleScene.Render();
		break;
		// プレイシーン
	case SceneID::GAMEPLAY:
		m_gameplayScene.Render();
		break;
		// リザルトシーン
	case SceneID::RESULT:
		//m_resultScene.Render();
		break;
	default:
		break;
	}

}

// 現在のシーンの終了処理
void Game::FinalizeCurrentScene()
{
	switch (m_currentSceneID)
	{
		// タイトルシーン
	case SceneID::TITLE:
		m_titleScene.Finalize();
		break;
		// プレイシーン
	case SceneID::GAMEPLAY:
		m_gameplayScene.Finalize();
		break;
		// リザルトシーン
	case SceneID::RESULT:
		//m_resultScene.Finalize();
		break;
	default:
		break;
	}
}

