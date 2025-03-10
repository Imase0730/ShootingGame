//--------------------------------------------------------------------------------------
// File: Game.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "TitleScene/TitleScene.h"
#include "GameplayScene/GameplayScene.h"

// ゲーム
class Game
{
	// 列挙型の定義 -----------------------------------------------------
public:

	// シーンID
	enum class SceneID
	{
		NONE = -1,
		TITLE,
		GAMEPLAY,
		RESULT
	};

	// クラス定数の宣言 -------------------------------------------------
public:

	// ゲームタイトル
	static constexpr const wchar_t* TITLE = L"Sample Game";


	// データメンバの宣言 -----------------------------------------------
private:

	// フレームタイマー
	GameLib::FrameTimer m_frameTimer;

	// キー情報
	int m_key;
	int m_oldKey;

	SceneID m_currentSceneID;	// 現在のシーンID
	SceneID m_requestedSceneID;	// 変更要求のシーンID

	// シーンオブジェクト
	GameplayScene m_gameplayScene;	// ゲームプレイシーン
	TitleScene m_titleScene;		// タイトルシーン

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	Game();

	// デストラクタ
	~Game();

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update();

	// 描画処理
	void Render();

	// 終了処理
	void Finalize();

	// シーン変更の要求
	void RequestSceneChange(SceneID nextSceneID);

private:

	// 開始シーンの設定
	void SetStartScene(SceneID startSceneID);

	// シーンの変更
	void ChangeScene();

	// 現在のシーンの初期化処理
	void InitializeCurrentScene();

	// 現在のシーンの更新処理
	void UpdateCurrentScene(int keyCondition, int keyTrigger);

	// 現在のシーンの描画処理
	void RenderCurrentScene();

	// 現在のシーンの終了処理
	void FinalizeCurrentScene();

};
