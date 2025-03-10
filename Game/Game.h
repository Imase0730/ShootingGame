//--------------------------------------------------------------------------------------
// File: Game.h
//
//--------------------------------------------------------------------------------------
#pragma once


// ゲーム
class Game
{
	// 列挙型の定義 -----------------------------------------------------
public:


	// クラス定数の宣言 -------------------------------------------------
public:

	// ゲームタイトル
	static constexpr const wchar_t* TITLE = L"Sample Game";

	// プレイヤーの大きさ
	static constexpr int PLAYER_SIZE = 100;

	// データメンバの宣言 -----------------------------------------------
private:

	// フレームタイマー
	GameLib::FrameTimer m_frameTimer;

	// キー情報
	int m_key;
	int m_oldKey;

	// テクスチャハンドル
	int m_playerTexture;
	int m_texture;

	// プレイヤーの位置
	POINT m_playerPosition;

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

};
