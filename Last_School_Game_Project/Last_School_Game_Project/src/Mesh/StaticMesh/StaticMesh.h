#pragma once

#include"Math/Matrix4/Matrix4.h"
class Renderer;
#include"Utility/Assets.h"

/**
 * @file StaticMesh.h
 * @brief 動かない３Dモデル定義ファイル
 * @author 阿曽
 * @date 2017/1/23
 */

/*! @class StaticMesh
 *   @brief  動かない３Dモデル
 */
class StaticMesh {
public:	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="modelName">登録した名前</param>
	/// <param name="world">初期姿勢行列</param>
	/// <param name="isUseZBuffer">Zソートするか？</param>
	StaticMesh(Assets::Model id, const Matrix4& world, bool isUseZBuffer = true);	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~StaticMesh();
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="dt">１秒</param>
	void Update(float dt);	
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="renderer">描画クラス</param>
	void Draw(Renderer& renderer) const;	
	/// <summary>
	///　モデルID・ハンドルを取得
	/// </summary>
	/// <returns>モデルID・ハンドル</returns>
	int GetModelHandle();

public:
	//!--------コピー禁止---------
	StaticMesh(const StaticMesh& other) = delete;
	//!--------コピー禁止---------
	StaticMesh& operator = (const StaticMesh& other) = delete;

private:
	//!モデルID・ハンドル
	int modelHandle;

};