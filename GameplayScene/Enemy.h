//--------------------------------------------------------------------------------------
// File: Enemy.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "BulletManager.h"

// 敵
class Enemy
{
	// クラス定数の宣言 -------------------------------------------------
public:

	// 大きさ
	static constexpr int SIZE = 64;

	// 移動の速さ
	static constexpr int SPEED = 5;

	// 弾の発射間隔
	static constexpr int SHOT_INTERVAL = 60;

	// データメンバの宣言 -----------------------------------------------
private:

	// アクティブならtrueを設定
	bool m_isActive;

	// テクスチャハンドル
	int m_texture;

	// 位置
	POINT m_position;

	// 速度
	POINT m_velocity;

	// フレーム数
	int m_frameCount;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	Enemy();

	// デストラクタ
	~Enemy();

	// 初期化関数
	void Initialize(int texture);

	// 更新関数
	void Update(BulletManager* pBulletMagager);

	// 描画関数
	void Render();

	// 敵を出現させる関数
	void Appear(POINT position);

	// データが有効か調べる関数
	bool IsActive() { return m_isActive; }

	// 衝突判定の取得関数
	RECT GetCollider();

	// 消滅させる関数
	void OnHit() { m_isActive = false; }

};

