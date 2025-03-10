//--------------------------------------------------------------------------------------
// File: EnemyManager.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Enemy.h"
#include "BulletManager.h"

// 敵のマネージャー
class EnemyManager
{
	// クラス定数の宣言 -------------------------------------------------
public:

	// 敵の出現間隔
	static constexpr int SPAWN_INTERVAL = 10;

	// データメンバの宣言 -----------------------------------------------
private:

	// 管理できる敵の数
	int m_enemyCount;

	// 敵のオブジェクトへのポインタ
	Enemy* m_pEnemy;

	// 敵の出現用カウンター
	int  m_spawnCounter;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	EnemyManager();

	// デストラクタ
	~EnemyManager();

	// 初期化関数
	void Initialize(int enemyCount, int texture);

	// 更新関数
	void Update(BulletManager* pBulletManager);

	// 描画関数
	void Render();

	// 敵を出現させる関数
	void AppearEnemy(POINT position);

};

