#pragma once

#include"Math/Vector3/Vector3.h"
#include"Collision/ShapeBase.h"

class BoundingBox : public ShapeBase {
public:
	BoundingBox();
	BoundingBox(const Vector3& min, const Vector3& max);
	/// <summary>
	/// 平行移動させる
	/// </summary>
	/// <param name="position">移動量</param>
	/// <returns>平行移動したあたり判定のポインタ</returns>
	virtual ShapePtr Translate(const Vector3& position) const override;
	/// <summary>
	/// 座標変換させる
	/// </summary>
	/// <param name="matrix">行列</param>
	/// <returns>座標変換したあたり判定のポインタ</returns>
	virtual ShapePtr Transform(const Matrix4& matrix) const	override;
	/// <summary>
	/// あたり判定の形状の種類を取得する
	/// </summary>
	/// <returns>あたり判定の形状の種類</returns>
	virtual ShapeType GetShapeType() const override;
	/// <summary>
	/// 球とあたり判定を行う
	/// </summary>
	/// <param name="shape">球</param>
	/// <param name="hitInfo">衝突情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	virtual bool Collide_BoundingSphere(const ShapeBase& shape, HitInfo& hitInfo) override;
	/// <summary>
	/// カプセルとあたり判定を行う
	/// </summary>
	/// <param name="shape">球</param>
	/// <param name="hitInfo">衝突情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	virtual bool Collide_Capsule(const ShapeBase& shape, HitInfo& hitInfo)override;
	/// <summary>
	/// 線分とあたり判定を行う
	/// </summary>
	/// <param name="shape">球</param>
	/// <param name="hitInfo">衝突情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	virtual bool Collide_Line(const ShapeBase& shape, HitInfo& hitInfo)override;
	
	virtual bool Collide_BoundingBox(const ShapeBase& shape, HitInfo& hitInfo) override;
	virtual bool Collide_OrientedBoundingBox(const ShapeBase& shape, HitInfo& hitInfo) override;

	/// <summary>
	/// あたり判定をワイヤーフレームで描画する
	/// </summary>
	virtual void Draw() const override;

public:
	// BoundingBoxからターゲットに対して一番近い座標を返す
	Vector3 ClosestPoint(const Vector3& target) const;
	// コーナーの座標を取得
	Vector3 CornerPoint(int cornerIndex) const;
	// サイズの取得
	Vector3 Size() const;
	// 中心座標の取得
	Vector3 Center() const;

public:
	Vector3 min;
	Vector3 max;

};