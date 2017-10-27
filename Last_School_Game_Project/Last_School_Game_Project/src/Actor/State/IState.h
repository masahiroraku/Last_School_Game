#pragma once

/**
* @file IState.h
* @brief �A�N�^�[�̏�Ԋ֐��̒��ۃN���X��`�t�@�C��
* @author ���]
* @date 2017/09/01
*/

enum class EventMessage;

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
	/// ��Ԃ̏�����
	/// </summary>
	virtual void Initialize() = 0;
	/// <summary>
	/// ��Ԃ̍X�V
	/// </summary>
	/// <param name="deltaTime">�P�t���[��</param>
	virtual void Update(float deltaTime) = 0;
	/// <summary>
	/// ��Ԃ̏I��
	/// </summary>
	virtual void Finalize() = 0;

	/// <summary>
	/// �A�N�^�[�̃��b�Z�[�W���󂯎��
	/// </summary>
	/// <param name="message">���b�Z�[�W�̎��</param>
	/// <param name="param">���b�Z�[�W�ƈꏏ�ɑ�������</param>
	virtual void HandleMessage(EventMessage message, void* param) = 0;
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
	/// <summary>
	/// ���ɍĐ�����A�j���[�V�����ԍ����擾����
	/// </summary>
	/// <returns>���ɍĐ�����A�j���[�V�����ԍ�</returns>
	virtual int GetNextAnime() const = 0;
};
