#pragma once

#include"Math/Matrix4/Matrix4.h"
#include"../Animation/Animation.h"
#include"Renderer/ModelInfo.h"
class Renderer;
#include"Utility/Assets.h"

/**
 * @file SkinningMesh.h
 * @brief アニメーションする３Dモデル定義ファイル
 * @author 阿曽
 * @date 2017/1/23
 */

/*! @class SkinningMesh
 *   @brief  アニメーションする３Dモデル
 */
class SkinningMesh {
public:	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="modelName">登録した名前</param>
	/// <param name="animationID">登録した名前</param>
	/// <param name="isDeplicate">複製するか？</param>
	SkinningMesh(Assets::Model modelID, Assets::Animation animationID, bool isDeplicate = false);	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~SkinningMesh();
	
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="dt">１秒</param>
	void Update(float dt);	

	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="renderer">描画クラス</param>
	/// <param name="world">姿勢行列（ワールド座標）</param>
	void Draw(Renderer& renderer, const Matrix4& world) const;	
	/// <summary>
	/// アニメーションを変える
	/// </summary>
	/// <param name="motion">アニメーション番号</param>
	void ChangeMotion(int motion);	
	/// <summary>
	/// ディフューズテクスチャを変える
	/// </summary>
	/// <param name="textureID">登録した名前</param>
	/// <param name="materialNumber">変更するマテリアルの番号</param>
	void ChangeTexture(Assets::Texture textureID, int materialNumber);
	
	/// <summary>
	/// モデルID・ハンドルを取得
	/// </summary>
	/// <returns>モデルID・ハンドル</returns>
	int GetModelHandle() const;

	/// <summary>
	/// アニメーションの再生が終わったか？
	/// </summary>
	/// <returns>
	/// 終了：true 再生中： false
	/// </returns>
	bool IsEndMotion() const;
	/// <summary>
	/// アニメーションタイマーを取得する
	/// </summary>
	/// <returns>再生時間</returns>
	float GetMotionTime() const;
	/// <summary>
	/// アニメーションの終了時間を取得する
	/// </summary>
	/// <returns>終了時間</returns>
	float GetMotionEndTime() const;
	
	/// <summary>
	/// モデルを削除
	/// </summary>
	void Clear();

	Vector3 GetBonePosition(int boneIndex) const;
	Matrix4 GetBoneLocalMatrix(int boneIndex) const;
	Matrix4 GetBoneWorldMatrix(int boneIndex) const;


	//-------------コピー禁止---------------
public:
	SkinningMesh(const SkinningMesh& other) = delete;
	SkinningMesh& operator = (const SkinningMesh& other) = delete;


private:
	//!複製するかどうかのフラグ
	bool isDeplicate;
	//!アニメーションクラス
	Animation animation;
	//!モデル情報
	ModelInfo modelInfo;
};