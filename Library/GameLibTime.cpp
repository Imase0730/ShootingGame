/**
 * @file   GameLibTime.cpp
 *
 * @brief  時間関連のソースファイル
 *
 * @author S.Takaki
 *
 * @date   2025/03/17
 */

// ヘッダファイルの読み込み ===================================================
#include "GameLibTime.h"

#include <DxLib.h>




// メンバ関数の定義 ===========================================================
namespace GameLib
{
	//*********************************************************************
	// 
	// フレームタイマー
	// 
	//*********************************************************************
	//-----------------------------------------------------------------
	// デフォルトコンストラクタ
	//-----------------------------------------------------------------
	FrameTimer::FrameTimer()
		: m_lastTime{ 0 }
		, m_currentTime{ GetNowHiPerformanceCount() }
		, m_startTime{ 0 }
		, m_frameCount{ 0 }
		, m_frameDeltaTime{ 0.0f }
		, m_frameRate{ 0.0f }
	{
	}



	//-----------------------------------------------------------------
	// 更新
	//-----------------------------------------------------------------
	void FrameTimer::Update()
	{
		// 時間の計測
		m_lastTime    = m_currentTime;
		m_currentTime = GetNowHiPerformanceCount();


		// フレームの経過時間の更新
		m_frameDeltaTime = static_cast<float>(m_currentTime - m_lastTime) / ONE_SECOND;


		// 1秒毎にフレームレートの更新
		m_frameCount++;
		if ((m_currentTime - m_startTime) > ONE_SECOND)
		{
			m_frameRate = static_cast<float>(m_frameCount * ONE_SECOND) / (m_currentTime - m_startTime);
			m_startTime = m_currentTime;
			m_frameCount = 0;
		}
	}

} // namespace GameLib
