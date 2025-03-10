//--------------------------------------------------------------------------------------
// File: Bullet.h
//
//--------------------------------------------------------------------------------------
#pragma once

// 弾
class Bullet
{
	// クラス定数の宣言 -------------------------------------------------
public:

	// 弾のタイプ
	enum class Type { None, Player, Enemy, TypeNum };

	// 弾の大きさ
	static constexpr int SIZE = 16;

	// 各タイプ毎の弾の速さ
	static constexpr POINT SPEED[static_cast<int>(Type::TypeNum)] =
	{
		{ 0, 0 }, { 0, -10 }, { 0, 10 }
	};

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

	// タイプ
	Type m_type;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	Bullet();

	// デストラクタ
	~Bullet();

	// 初期化関数
	void Initialize(int texture, Bullet::Type type);

	// 更新関数
	void Update();

	// 描画関数
	void Render();

	// 弾を発射する関数
	void Shot(POINT position);

	// データが有効か調べる関数
	bool IsActive() { return m_isActive; }

};

