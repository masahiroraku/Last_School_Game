#pragma once

/**
* @file StateNull.h
* @brief nullptr����̉������Ȃ���ԃN���X
* @author ���]
* @date 2017/10/20
*/
#include"IState.h"
enum class EventMessage;

/*! @class StateNull
*   @brief nullptr����̉������Ȃ���ԃN���X
*/
class StateNull : public IState{
public:
	StateNull();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~StateNull();
	/// <summary>
	/// ��Ԃ̏�����
	/// </summary>
	virtual void Initialize() override;
	/// <summary>
	/// ��Ԃ̍X�V
	/// </summary>
	/// <param name="deltaTime">�P�t���[��</param>
	virtual void Update(float deltaTime) override;
	/// <summary>
	/// ��Ԃ̏I��
	/// </summary>
	virtual void Finalize() override;

	/// <summary>
	/// �A�N�^�[�̃��b�Z�[�W���󂯎��
	/// </summary>
	/// <param name="message">���b�Z�[�W�̎��</param>
	/// <param name="param">���b�Z�[�W�ƈꏏ�ɑ�������</param>
	virtual void HandleMessage(EventMessage message, void* param) override;
	/// <summary>
	/// ���̏�ԂɑJ�ڂ��邩�ǂ���
	/// </summary>
	/// <returns>
	/// [true:�J�ڂ��� false:�J�ڂ��Ȃ�]
	/// </returns>
	virtual bool IsEnd() const override;
	/// <summary>
	/// ���ɑJ�ڂ����Ԃ��擾����
	/// </summary>
	/// <returns>���̏��</returns>
	virtual int GetNextState() const override;
	/// <summary>
	/// ���ɍĐ�����A�j���[�V�����ԍ����擾����
	/// </summary>
	/// <returns>���ɍĐ�����A�j���[�V�����ԍ�</returns>
	virtual int GetNextAnime() const override;
};
