#pragma once

/**
 * @file IWorld.h
 * @brief �A�N�^�[�����L����C���^�[�t�F�[�X�N���X
 * @author ���]
 * @date 2015/09/12
 */

#include "Actor/Base/ActorPtr.h"
#include<string>

enum class ActorGroup;
class ICamera;
class IField;
enum class EventMessage;

/*! @class IWorld
*	@brief  �A�N�^�[�����L����C���^�[�t�F�[�X�N���X
*/
class IWorld {
public:		
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~IWorld() {}
	/// <summary>
	/// �A�N�^�[��ǉ�����
	/// </summary>
	/// <param name="group">�ǉ�����O���[�v</param>
	/// <param name="actor">�ǉ�����A�N�^�[�|�C���^</param>
	virtual void AddActor(ActorGroup group, const ActorPtr& actor) = 0;
	/// <summary>
	/// �A�N�^�[����������
	/// </summary>
	/// <param name="name">��������A�N�^�[�̖��O</param>
	/// <returns>[true ActorPtr] : [false nullptr]</returns>
	virtual ActorPtr FindActor(const std::string& name) = 0;
	/// <summary>
	/// �A�N�^�[����������
	/// </summary>
	/// <param name="group">��������A�N�^�[�̃O���[�v</param>
	/// <param name="name">��������A�N�^�[�̖��O</param>
	/// <returns>[true ActorPtr] : [false nullptr]</returns>
	virtual ActorPtr FindActor(ActorGroup group, const std::string& name) = 0;
	/// <summary>
	/// �O���[�v�̐e�̃|�C���^���擾����
	/// </summary>
	/// <param name="group">�A�N�^�[�̃O���[�v</param>
	/// <returns>[true ActorPtr] : [false nullptr]</returns>
	virtual ActorPtr GetRoot(ActorGroup group) = 0;
	/// <summary>
	/// �J�����̃|�C���^���擾
	/// </summary>
	/// <returns>�J�����̃|�C���^</returns>
	virtual ICamera& GetCamera() = 0;
	/// <summary>
	/// �X�e�[�W�̃|�C���^���擾
	/// </summary>
	/// <returns>�X�e�[�W�̃|�C���^</returns>
	virtual IField& GetField() const = 0;
	/// <summary>
	/// �S�A�N�^�[�ɃC�x���g���b�Z�[�W�𑗐M
	/// </summary>
	/// <param name="message">�o�^�����C�x���g���b�Z�[�W</param>
	/// <param name="param">�C�x���g�ƈꏏ�ɑ���ϐ�</param>
	virtual void SendEventMessage(EventMessage message, void* param = nullptr) = 0;
};
