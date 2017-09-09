#pragma once

/**
 * @file Assets.h
 * @brief �Q�[�����Ŏg�p����A�Z�b�g�̒�`�t�@�C��
 * @author ���]
 * @date 2017/2/23
 */

 //! Assets�̖��O���
namespace Assets {
	/**
	 * @enum Model
	 * �g�p���郂�f���̒�`
	 */	
	enum class Model {
		//!�v���C���[
		Player,
		//!�{�X
		Boss,
		//!�X�e�[�W
		Stage,
		//!�����蔻��p�̃X�e�[�W
		CollisionStage,
	};
	/**
	* @enum Animation
	* �g�p����A�j���[�V�����̒�`
	*/
	enum class Animation {
		//!�v���C���[�̃A�j���[�V����
		Player,
		//�{�X�̃A�j���[�V����
		Boss
	};
	/**
	* @enum Texture
	* �g�p����e�N�X�`���̒�`
	*/
	enum class Texture {
		//!�t�F�[�h�p
		Fade,
		//!�{�X���f���̃e�N�X�`��
		BossTexture,
		//!�Q�[�����C���Ŏg��UI�@�F�@���b�N�I��
		GameMainUI_RockOn,
	};
	/**
	 * @enum Font
	 * �g�p����t�H���g�̒�`
	 */
	enum class Font {
		//!�f�t�H���g�̃t�H���g�@MS�@�S�V�b�N
		Default
	};
	/**
	* @enum Font
	* �g�p����G�t�F�N�g�̒�`
	*/
	enum class Effect {
	};
	/**
	 * @enum Sound
	 * �g�p���鉹�y�̒�` BGM & SE
	 */
	enum class Sound {
	};
}