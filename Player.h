//--------------------------------------------------------------------------------------
// File: Player.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "BulletManager.h"

// プレイヤー
class Player
{
	// クラス定数の宣言 -------------------------------------------------
public:

	// 大きさ
	static constexpr int SIZE = 64;

	// 移動の速さ
	static constexpr int SPEED = 5;

	// データメンバの宣言 -----------------------------------------------
private:

	// テクスチャハンドル
	int m_texture;

	// 位置
	POINT m_position;

	// 速度
	POINT m_velocity;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	Player();

	// デストラクタ
	~Player();

	// 初期化関数
	void Initialize(int texture, POINT position);

	// 更新関数
	void Update(int keyCondition, int keyTrigger, BulletManager* pBulletManager);

	// 描画関数
	void Render();

	// 位置の取得関数
	POINT GetPosition() { return m_position; }

};

