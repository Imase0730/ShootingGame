/**
 * @file   GameLibTime.h
 *
 * @brief  ���Ԋ֘A�̃w�b�_�t�@�C��
 *
 * @author S.Takaki
 *
 * @date   2025/03/17
 */

// ���d�C���N���[�h�̖h�~ =====================================================
#pragma once




// �N���X�̒�` ===============================================================
namespace GameLib
{
	/**
	 * @brief �t���[���^�C�}�[
	 */
	class FrameTimer final
	{
		// �N���X�萔�̐錾 --------------------------------------------
		private:
			static constexpr int ONE_SECOND = 1'000'000;    ///< 1�b (=1,000,000�ʕb)



		// �f�[�^�����o�̐錾 --------------------------------------------
		private:
			LONGLONG m_lastTime;          ///< �O��̌v������
			LONGLONG m_currentTime;       ///< ���݂̌v������
			LONGLONG m_startTime;         ///< �t���[�����[�g�v���J�n����
			int      m_frameCount;        ///< �t���[����
			float    m_frameDeltaTime;    ///< �t���[���Ԃ̎��ԍ�[s]
			float    m_frameRate;         ///< �t���[�����[�g[fps]



		// �����o�֐��̐錾 -----------------------------------------------
		/// @name �R���X�g���N�^�^�f�X�g���N�^
		/// @{
		public:
			/**
			 * @brief �f�t�H���g�R���X�g���N�^
			 *
			 * @param �Ȃ�
			 */
			FrameTimer();


			/**
			 * @brief �f�X�g���N�^
			 */
			~FrameTimer() = default;
		/// @}


		/// @name ����
		/// @{
		public:
			/**
			 * @brief �t���[���^�C�}�[�̍X�V����
			 *
			 * @param �Ȃ�
			 *
			 * @return �Ȃ�
			 */
			void Update();
		/// @}


		/// @name �ݒ�^�擾
		/// @{
		public:
			/**
			 * @brief ���O�̃t���[������̌o�ߎ��Ԃ̎擾
			 *
			 * @param �Ȃ�
			 *
			 * @return ���O�̃t���[������̌o�ߎ���[s]
			 */
			float GetFrameDeltaTime() const
			{
				return m_frameDeltaTime;
			}

			
			/**
			 * @brief �t���[�����[�g�̎擾
			 * 
			 * @param �Ȃ�
			 * 
			 * @return ���݂̃t���[�����[�g[fps]
			 */
			float GetFrameRate() const
			{
				return m_frameRate;
			}
		/// @}
	};

} // namespace GameLib