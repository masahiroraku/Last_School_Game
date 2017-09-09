#pragma once

#include<DxLib.h>
#include<array>
#include<functional>

#include"Math/Math.h"
#include"Math/Vector3/Vector3.h"
#include"Math/Vector2/Vector2.h"

#include"GamePad.h"
#include"Command.h"
#include"Axis.h"

/**
 * @file Input.h
 * @brief ���͊Ǘ��N���X��`�w�b�_�[
 * @author ���]
 * @date Unknown
 */

 /*! @class Input
 *   @brief  ���͊Ǘ��N���X
 */
class Input {
private:	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Input();	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Input();

private:
	/// <summary>
	/// �Q�[���p�̃{�^����`�ŉ����ꂽ��s��������o�^
	/// </summary>
	void RegistFunc();	
	/// <summary>
	/// �L�[�{�[�h�z��̏�����
	/// </summary>
	void InitializeKeys();
public:	
	/// <summary>
	/// Input�N���X�̎��Ԃ��擾
	/// </summary>
	/// <returns>Input�N���X�̎���</returns>
	static Input& GetInstance();
	
	/// <summary>
	/// �Q�[���p�̃{�^���������ꂽ���H
	/// </summary>
	/// <param name="command">�Q�[���p�̃{�^��</param>
	/// <returns>�����ꂽ���H</returns>
	bool GetCommand(Command command);

	/// <summary>
	/// ����(Horizontal)�E�c��(Vertical)�̓��͒l���擾�ł���
	/// </summary>
	/// <param name="axis">����(Horizontal)�E�c��(Vertical)</param>
	/// <returns>�w�肵�����̓��͒l</returns>
	float GetAxis(Axis axis);	

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// WASD�L�[ LStick�̓��͂��ꂽ�l��Ԃ�
	/// </summary>
	/// <returns>�ړ���(0.0 �` 1.0)</returns>
	Vector3 GetVelocity();

	//�L�[�{�[�h

	/// <summary>
	/// �L�[�{�[�h �̃L�[�������ꂽ���ǂ�������
	/// </summary>
	/// <param name="key">�L�[�{�[�h �̃L�[</param>
	/// <returns>
	/// �����ꂽ�ꍇ�͐^
	/// </returns>
	bool IsKeyBoardUp(int key);
	/// <summary>
	/// �L�[�{�[�h �̃L�[�������ꂽ���ǂ�������
	/// </summary>
	/// <param name="key">�L�[�{�[�h �̃L�[</param>
	/// <returns>
	/// �����ꂽ�ꍇ�͐^
	/// </returns>
	bool IsKeyBoardDown(int key);
	/// <summary>
	/// �L�[�{�[�h �̃L�[�������ꑱ���Ă���ǂ�������
	/// </summary>
	/// <param name="key">�L�[�{�[�h �̃L�[</param>
	/// <returns>
	/// �����ꑱ���Ă����ꍇ�͐^
	/// </returns>
	bool IsKeyBoardState(int key);

	//�Q�[���p�b�h

	/// <summary>
	/// �p�b�h���ڑ�����Ă��邩�Ԃ�
	/// </summary>
	/// <returns>1��ȏ�ڑ�����Ă��邩�H</returns>
	bool IsConnectGamePad();
	
	/// <summary>
	/// �Q�[���p�b�h�̃{�^���������ꂽ���H
	/// </summary>
	/// <param name="button">�Q�[���p�b�h�̃{�^��</param>
	/// <returns>
	/// �����ꂽ�ꍇ�͐^
	/// </returns>
	bool IsGamePadUp(XboxGamePad button);	
	/// <summary>
	/// �Q�[���p�b�h�̃{�^���������ꂽ���H
	/// </summary>
	/// <param name="button">�Q�[���p�b�h�̃{�^��</param>
	/// <returns>
	/// �����ꂽ�ꍇ�͐^
	/// </returns>
	bool IsGamePadDown(XboxGamePad button);	
	/// <summary>
	/// �Q�[���p�b�h�̃{�^���������ꑱ���Ă��邩�H
	/// </summary>
	/// <param name="button">�Q�[���p�b�h�̃{�^��</param>
	/// <returns>
	/// �����ꑱ���Ă���ꍇ�͐^
	/// </returns>
	bool IsGamePadState(XboxGamePad button);
	
	/// <summary>
	/// ���g���K�[�̉��������擾(0�`255)
	/// </summary>
	/// <returns>������</returns>
	unsigned char GetGamePadLeftTrigger();	
	/// <summary>
	/// �E�g���K�[�̉��������擾(0�`255)
	/// </summary>
	/// <returns>������</returns>
	unsigned char GetGamePadRightTrigger();
	
	/// <summary>
	/// ���X�e�B�b�N�̓��͒l���擾����
	/// </summary>
	/// <returns>���X�e�B�b�N�̓��͒l</returns>
	Vector2 GetGamePadLeftStick();	
	/// <summary>
	/// �E�X�e�B�b�N�̓��͒l���擾����
	/// </summary>
	/// <returns>�E�X�e�B�b�N�̓��͒l</returns>
	Vector2 GetGamePadRightStick();



	/// <summary>
	/// �Q�[���p�b�h�̐U�����J�n����
	/// </summary>
	/// <param name="player">�U������Q�[���p�b�h</param>
	/// <param name="vibrationPower">�U���̋���(0�`1000)</param>
	/// <param name="vibrationTime">�U�������鎞��(�~���b)�@-1�Ȃ��~����܂ŐU������</param>
	void VibrationStart(GamePad player, int vibrationPower, int vibrationTime = -1);	
	/// <summary>
	/// �Q�[���p�b�h�̐U�����~����
	/// </summary>
	/// <param name="player">�U�����~����Q�[���p�b�h</param>
	void VibrationStop(GamePad player);

private:
	//----RegistFunc�p�̊֐�----
	
	/// <summary>
	/// �c��(WS�L�[, LStick�̏㉺)�̓��͒l���擾����
	/// </summary>
	/// <returns>�c��(WS�L�[, LStick�̏㉺)�̓��͒l</returns>
	float GetVertical();
	/// <summary>
	/// ����(AD�L�[, LStick�̍��E)�̓��͒l���擾����
	/// </summary>
	/// <returns>����(AD�L�[, LStick�̍��E)�̓��͒l</returns>
	float GetHorizontal();
	/// <summary>
	/// �c��(�㉺�L�[, RStick�̏㉺)�̓��͒l���擾����
	/// </summary>
	/// <returns>�c��(�㉺�L�[, RStick�̏㉺)�̓��͒l</returns>
	float GetVertical2();
	/// <summary>
	/// ����(���E�L�[, RStick�̍��E)�̓��͒l���擾����
	/// </summary>
	/// <returns>����(���E�L�[, RStick�̍��E)�̓��͒l</returns>
	float GetHorizontal2();

private:	
	//!�ő�L�[��
	static const int Max_Key_Num = 256;		
	
	//!�L�[�������ꂽ�����i�[����z��
	using Keys = std::array<char, Max_Key_Num>;

	//!�L�[�̌��݂̉����󋵕ۑ�
	Keys curKeys;  
	//!�L�[��1�t���[���O�̉����󋵕ۑ�
	Keys preKeys;

	//!�Q�[���p�b�h�̌��݂̓��͏󋵂�ۑ�
	XINPUT_STATE curXinput;
	//!�Q�[���p�b�h�̂P�t���[���̓��͏󋵂�ۑ�
	XINPUT_STATE preXinput;

	//!�Q�[���p�̃{�^���������ꂽ�����i�[����z��
	using CommandFunc = std::array < std::function<bool(void)>, static_cast<int>(Command::Max_Of_Num)>;
	//!�Q�[���p�̃{�^���������ꂽ�����i�[����z��	
	CommandFunc commandFunc;

	//!�c�����̓��͐��l���i�[����z��
	using AxisFunc = std::array< std::function<float(void)>, static_cast<int>(Axis::Max_Of_Num)>;
	
	//!�c�����̓��͐��l���i�[����z��
	AxisFunc axisFunc;

	//!���͐��l�̒l
	const float VelocityValue;
};