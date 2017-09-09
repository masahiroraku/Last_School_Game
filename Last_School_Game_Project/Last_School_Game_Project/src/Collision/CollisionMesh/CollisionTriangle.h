#pragma once

/**
 * @file CollisionTriangle.h
 * @brief 三次元の三角形定義ファイル
 * @author 阿曽
 * @date 2017/7/13
 */

#include"Math/Vector3/Vector3.h"
#include"Collision/BoundingSphere/BoundingSphere.h"
#include<array>
#include<DxLib.h>

/*! @class CollisionTriangle
 *   @brief  三次元の三角形
 */
class CollisionTriangle {
public:	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="p1">頂点座標</param>
	/// <param name="p2">頂点座標</param>
	/// <param name="p3">頂点座標</param>
	CollisionTriangle(const Vector3& p1, const Vector3& p2, const Vector3& p3);
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="p1">頂点座標</param>
	/// <param name="p2">頂点座標</param>
	/// <param name="p3">頂点座標</param>
	CollisionTriangle(const VECTOR& p1, const VECTOR& p2, const VECTOR& p3);	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~CollisionTriangle();	
	/// <summary>
	/// 三角形の中に座標が入っているかどうか
	/// </summary>
	/// <param name="point">座標</param>
	/// <returns>
	/// [true 中に入っている : false 中に入っていない]
	/// </returns>
	bool IsInside(const Vector3& point)const;	
	/// <summary>
	/// 球と縁のあたり判定
	/// </summary>
	/// <param name="sphere">球</param>
	/// <param name="result">接触点</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	bool Collide_Edge_And_Sphere(const BoundingSphere& sphere, Vector3* result = nullptr);
private:
	//!３頂点
	std::array<VECTOR, 3> points;
};