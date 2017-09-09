#pragma once

/**
 * @file CollisionMesh.h
 * @brief あたり判定をおこなうメッシュファイル
 * @author 阿曽
 * @date 2017/7/13
 */

#include"Math/Vector3/Vector3.h"
#include"Collision/Line/Line.h"
#include"Collision/BoundingSphere/BoundingSphere.h"

/*! @class　CollisionMesh 
 *  @brief  あたり判定をおこなうメッシュ
 */
class CollisionMesh {
public:	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="modelHandle">あたり判定を行うモデルのハンドル</param>
	CollisionMesh(int modelHandle);	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~CollisionMesh();	
	/// <summary>
	/// 線分とあたり判定を行う
	/// </summary>
	/// <param name="line">線分</param>
	/// <param name="point">接触点</param>
	/// <param name="normal">法線ベクトル</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	bool Collide_Line(const Line& line, Vector3* point = nullptr, Vector3* normal = nullptr)const;	
	/// <summary>
	/// 球とあたり判定を行う
	/// </summary>
	/// <param name="sphere">球</param>
	/// <param name="result">接触点</param>
	/// <returns>[true 衝突した: false 衝突していない]</returns>
	bool Collide_Sphere(const BoundingSphere& sphere, Vector3* result = nullptr) const;

private:
	//!あたり判定を行うモデルのハンドル
	int modelHandle;
};