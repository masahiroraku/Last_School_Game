#pragma once

class Ray;
class Line;
class Capsule;
class BoundingSphere;
class HitInfo;

/**
 * @file Collision.h
 * @brief あたり判定の関数をまとめたクラス定義ファイル
 * @author 阿曽
 * @date Unknown
 */

/*! @class Collision
 *   @brief あたり判定の関数をまとめたクラス
 */
class Collision {
public:

	/// <summary>
	/// ステージのあたり判定を初期化する
	/// </summary>
	/// <param name="modelID">あたり判定を設定するモデルのハンドル</param>
	/// <param name="XDivNum">X軸方向の空間分割数</param>
	/// <param name="YDivNum">Y軸方向の空間分割数</param>
	/// <param name="ZDivNum">Z軸方向の空間分割数</param>
	static void SetUpOctree(unsigned int modelID, int XDivNum = 32, int YDivNum = 8, int ZDivNum = 32);	
	/// <summary>
	/// 球と球のあたり判定
	/// </summary>
	/// <param name="sphere1">球</param>
	/// <param name="sphere2">球</param>
	/// <param name="hitInfo">衝突情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	static bool BoundingShpere_BoundingSphere(const BoundingSphere& sphere1, const BoundingSphere& sphere2, HitInfo& hitInfo);	
	/// <summary>
	/// 球と線分のあたり判定
	/// </summary>
	/// <param name="sphere">球</param>
	/// <param name="line">線分</param>
	/// <param name="hitInfo">衝突情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	static bool BoundingSphere_Line(const BoundingSphere& sphere, const Line& line, HitInfo& hitInfo);
	/// <summary>
	/// 球とカプセルのあたり判定
	/// </summary>
	/// <param name="sphere">球</param>
	/// <param name="capsule">カプセル</param>
	/// <param name="hitInfo">衝突情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	static bool BoundingSphere_Capsule(const BoundingSphere& sphere, const Capsule& capsule, HitInfo& hitInfo);
	/// <summary>
	/// カプセルとカプセルのあたり判定
	/// </summary>
	/// <param name="capsule1">カプセル</param>
	/// <param name="capsule2">カプセル</param>
	/// <param name="hitInfo">衝突情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	static bool Capsule_Capsule(const Capsule& capsule1, const Capsule& capsule2, HitInfo& hitInfo);
	/// <summary>
	/// カプセルと線分のあたり判定
	/// </summary>
	/// <param name="capsule">カプセル</param>
	/// <param name="line">線分</param>
	/// <param name="hitInfo">衝突情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	static bool Capsule_Line(const Capsule& capsule, const Line& line, HitInfo& hitInfo);
	/// <summary>
	/// 線分と線分のあたり判定
	/// </summary>
	/// <param name="line1">線分</param>
	/// <param name="line2">線分</param>
	/// <param name="hitInfo">衝突情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	static bool Line_Line(const Line& line1, const Line& line2, HitInfo& hitInfo);
	/// <summary>
	/// ステージと線分のあたり判定
	/// </summary>
	/// <param name="modelID">あたり判定を行うモデルのハンドル</param>
	/// <param name="line">線分</param>
	/// <param name="hitInfo">衝突情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	static bool Octree_Line(int modelID, const Line& line, HitInfo& hitInfo);
	/// <summary>
	/// ステージと球のあたり判定
	/// </summary>
	/// <param name="modelID">あたり判定を行うモデルのハンドル</param>
	/// <param name="sphere">球</param>
	/// <param name="hitInfo">衝突情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	static bool Octree_BoundingSphere(int modelID, const BoundingSphere& sphere, HitInfo& hitInfo);
	/// <summary>
	/// ステージとカプセルのあたり判定
	/// </summary>
	/// <param name="modelID">あたり判定を行うモデルのハンドル</param>
	/// <param name="capsule">カプセル</param>
	/// <param name="hitInfo">衝突情報</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	static bool Octree_Capsule(int modelID, const Capsule& capsule, HitInfo& hitInfo);

};