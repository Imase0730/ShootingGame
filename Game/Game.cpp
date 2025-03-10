﻿//--------------------------------------------------------------------------------------
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

	// プレイヤーの初期化
	POINT position{ 200, 200 };
	m_player.Initialize(m_texture, position);
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
	m_player.Update(m_key, m_oldKey);
}

// 描画処理
void Game::Render()
{
	// プレイヤーの描画
	m_player.Render();

	// FPSの描画
	DrawFormatString(10, 10, GetColor(255, 255, 255), L"%3.0ffps", m_frameTimer.GetFrameRate());
}

// 終了処理
void Game::Finalize()
{
}
