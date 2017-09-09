#pragma once

#include"Math\Vector3\Vector3.h"
#include"Actor/Base/Actor.h"

/**
 * @file HitInfo.h
 * @brief あたり判定の情報をまとめた構造体定義ファイル
 * @author 阿曽
 * @date Unknown
 */


/*! @class HitInfo
 * @brief  あたり判定の情報をまとめた構造体
 */
class HitInfo {
public:	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	HitInfo()
		: intersect(0, 0, 0)
		, collideActor(nullptr)
		, normal(0, 0, 0)
	{
	}
public:
	//!接触点
	Vector3 intersect;
	//!衝突したアクターのポインタ
	Actor* collideActor;
	//!接触した面の法線
	Vector3 normal;
};
