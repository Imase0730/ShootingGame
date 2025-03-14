//--------------------------------------------------------------------------------------
// File: BulletManager.cpp
//
//--------------------------------------------------------------------------------------
#include "pch.h"
#include "BulletManager.h"

// コンストラクタ
BulletManager::BulletManager()
	: m_bulletCount{ 0 }
	, m_pBullet{ nullptr }
{
}

// デストラクタ
BulletManager::~BulletManager()
{
	// メモリを解放する
	if (m_pBullet) delete[] m_pBullet;
}

// 初期化関数
void BulletManager::Initialize(int bulletCount, int texture, Bullet::Type type)
{
	// 管理する弾の数
	m_bulletCount = bulletCount;

	// もし一度メモリが確保されていたら解放する
	if (m_pBullet) delete[] m_pBullet;

	// 弾の数分メモリを確保する
	m_pBullet = new Bullet[bulletCount];
	for (int i = 0; i < bulletCount; i++)
	{
		// 弾を初期化
		m_pBullet[i].Initialize(texture, type);
	}
}

// 更新関数
void BulletManager::Update()
{
	for (int i = 0; i < m_bulletCount; i++)
	{
		m_pBullet[i].Update();
	}
}

// 描画関数
void BulletManager::Render()
{
	for (int i = 0; i < m_bulletCount; i++)
	{
		m_pBullet[i].Render();
	}
}

// 弾を発射する関数
void BulletManager::Shot(POINT position)
{
	for (int i = 0; i < m_bulletCount; i++)
	{
		// アクティブでない弾を使用する
		if (!m_pBullet[i].IsActive())
		{
			// 弾を発射する
			m_pBullet[i].Shot(position);
			return;
		}
	}
}

// プレイヤーの弾を取得する関数
Bullet* BulletManager::GetBullet(int idx)
{
	if (idx < 0 || idx >= m_bulletCount || !m_pBullet[idx].IsActive()) return nullptr;
	return &m_pBullet[idx];
}
