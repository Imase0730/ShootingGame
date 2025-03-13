//--------------------------------------------------------------------------------------
// File: GameplayScene.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Player.h"
#include "EnemyManager.h"
#include "BulletManager.h"

// クラスの前方宣言
class Game;

// ゲームプレイシーン
class GameplayScene
{

// クラス定数の宣言 -------------------------------------------------
public:

	// プレイヤーのY座標
	static constexpr int PLAYER_POSITION_Y = 600;

	// 敵の最大数
	static const int ENEMY_MAX = 10;

	// プレイヤーの弾の最大数
	static constexpr int PLAYER_BULLET_MAX = 3;

	// 敵の弾の最大数
	static constexpr int ENEMY_BULLET_MAX = 100;


// データメンバの宣言 -----------------------------------------------
private:

	// このシーンを含むゲームオブジェクトへのポインタ
	Game* m_pGame;

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
	GameplayScene(Game* pGame);

	// デストラクタ
	~GameplayScene();

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update(int keyCondition, int keyTrigger);

	// 描画処理
	void Render();

	// 終了処理
	void Finalize();

private:

	// ゲームのテクスチャハンドル
	int m_texture;

	// AABBの衝突判定関数
	bool IsHit(RECT a, RECT b);

	// プレイヤーの弾と敵の衝突判定
	void HitCheck_PlayerBulletToEnemy();

	// 敵の弾とプレイヤーの衝突判定
	void HitCheck_EnemyBulletToPlayer();

};
