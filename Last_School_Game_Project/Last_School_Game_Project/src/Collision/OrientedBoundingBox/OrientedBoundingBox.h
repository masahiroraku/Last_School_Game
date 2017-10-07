#pragma once

#include"Collision/ShapeBase.h"
#include"Math/Vector3/Vector3.h"
#include"Math/Matrix4/Matrix4.h"
class BoundingBox;

class OrientedBoundingBox : public ShapeBase {
public:
	OrientedBoundingBox();
	OrientedBoundingBox(const Vector3& position, const Vector3& extents, const Vector3& axis_x, const Vector3& axis_y, const Vector3& axis_z);
	explicit OrientedBoundingBox(const BoundingBox& aabb);
	/// <summary>
	/// あたり判定を行う関数
	/// </summary>
	/// <param name="shape">あたり判定用の形状</param>
	/// <param name="hitInfo">あたり判定情報</param>
	/// <returns></returns>
	bool Intersect(const ShapeBase& shape, HitInfo& hitInfo);

	/// <summary>
	/// 座標移動
	/// </summary>
	/// <param name="position">座標</param>
	/// <returns>移動した形状ポインタ</returns>
	virtual ShapePtr Translate(const Vector3& position) const = 0;
	/// <summary>
	/// 座標変換
	/// </summary>
	/// <param name="matrix">姿勢行列</param>
	/// <returns>座標変換された形状ポインタ</returns>
	virtual ShapePtr Transform(const Matrix4& matrix) const = 0;

	/// <summary>
	/// 形状の種類を取得
	/// </summary>
	/// <returns>形状の種類</returns>
	virtual ShapeType GetShapeType() const { return ShapeType::Max_Num; }

	/// <summary>
	/// 球とのあたり判定
	/// </summary>
	/// <param name="shape">球のポインタ</param>
	/// <param name="hitInfo">あたり判定情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	virtual bool Collide_BoundingSphere(const ShapeBase& shape, HitInfo& hitInfo);

	/// <summary>
	/// カプセルとのあたり判定
	/// </summary>
	/// <param name="shape">カプセルのポインタ</param>
	/// <param name="hitInfo">あたり判定の情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	virtual bool Collide_Capsule(const ShapeBase& shape, HitInfo& hitInfo);

	/// <summary>
	/// 線分とのあたり判定
	/// </summary>
	/// <param name="shape">線分のポインタ</param>
	/// <param name="hitInfo">あたり判定の情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	virtual bool Collide_Line(const ShapeBase& shape, HitInfo& hitInfo);

	virtual bool Collide_BoundingBox(const ShapeBase& shape, HitInfo& hitInfo);
	virtual bool Collide_OrientedBoundingBox(const ShapeBase& shape, HitInfo& hitInfo);
	/// <summary>
	/// 当たり判定をワイヤーフレームで描画
	/// </summary>
	virtual void Draw() const;

public:
	// OBBからターゲットに対して一番近い座標を返す
	Vector3 ClosestPoint(const Vector3& target) const;
	// ワールド座標に変換する行列を作成
	Matrix4 LocalToWorld() const;
	// ローカル座標に変換する行列を作成
	Matrix4 WorldToLocal() const;

	// コーナーの座標を取得
	Vector3 CornerPoint(int cornerIndex) const;
	// サイズを取得
	Vector3 Size() const;
	// 中心座標を取得
	Vector3 Center() const;

public:
	Vector3 position;
	Vector3 extents;
	Vector3 axis[3];
};