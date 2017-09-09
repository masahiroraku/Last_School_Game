#pragma once

/**
 * @file ModelInfo.h
 * @brief ���f�������܂Ƃ߂��\���̂̒�`�t�@�C��
 * @author ���]
 * @date Unknown
 */

/*! @struct ModelInfo
 *	@brief ���f�������܂Ƃ߂��\����
 */
struct ModelInfo {
	//!�`�悷�郂�f����ID
	int modelID;
	//!�A�j���[�V����ID
	int animeID;
	//!�O��̃A�j���[�V����ID
	int previousAnimeID;
	//!���Đ����Ă���A�j���[�V�����ԍ�
	int nowPlayAnimeIndex;
	//!�O��Đ����Ă����A�j���[�V�����ԍ�
	int previousPlayAnimeIndex;
	//!��ԃA�j���[�V��������
	float lerpTime;
	//!�A�j���[�V�����̎Q�ƌ��̃��f��ID
	int sourceAnimeModelID;
	/**
	 * @brief �R���X�g���N�^
	 */
	ModelInfo() {
		Initialize();
	}	
	/**
	 * @brief ������
	 */
	void Initialize() {
		modelID = -1;
		animeID = -1;
		previousAnimeID = -1;
		nowPlayAnimeIndex = -1;
		previousPlayAnimeIndex = -1;
		lerpTime = 0.0f;
		sourceAnimeModelID = -1;
	}	
};
