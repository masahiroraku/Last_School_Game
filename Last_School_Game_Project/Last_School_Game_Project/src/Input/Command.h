#pragma once

/************************************************************
* File Name	: Command.h
* Description	: ���͂̃Q�[���p�̃{�^����`�w�b�_�[
*																Date		:	Unknown.
*															  Author	:	���]
*************************************************************/

/**
 * @file Command.h
 * @brief ���͂̃Q�[���p�̃{�^����`�w�b�_�[
 * @author ���]
 * @date Unknown
 */

 /**
  * @enum Command
  * �Q�[���p�̃{�^��
  */
enum class Command {
	//!�Q�[�������
	ShutDown,
	//!��U��
	Attack_Light,
	//!���U��
	Attack_High,
	//!����
	Dash,
	//!�K�[�h
	Guard,
	//!�ً}���
	QuickRoll,
	//!�ߋ����K�E�Z
	NearAttack,
	//!�������K�E�Z
	FarAttack,
	//!�h���C���E�z�����
	Drain,
	//!�J�������Z�b�g
	Camera_RockOn,
	//!���ڌ���{�^���@���j���[�Ƃ��Ɏg��
	Decide,
	//!�|�[�Y�{�^���@�Q�[�����C���Ŏg��
	Pause,
	//!�ő�R�}���h��
	Max_Of_Num
};
