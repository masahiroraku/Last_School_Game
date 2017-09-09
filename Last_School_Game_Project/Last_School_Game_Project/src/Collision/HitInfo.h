#pragma once

#include"Math\Vector3\Vector3.h"
#include"Actor/Base/Actor.h"

/**
 * @file HitInfo.h
 * @brief �����蔻��̏����܂Ƃ߂��\���̒�`�t�@�C��
 * @author ���]
 * @date Unknown
 */


/*! @class HitInfo
 * @brief  �����蔻��̏����܂Ƃ߂��\����
 */
class HitInfo {
public:	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	HitInfo()
		: intersect(0, 0, 0)
		, collideActor(nullptr)
		, normal(0, 0, 0)
	{
	}
public:
	//!�ڐG�_
	Vector3 intersect;
	//!�Փ˂����A�N�^�[�̃|�C���^
	Actor* collideActor;
	//!�ڐG�����ʂ̖@��
	Vector3 normal;
};
