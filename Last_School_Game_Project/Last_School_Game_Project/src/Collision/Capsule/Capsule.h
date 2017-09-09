#pragma once

#include"Math/Vector3/Vector3.h"
#include"Math/Matrix4/Matrix4.h"
#include"Collision/ShapeBase.h"

/**
 * @file Capsule.h
 * @brief あたり判定のカプセル定義ファイル
 * @author 阿曽
 * @date Unknown
 */

/*! @class Capsule
 *  @brief あたり判定のカプセル
 */
class Capsule : public ShapeBase {
public:	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="p1">始点</param>
	/// <param name="p2">終点</param>
	/// <param name="radius">半径</param>
	Capsule(const Vector3& p1, const Vector3& p2, float radius);	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Capsule();
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
	/// <summary>
	/// あたり判定をワイヤーフレームで描画する
	/// </summary>
	virtual void Draw() const override;

public:
	//!始点
	Vector3 p1;
	//!終点
	Vector3 p2;
	//!始点と終点のベクトル
	Vector3 vector;
	//!半径
	float radius;
};