#pragma once

#include<string>
#include"Application\FPS\FPS.h"

/************************************************************
* File Name	: GameApplication.h
* Description	: �Q�[���t���[�����[�N�̃x�[�X�N���X
*																Date		:	Unknown
*															  Author	:	���]
*************************************************************/

/**
 * @file GameApplication.h
 * @brief �Q�[���t���[�����[�N�̃x�[�X�N���X��`�t�@�C��
 * @author ���]
 * @date Unknown
 */

 /*! @class GameApplication
 *   @brief  �Q�[���t���[�����[�N�̃x�[�X�N���X
 */
class GameApplication {
public:	
	/// <summary>
	/// �Q�[�������s
	/// </summary>
	/// <returns>[0 ����I��: -1 �N�����s]</returns>
	int Run();	
	/// <summary>
	/// �E�B���h�E���V���b�g�_�E������
	/// </summary>
	static void ShutDown();

protected:	
	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	GameApplication();
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="width">�E�B���h�E�̉���</param>
	/// <param name="height">�E�B���h�E�̏c��</param>
	/// <param name="name">�E�B���h�E�̖��O</param>
	/// <param name="isWindowMode">�t���X�N���[���ɂ��邩�ǂ���</param>
	GameApplication(int width, int height, const std::string& name, bool isWindowMode = true);	
	/// <summary>
	/// ���z�f�X�g���N�^
	/// </summary>
	virtual ~GameApplication();	
	/// <summary>
	/// ������
	/// </summary>
	virtual void Initialize() {};	
	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name="deltaTime">1�b</param>
	virtual void Update(float deltaTime) { static_cast<void>(deltaTime); };	
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw() {};	
	/// <summary>
	/// �I��
	/// </summary>
	virtual void Finalize() {};

private:
	/// <summary>
	/// DXLIB�̏�����	
	/// </summary>
	/// <returns>[true ����������: false ���������s]</returns>
	bool DxLibInit();	
	/// <summary>
	/// DXLIB�̏I��	
	/// </summary>
	void DxLibEnd();
	/// <summary>
	/// �E�B���h�E����邩�ǂ����H	
	/// </summary>
	/// <returns>
	/// [true ����: false �܂����Ȃ�]
	/// </returns>
	bool IsShutDown();

private:
	GameApplication(const GameApplication&) = delete;
	GameApplication& operator = (const GameApplication&) = delete;

private:
	//!�Q�[����FPS���Ǘ�����N���X
	FPS fps;
	//!�V���b�g�_�E�����邩�ǂ���
	static bool isShutDown;
};