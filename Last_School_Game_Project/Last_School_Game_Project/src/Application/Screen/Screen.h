#pragma once

/**
 * @file Screen.h
 * @brief �X�N���[��(�E�B���h�E)�̒�`�t�@�C��
 * @author ���]
 * @date Unknown
 */


 /*! @class Screen
 *   @brief �X�N���[��(�E�B���h�E)�̐ݒ�
 */
class Screen {
public:
	//!�E�B���h�E�̉���
	static const float Width;
	//!�E�B���h�E�̏c��
	static const float Height;
	//!�E�B���h�E�̃A�X�y�N�g��
	static const float Aspect;
	//!�E�B���h�E���t���X�N���[���ɂ��邩�H
	static const bool IsWindowMode;
	//!�E�B���h�E�̖��O
	static const char* Name;
};