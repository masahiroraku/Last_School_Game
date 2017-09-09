
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
	ActorTag actorTag;
	//!与えるダメージ
	int damage;
	//!当たった座標
	Vector3 hitPosition;
	
	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	WeaponHitInfo()
		: actorTag(ActorTag::None)
		, damage(0)
		, hitPosition(Vector3::Zero)
	{

	}	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="actorTag">タグ</param>
	/// <param name="damage">与えるダメージ</param>
	/// <param name="hitPosition">接触点</param>
	WeaponHitInfo(ActorTag actorTag, int damage, const Vector3& hitPosition = Vector3::Zero)
		: actorTag(actorTag)
		, damage(damage)
		, hitPosition(hitPosition)
	{

	}
};