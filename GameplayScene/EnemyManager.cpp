//--------------------------------------------------------------------------------------
// File: EnemyManager.cpp
//
//--------------------------------------------------------------------------------------
#include "pch.h"
#include "EnemyManager.h"
#include "Game/Screen.h"

// コンストラクタ
EnemyManager::EnemyManager()
	: m_enemyCount{ 0 }
	, m_pEnemy{ nullptr }
	, m_spawnCounter{ 0 }
{
}

// デストラクタ
EnemyManager::~EnemyManager()
{
	// メモリを解放する
	if (m_pEnemy) delete[] m_pEnemy;
}

// 初期化関数
void EnemyManager::Initialize(int enemyCount, int texture)
{
	// 管理する敵の数
	m_enemyCount = enemyCount;

	// もし一度メモリが確保されていたら解放する
	if (m_pEnemy) delete[] m_pEnemy;

	// 敵の数分メモリを確保する
	m_pEnemy = new Enemy[enemyCount];
	for (int i = 0; i < enemyCount; i++)
	{
		// 敵を初期化
		m_pEnemy[i].Initialize(texture);
	}
}

// 更新関数
void EnemyManager::Update(BulletManager* pBulletManager)
{
	for (int i = 0; i < m_enemyCount; i++)
	{
		m_pEnemy[i].Update(pBulletManager);
	}

	// 敵の出現用カウンターの加算
	m_spawnCounter++;

	// 一定の間隔で敵を出現させる
	if (m_spawnCounter > SPAWN_INTERVAL)
	{
		m_spawnCounter = 0;
		// ランダムな位置に画面上部に敵を出現させる
		POINT pos = { GetRand(Screen::WIDTH - Enemy::SIZE), -Enemy::SIZE };
		AppearEnemy(pos);
	}
}

// 描画関数
void EnemyManager::Render()
{
	for (int i = 0; i < m_enemyCount; i++)
	{
		m_pEnemy[i].Render();
	}
}

// 敵を出現させる関数
void EnemyManager::AppearEnemy(POINT position)
{
	for (int i = 0; i < m_enemyCount; i++)
	{
		// アクティブでない敵を使用する
		if (!m_pEnemy[i].IsActive())
		{
			// 敵を出現させる
			m_pEnemy[i].Appear(position);
			return;
		}
	}
}

// 敵を取得する関数
Enemy* EnemyManager::GetEnemy(int idx)
{
	if (idx < 0 || idx >= m_enemyCount || !m_pEnemy[idx].IsActive()) return nullptr;
	return &m_pEnemy[idx];
}

