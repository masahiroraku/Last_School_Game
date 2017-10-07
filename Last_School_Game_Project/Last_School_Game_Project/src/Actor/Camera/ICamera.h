#pragma once

class Matrix4;
class Actor;
class Vector3;

#include<list>
#include"Actor/Base/ActorPtr.h"
enum class ActorGroup;

/************************************************************
* File Name	: ICamera.h
* Description	: �J�����̃C���^�[�t�F�[�X
*																Date		:	Unknown.
*															  Author	:	���]
*************************************************************/
class ICamera {
public:	
	/// <summary>
	///�@���z�f�X�g���N�^
	/// </summary>
	virtual ~ICamera() {}
	
	/// <summary>
	/// �J�����̎p���s����擾
	/// </summary>
	/// <returns>�J�����̎p���s��</returns>
	virtual Matrix4 GetMatrix() = 0;	
	/// <summary>
	/// ���ڂ���A�N�^�[��ݒ�
	/// </summary>
	/// <param name="target">���ڂ���A�N�^�[</param>
	virtual void SetTarget(const Actor& target) = 0;	
	/// <summary>
	/// �w�肵�����W���J�����ɉf���Ă��邩�ǂ����擾����
	/// </summary>
	/// <param name="position">�f���Ă��邩�m�肽�����W</param>
	/// <returns>
	/// �f���Ă���ꍇ�͐^
	/// </returns>
	virtual bool IsInsideCameraView(const Vector3& position) const = 0;
	
	/// <summary>
	/// �J�����ɉf���Ă���A�N�^�[�����������X�g���擾����
	/// </summary>
	/// <param name="group">�擾�������A�N�^�[</param>
	/// <returns>
	/// �J�����ɉf���Ă���A�N�^�[�����������X�g
	/// </returns>
	virtual std::list<ActorPtr> IsInsideCameraViewActors(ActorGroup group) const = 0;


};