#pragma once

/**
* @file IState.h
* @brief �A�N�^�[�̏�Ԋ֐��̒��ۃN���X��`�t�@�C��
* @author ���]
* @date 2017/09/01
*/

/*! @class IState
*   @brief �A�N�^�[�̏�Ԋ֐��̒��ۃN���X
*/
class IState {
public:	
	/// <summary>
	/// ���z�f�X�g���N�^
	/// </summary>
	virtual ~IState() {}	
	/// <summary>
	/// ��Ԃ̍X�V
	/// </summary>
	/// <param name="deltaTime">�P�t���[��</param>
	virtual void Update(float deltaTime) = 0;	
	/// <summary>
	/// ���̏�ԂɑJ�ڂ��邩�ǂ���
	/// </summary>
	/// <returns>
	/// [true:�J�ڂ��� false:�J�ڂ��Ȃ�]
	/// </returns>
	virtual bool IsEnd() const = 0;	
	/// <summary>
	/// ���ɑJ�ڂ����Ԃ��擾����
	/// </summary>
	/// <returns>���̏��</returns>
	virtual int GetNextState() const = 0;
};
