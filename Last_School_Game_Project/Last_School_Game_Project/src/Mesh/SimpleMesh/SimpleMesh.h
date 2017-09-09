#pragma once

#include"Math/Matrix4/Matrix4.h"
class Renderer;
#include"Utility/Assets.h"

/**
 * @file SimpleMesh.h
 * @brief アニメーションしない３Dモデル定義ファイル
 * @author 阿曽
 * @date 2017/1/31
 */


 /*! @class SimpleMesh
 *   @brief アニメーションしない３Dモデル
 */
class SimpleMesh {
public:	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="modelName">登録した名前</param>
	/// <param name="isUseZBuffer">Zソートするかどうか？</param>
	SimpleMesh(Assets::Model id, bool isUseZBuffer = true);	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~SimpleMesh();
	
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
	/// モデルID・ハンドルを取得
	/// </summary>
	/// <returns>モデルID・ハンドル</returns>
	int GetModelHandle();
	/// <summary>
	/// ディフューズテクスチャを変える
	/// </summary>
	/// <param name="textureID">登録した名前</param>
	/// <param name="materialNumber">変更するマテリアルの番号</param>
	void ChangeTexture(Assets::Texture textureID, int materialNumber);


	//------------コピー禁止---------------
public:
	SimpleMesh(const SimpleMesh& other) = delete;
	SimpleMesh& operator = (const SimpleMesh& other) = delete;

private:
	//!モデルID・ハンドル
	int modelHandle;

};