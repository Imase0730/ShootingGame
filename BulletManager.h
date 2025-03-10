//--------------------------------------------------------------------------------------
// File: BulletManager.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Bullet.h"

// 弾のマネージャー
class BulletManager
{
	// データメンバの宣言 -----------------------------------------------
private:

	// 管理できる弾の数
	int m_bulletCount;

	// 弾のオブジェクトへのポインタ
	Bullet* m_pBullet;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	BulletManager();

	// デストラクタ
	~BulletManager();

	// 初期化関数
	void Initialize(int bulletCount, int texture);

	// 更新関数
	void Update();

	// 描画関数
	void Render();

	// 管理できる弾の数を取得する関数
	int GetBulletCount() { return m_bulletCount; }

	// 弾を発射する関数
	void Shot(POINT position);

};

