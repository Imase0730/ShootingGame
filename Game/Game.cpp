//--------------------------------------------------------------------------------------
// File: Game.cpp
//
//--------------------------------------------------------------------------------------
#include "Game.h"
#include "Game/Screen.h"

// コンストラクタ
Game::Game()
	: m_frameTimer{}
	, m_key{}
	, m_oldKey{}
	, m_texture{}
	, m_player{}
	, m_enemyManager{}
	, m_playerBulletManager{}
	, m_enemyBulletManager{}
{
	// 乱数の初期値を設定
	SRand(static_cast<int>(time(NULL)));
}

// デストラクタ
Game::~Game()
{
}

// 初期化処理
void Game::Initialize()
{
	// シューティングゲームで使用するテクスチャの読み込み
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
void Game::Update()
{
	// フレームタイマーの更新
	m_frameTimer.Update();

	// キー入力の取得
	m_oldKey = m_key;
	m_key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// プレイヤーの更新
	m_player.Update(m_key, ~m_oldKey & m_key, &m_playerBulletManager);

	// 敵の更新
	m_enemyManager.Update(&m_enemyBulletManager);

	// プレイヤーの弾の更新
	m_playerBulletManager.Update();

	// 敵の弾の更新
	m_enemyBulletManager.Update();

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
				}
			}
		}
	}

}

// 描画処理
void Game::Render()
{
	// プレイヤーの描画
	m_player.Render();

	// 敵の描画
	m_enemyManager.Render();

	// プレイヤーの弾の描画
	m_playerBulletManager.Render();

	// 敵の弾の描画
	m_enemyBulletManager.Render();

	// FPSの描画
	DrawFormatString(10, 10, GetColor(255, 255, 255), L"%3.0ffps", m_frameTimer.GetFrameRate());
}

// 終了処理
void Game::Finalize()
{
}

// AABBの衝突判定関数
bool Game::IsHit(RECT a, RECT b)
{
	if ( (a.left < b.right && b.left < a.right)
	  && (a.top < b.bottom && b.top < a.bottom)
	   )
	{
		return true;
	}
	return false;
}
