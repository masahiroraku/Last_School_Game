
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
	ActorTag tag;
	//!�^����_���[�W
	int damage;
	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	WeaponHitInfo()
		: tag(ActorTag::None)
		, damage(0)
	{

	}	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="tag">�^�O</param>
	/// <param name="damage">�^����_���[�W</param>
	WeaponHitInfo(ActorTag tag, int damage)
		: tag(tag)
		, damage(damage)
	{

	}
};