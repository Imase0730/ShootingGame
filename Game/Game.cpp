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
	, m_playerTexture{}
	, m_texture{}
	, m_playerPosition { 200, 200 }
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
	// プレイヤーのテクスチャの読み込み
	m_playerTexture = LoadGraph(L"Resources/Textures/Fighter.png");

	// シューティングゲームで使用するテクスチャの読み込み
	m_texture = LoadGraph(L"Resources/Textures/ShootingGame.png");
}

// 更新処理
void Game::Update()
{
	// フレームタイマーの更新
	m_frameTimer.Update();

	// キー入力の取得
	m_oldKey = m_key;
	m_key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// 左右キーでプレイヤーを左右に移動する
	if (m_key & PAD_INPUT_LEFT)
	{
		m_playerPosition.x -= 10;
	}
	if (m_key & PAD_INPUT_RIGHT)
	{
		m_playerPosition.x += 10;
	}
}

// 描画処理
void Game::Render()
{
	// １枚絵のプレイヤーを描画
	DrawGraph(100, 100, m_playerTexture, TRUE);

	// 指定矩形を切り出して指定した矩形へプレイヤーを描画
	DrawRectExtendGraph( m_playerPosition.x, m_playerPosition.y
					   , m_playerPosition.x + PLAYER_SIZE, m_playerPosition.y + PLAYER_SIZE
					   , 0, 0, 32, 32, m_texture, TRUE );

	// FPSの描画
	DrawFormatString(10, 10, GetColor(255, 255, 255), L"%3.0ffps", m_frameTimer.GetFrameRate());
}

// 終了処理
void Game::Finalize()
{
}
