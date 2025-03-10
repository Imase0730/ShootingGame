/**
 * @file   GameLibTime.h
 *
 * @brief  時間関連のヘッダファイル
 *
 * @author S.Takaki
 *
 * @date   2025/03/17
 */

// 多重インクルードの防止 =====================================================
#pragma once




// クラスの定義 ===============================================================
namespace GameLib
{
	/**
	 * @brief フレームタイマー
	 */
	class FrameTimer final
	{
		// クラス定数の宣言 --------------------------------------------
		private:
			static constexpr int ONE_SECOND = 1'000'000;    ///< 1秒 (=1,000,000μ秒)



		// データメンバの宣言 --------------------------------------------
		private:
			LONGLONG m_lastTime;          ///< 前回の計測時間
			LONGLONG m_currentTime;       ///< 現在の計測時間
			LONGLONG m_startTime;         ///< フレームレート計測開始時間
			int      m_frameCount;        ///< フレーム数
			float    m_frameDeltaTime;    ///< フレーム間の時間差[s]
			float    m_frameRate;         ///< フレームレート[fps]



		// メンバ関数の宣言 -----------------------------------------------
		/// @name コンストラクタ／デストラクタ
		/// @{
		public:
			/**
			 * @brief デフォルトコンストラクタ
			 *
			 * @param なし
			 */
			FrameTimer();


			/**
			 * @brief デストラクタ
			 */
			~FrameTimer() = default;
		/// @}


		/// @name 操作
		/// @{
		public:
			/**
			 * @brief フレームタイマーの更新処理
			 *
			 * @param なし
			 *
			 * @return なし
			 */
			void Update();
		/// @}


		/// @name 設定／取得
		/// @{
		public:
			/**
			 * @brief 直前のフレームからの経過時間の取得
			 *
			 * @param なし
			 *
			 * @return 直前のフレームからの経過時間[s]
			 */
			float GetFrameDeltaTime() const
			{
				return m_frameDeltaTime;
			}

			
			/**
			 * @brief フレームレートの取得
			 * 
			 * @param なし
			 * 
			 * @return 現在のフレームレート[fps]
			 */
			float GetFrameRate() const
			{
				return m_frameRate;
			}
		/// @}
	};

} // namespace GameLib