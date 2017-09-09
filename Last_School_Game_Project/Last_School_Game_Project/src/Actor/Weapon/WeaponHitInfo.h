
#pragma once

#include"Actor/Base/ActorTag.h"
#include"Math/Vector3/Vector3.h"

/**
 * @file WeaponHitInfo.h
 * @brief �U���̂����蔻������`����t�@�C��
 * @author ���]
 * @date 2017/2/26
 */

 /*! @struct WeaponHitInfo
 * @brief �U���̂����蔻����
 */
struct WeaponHitInfo
{
	//!�^�O
	ActorTag actorTag;
	//!�^����_���[�W
	int damage;
	//!�����������W
	Vector3 hitPosition;
	
	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	WeaponHitInfo()
		: actorTag(ActorTag::None)
		, damage(0)
		, hitPosition(Vector3::Zero)
	{

	}	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="actorTag">�^�O</param>
	/// <param name="damage">�^����_���[�W</param>
	/// <param name="hitPosition">�ڐG�_</param>
	WeaponHitInfo(ActorTag actorTag, int damage, const Vector3& hitPosition = Vector3::Zero)
		: actorTag(actorTag)
		, damage(damage)
		, hitPosition(hitPosition)
	{

	}
};