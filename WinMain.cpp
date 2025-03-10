/**
 * @file   WinMain.cpp
 * 
 * @brief  ゲームプログラムのエントリーポイント
 * 
 * @author S.Takaki
 * 
 * @date   2022/10/16
 */

// ヘッダファイルの読み込み ===================================================
#include "EmbeddedResources/Resource.h"
#include "Game/Game.h"
#include "Game/Screen.h"
#include "Library/MemoryLeakDetector.h"




// 関数定義 ===================================================================
/**
 * @brief プログラムのエントリーポイント
 * 
 * @param[in] hInstance     現在のインスタンスのハンドル
 * @param[in] hPrevInstance 以前のインスタンスのハンドル(常にNULL)
 * @param[in] lpCmdLine     コマンドライン
 * @param[in] nCmdShow      ウィンドウの表示状態
 * 
 * @retval  0 正常終了
 * @retval -1 異常終了
 */
int APIENTRY wWinMain(_In_     HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_     LPWSTR    lpCmdLine,
                      _In_     int       nCmdShow)
{
    // 未使用引数の警告対策
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(nCmdShow);


#if defined(_DEBUG)
    // メモリーリーク検出機構のセットアップ
    SetUpMemoryLeakDetector();
#endif


    // デバッグ情報用ログファイルの出力の抑制
    SetOutApplicationLogValidFlag(FALSE);


    // 起動モードの設定
#if defined(_DEBUG)
    ChangeWindowMode(TRUE);	           // ウインドウモードで実行
    SetMainWindowText(Game::TITLE);    // ウインドウタイトルの設定
    SetWindowIconID(IDI_ICON1);        // ウインドウアイコンの設定
#else
    ChangeWindowMode(FALSE);	      // フルスクリーンで実行
#endif


    // 初期状態の画面モードの設定
    SetGraphMode(Screen::WIDTH, Screen::HEIGHT, 32);


    // DXライブラリの初期化処理
    if (DxLib_Init() == -1)
    {
        return -1;    // エラーが起きたら直ちに終了
    }


    // 描画先を裏画面に設定
    SetDrawScreen(DX_SCREEN_BACK);


    // ゲームオブジェクトの生成
    Game game;


    // ゲームの処理
    game.Initialize();    // ゲームの初期化処理

    while (!ProcessMessage() && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        game.Update();              // ゲームの更新処理
        game.Render();              // ゲームの描画処理

        ScreenFlip();               // 裏画面の内容を表画面に反映
        ClearDrawScreen();          // 裏画面の消去
    }

    game.Finalize();      // ゲームの終了処理


    // DXライブラリの終了処理
    if (DxLib_End() == -1)
    {
        return -1;    // エラーが起きたら直ちに終了
    }


    return 0;    // 正常終了
}
