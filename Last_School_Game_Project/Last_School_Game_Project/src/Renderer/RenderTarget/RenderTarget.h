#pragma once

#include<DxLib.h>

/**
 * @file RenderTarget.h
 * @brief レンダーターゲット定義ファイル
 * @author 阿曽
 * @date 2017/6/22
 */

/*! @class RenderTarget
*   @brief  レンダーターゲット
*/
class RenderTarget {
public:		
	/// <summary>
	/// コンストラクタ<see cref="RenderTarget"/>
	/// </summary>
	/// <param name="width">設定するスクリーンの横幅</param>
	/// <param name="height">設定するスクリーンの縦幅</param>
	/// <param name="hdr">HDR画像にするかどうかの設定</param>
	/// <param name="z_buffer">Zバッファを使用するか</param>
	/// <param name="bit_depth">ビットの深さ</param>
	/// <param name="channel">チャンネル数</param>
	RenderTarget(int width, int height, bool hdr = false, bool z_buffer = true, int bit_depth = 32, int channel = 4);	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~RenderTarget();	
	/// <summary>
	/// 開始
	/// </summary>
	void Begin();	
	/// <summary>
	/// 終了
	/// </summary>
	void End();	
	/// <summary>
	/// 描画
	/// </summary>
	void Draw() const;	
	/// <summary>
	/// 設定した画像の横幅を取得
	/// </summary>
	/// <returns>設定した画像の横幅を取得</returns>
	int Width()const;	
	/// <summary>
	/// 設定した画像の縦幅を取得
	/// </summary>
	/// <returns>設定した画像の縦幅を取得</returns>
	int Height() const;	
	/// <summary>
	/// 生成したテクスチャのハンドルを取得
	/// </summary>
	/// <returns>生成したテクスチャのハンドル</returns>
	int Texture() const;
private:
	//!設定した画像の横幅
	int width;
	//!設定した画像の縦幅
	int height;
	//!テクスチャのハンドル
	int texture;
	//!テクスチャを貼るポリゴン
	VERTEX2DSHADER vertices[4];
	//!１フレーム前のスクリーン画面
	int preview_draw_screen;
};