//--------------------------------------------------------------------------------------
// File: GameplayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GameplayScene.h"
#include "Game/Game.h"
#include "Game/Screen.h"

// コンストラクタ
GameplayScene::GameplayScene(Game* pGame)
	: m_pGame{ pGame }
	, m_texture{}
{

}

// デストラクタ
GameplayScene::~GameplayScene()
{

}

// 初期化処理
void GameplayScene::Initialize()
{
	// テクスチャの読み込み
	m_texture = LoadGraph(L"Resources/Textures/ShootingGame.png");

	// プレイヤーの初期化（X座標は画面の中央へ）
	POINT position = { (Screen::WIDTH - Player::SIZE) / 2, PLAYER_POSITION_Y };
	m_player.Initialize(m_texture, position);

	// 敵のマネージャーの初期化
	m_enemyManager.Initialize(ENEMY_MAX, m_texture);

	// プレイヤーの弾のマネージャーの初期化
	m_playerBulletManager.Initialize(PLAYER_BULLET_MAX, m_texture, Bullet::Type::Player);

	// 敵の弾のマネージャーの初期化
	m_enemyBulletManager.Initialize(ENEMY_BULLET_MAX, m_texture, Bullet::Type::Enemy);
}

// 更新処理
void GameplayScene::Update(int keyCondition, int keyTrigger)
{
	// プレイヤーの更新
	m_player.Update(keyCondition, keyTrigger, &m_playerBulletManager);

	// 敵のマネージャーの更新
	m_enemyManager.Update(&m_enemyBulletManager);

	// プレイヤーの弾のマネージャーの更新
	m_playerBulletManager.Update();

	// 敵の弾のマネージャーの更新
	m_enemyBulletManager.Update();

	// プレイヤーの弾と敵の衝突判定
	HitCheck_PlayerBulletToEnemy();
	
	// 敵の弾とプレイヤーの衝突判定
	HitCheck_EnemyBulletToPlayer();
}

// 描画処理
void GameplayScene::Render()
{
	// プレイヤーの描画
	m_player.Render();

	// 敵の描画
	m_enemyManager.Render();

	// プレイヤーの弾の描画
	m_playerBulletManager.Render();

	// 敵の弾の描画
	m_enemyBulletManager.Render();

	DrawFormatString(10, 30, GetColor(255, 255, 255), L"ゲームプレイシーン");
}

// 終了処理
void GameplayScene::Finalize()
{
	// テクスチャデータをメモリから削除
	DeleteGraph(m_texture);
}

// AABBの衝突判定関数
bool GameplayScene::IsHit(RECT a, RECT b)
{
	if ( (a.left < b.right && b.left < a.right)
	  && (a.top < b.bottom && b.top < a.bottom)
	   )
	{
		return true;
	}
	return false;
}

// プレイヤーの弾と敵の衝突判定
void GameplayScene::HitCheck_PlayerBulletToEnemy()
{
	// プレイヤーの弾と敵の衝突判定
	for (int j = 0; j < m_playerBulletManager.GetBulletCount(); j++)
	{
		// プレイヤーの弾が有効なら
		Bullet* pBullet = m_playerBulletManager.GetBullet(j);
		if (pBullet)
		{
			for (int i = 0; i < m_enemyManager.GetEnemyCount(); i++)
			{
				// 敵が有効なら
				Enemy* pEnemy = m_enemyManager.GetEnemy(i);
				if (pEnemy)
				{
					// 衝突していたら
					if (IsHit(pBullet->GetCollider(), pEnemy->GetCollider()))
					{
						// 衝突時の関数を呼び出す
						pBullet->OnHit();
						pEnemy->OnHit();
					}
				}
			}
		}
	}
}

// 敵の弾とプレイヤーの衝突判定
void GameplayScene::HitCheck_EnemyBulletToPlayer()
{
	// 敵の弾とプレイヤーの衝突判定
	if (m_player.IsActive())
	{
		for (int i = 0; i < m_enemyBulletManager.GetBulletCount(); i++)
		{
			// 敵の弾が有効なら
			Bullet* pBullet = m_enemyBulletManager.GetBullet(i);
			if (pBullet)
			{
				// 衝突していたら
				if (IsHit(m_player.GetCollider(), pBullet->GetCollider()))
				{
					// 衝突時の関数を呼び出す
					m_player.OnHit();
					pBullet->OnHit();
					m_pGame->RequestSceneChange(Game::SceneID::TITLE);
				}
			}
		}
	}
}
