
#pragma once

#include"Actor/Base/ActorTag.h"
#include"Math/Vector3/Vector3.h"

/**
 * @file WeaponHitInfo.h
 * @brief 攻撃のあたり判定情報を定義するファイル
 * @author 阿曽
 * @date 2017/2/26
 */

 /*! @struct WeaponHitInfo
 * @brief 攻撃のあたり判定情報
 */
struct WeaponHitInfo
{
	//!タグ
	ActorTag tag;
	//!与えるダメージ
	int damage;
	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	WeaponHitInfo()
		: tag(ActorTag::None)
		, damage(0)
	{

	}	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="tag">タグ</param>
	/// <param name="damage">与えるダメージ</param>
	WeaponHitInfo(ActorTag tag, int damage)
		: tag(tag)
		, damage(damage)
	{

	}
};