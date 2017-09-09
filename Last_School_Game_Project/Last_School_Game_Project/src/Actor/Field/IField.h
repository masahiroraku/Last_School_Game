#pragma once

class Line;
class BoundingSphere;
class Capsule;
class HitInfo;

/**
 * @file IField.h
 * @brief フィールドのインターフェース定義ファイル
 * @author 阿曽
 * @date Unknown
 */

 /*! @class IField
 *   @brief フィールドのインターフェース
 */
class IField {
public:	
	/// <summary>
	/// 仮想デストラクタ
	/// </summary>
	virtual ~IField() {}	
	/// <summary>
	/// 線分とあたり判定を行う
	/// </summary>
	/// <param name="line">線分</param>
	/// <param name="hitInfo">衝突情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	virtual bool Collision(const Line& line, HitInfo& hitInfo) = 0;
	/// <summary>
	/// 球とあたり判定を行う
	/// </summary>
	/// <param name="sphere">球</param>
	/// <param name="hitInfo">衝突情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	virtual bool Collision(const BoundingSphere& sphere, HitInfo& hitInfo) = 0;
	/// <summary>
	/// カプセルとあたり判定を行う
	/// </summary>
	/// <param name="capsule">カプセル</param>
	/// <param name="hitInfo">衝突情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	virtual bool Collision(const Capsule& capsule, HitInfo& hitInfo) = 0;
};