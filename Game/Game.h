//--------------------------------------------------------------------------------------
// File: Game.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Player.h"
#include "BulletManager.h"
#include "EnemyManager.h"

// ゲーム
class Game
{
	// 列挙型の定義 -----------------------------------------------------
public:


	// クラス定数の宣言 -------------------------------------------------
public:

	// ゲームタイトル
	static constexpr const wchar_t* TITLE = L"Sample Game";

	// プレイヤーのY座標
	static constexpr int PLAYER_POSITION_Y = 600;

	// 敵の最大数
	static constexpr int ENEMY_MAX = 10;

	// プレイヤーの弾の最大数
	static constexpr int PLAYER_BULLET_MAX = 3;

	// 敵の弾の最大数
	static constexpr int ENEMY_BULLET_MAX = 100;

	// データメンバの宣言 -----------------------------------------------
private:

	// フレームタイマー
	GameLib::FrameTimer m_frameTimer;

	// キー情報
	int m_key;
	int m_oldKey;

	// テクスチャハンドル
	int m_texture;

	// プレイヤー
	Player m_player;

	// 敵のマネージャー
	EnemyManager m_enemyManager;

	// プレイヤーの弾のマネージャー
	BulletManager m_playerBulletManager;

	// 敵の弾のマネージャー
	BulletManager m_enemyBulletManager;

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
