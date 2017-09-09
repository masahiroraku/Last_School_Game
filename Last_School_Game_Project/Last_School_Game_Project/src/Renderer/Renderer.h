#pragma once

/**
 * @file Renderer.h
 * @brief 描画関係をまとめたクラス
 * @author 阿曽
 * @date 2015/12/7
 */

#include<string>
#include"Math/Matrix4/Matrix4.h"
#include<unordered_map>
#include"Math/Vector2/Vector2.h"
#include"Utility/Rect/Rect.h"
#include"Utility/Color/Color.h"
#include"ModelInfo.h"
#include"Utility/Assets.h"

/*! @class Renderer
 *  @brief  描画クラス
 */
class Renderer {
private:
	/**
	 * @brief コンストラクタ
	 */
	Renderer();
	/**
	* @brief デストラクタ
	*/
	~Renderer();
public:	
	/**
	 * @brief Rendererのポインタを取得
	 * @return Rendererのポインタ
	 */
	static Renderer* GetInstance();
	/**
	 * @brief テクスチャを読み込む
	 * @param id 登録する名前
	 * @param fileName 読み込むファイル名
	 */
	void LoadTexture(Assets::Texture id, const std::string& fileName);	
	/**
	 * @brief フォントを読み込む
	 * @param id 登録する名前
	 * @param fileName 読み込むファイル名
	 * @param edgeSize 文字の縁の太さ
	 */
	void LoadFont(Assets::Font id, const std::string& fileName, int edgeSize = 0);
	/**
	 * @brief 3Dモデルを読み込む
	 * @param id 登録する名前
	 * @param fileName 読み込むファイル名
	 */
	void Load3DModel(Assets::Model id, const std::string& fileName);
	/**
	 * @brief アニメーションを読み込む
	 * @param id 登録する名前
	 * @param fileName 読み込むファイル名
	 */
	void LoadAnimation(Assets::Animation id, const std::string& fileName);
	/**
	 * @brief エフェクトを読み込む
	 * @param id 登録する名前
	 * @param fileName 読み込むファイル名
	 */
	void LoadEffect(Assets::Effect id, const std::string& fileName);
	/**
	 * @brief テクスチャを画面に描画
	 * @param id 登録した名前
	 * @param position 描画する座標
	 * @param center テクスチャの中心点
	 * @param scale テクスチャの大きさ
	 * @param angle テクスチャの回転角度（度数法）
	 * @param color テクスチャの色
	 */
	void DrawTexture(Assets::Texture id, const Vector2& position = Vector2(0, 0), const Vector2& center = Vector2(0, 0), const Vector2& scale = Vector2(1, 1), float angle = 0.0f, const Color& color = Color::White);
	/**
	* @brief 矩形を画面に描画
	* @param id 登録した名前
	* @param position 描画する座標
	* @param rect 切り取る範囲
	* @param alpha アルファ値
	*/
	void DrawRectangle(Assets::Texture id, const Vector2& position = Vector2(0, 0), const Rect& rect = Rect(0, 0, 1, 1), float alpha = 1.0f);
	/**
	* @brief フォントを画面に描画
	* @param id 登録した名前
	* @param text 表示する文字列
	* @param position 描画する座標
	* @param color テクスチャの色
	*/
	void DrawFont(Assets::Font id, const std::string& text, const Vector2& position, const Color& color = Color::White);
	/**
	* @brief 画像を使って数字を画面に描画する
	* @param id 登録した名前
	* @param position 座標
	* @param number 数値
	* @param width 数字１つあたりの横幅
	* @param height 数字１つあたりの縦幅
	* @param digit 桁数
	* @param fill 余った桁を何で埋めるか
	*/
	void DrawNumber(Assets::Texture id, const Vector2& position, int number, int width, int height, int digit = 0, char fill = '0');
	/**
	* @brief ビルボードを描画
	* @param id 登録した名前
	* @param position 座標
	* @param center 中心座標
	* @param scale 大きさ
	* @param angle 回転角度（度数法）
	* @param color 色
	*/
	void DrawBillboard(Assets::Texture id, const Vector3& position, const Vector2& center = Vector2::Zero, float scale = 1.0f, float angle = 0.0f, const Color& color = Color::White);	
	/**
	* @brief ビルボードを使って数字を画面に描画する
	* @param id 登録した名前
	* @param position 座標
	* @param number 中心座標
	* @param width 数字１つあたりの横幅
	* @param height 数字１つあたりの横幅
	* @param alpha アルファ値
	*/
	void DrawNumberBillboard(Assets::Texture id, const Vector3& position, int number, int width, int height, float alpha = 1.0f);	
	/**
	* @brief ３Dエフェクトを表示
	* @param id 登録した名前
	* @return 再生中のエフェクトのハンドル
	*/
	int DrawEffect3D(Assets::Effect id);
	/**
	* @brief ３Dエフェクトの座標を設定
	* @param playEffectHandle 再生中のエフェクトハンドル
	* @param position 座標
	*/
	void SetEffect3DPosition(int playEffectHandle, const Vector3& position);
	/**
	* @brief ３Dエフェクトの大きさを設定
	* @param playEffectHandle 再生中のエフェクトハンドル
	* @param scale 大きさ
	*/
	void SetEffect3DScele(int playEffectHandle, const Vector3& scale);
	/**
	* @brief ３Dエフェクトの回転角度を設定
	* @param playEffectHandle 再生中のエフェクトハンドル
	* @param x X軸角度(度数法)
	* @param y Y軸角度(度数法)
	* @param z Z軸角度(度数法)
	*/
	void SetEffect3DRotate(int playEffectHandle, float x, float y, float z);
	/**
	* @brief ３Dエフェクトの姿勢行列を設定
	* @param playEffectHandle 再生中のエフェクトハンドル
	* @param matrix 姿勢行列
	*/
	void SetEffect3DMatrix(int playEffectHandle, const Matrix4& matrix);
	/**
	* @brief ３Dモデルの姿勢行列を設定
	* @param modelHandle ３Dモデルのハンドル
	* @param matrix 姿勢行列
	*/
	void SetMatrix3DModel(int modelHandle, const Matrix4& matrix);
	/**
	* @brief ３Dモデルを描画
	* @param modelHandle ３Dモデルのハンドル
	*/
	void Draw3DModel(int modelHandle);
	/**
	* @brief ３Dモデルを描画
	* @param modelHandle ３Dモデルのハンドル
	* @param matrix 姿勢行列
	*/
	void Draw3DModel(int modelHandle, const Matrix4& matrix);	
	/**
	* @brief ３Dモデルにアニメーションをバインドする
	* @param info モデル情報
	* @param animeIndex 再生するアニメーションの番号
	* @param animeTime 再生時間
	*/
	void BindAnimation(ModelInfo& info, int animeIndex, float animeTime);
	/**
	* @brief ３Dモデルにアニメーションブレンドを適用させる（切り替えが滑らかになる）
	* @param info モデル情報
	* @param animeIndex 再生するアニメーションの番号
	* @param animeTime 再生時間
	*/
	void BindAnimationBlend(ModelInfo& info, int animeIndex, float animeTime);
	/**
	* @brief 指定したボーンから上下別々のアニメーションを適応させる
	* @param info モデル情報
	* @param animeIndex 再生するアニメーションの番号
	* @param animeTime00 片方の再生時間
	* @param animeTime01 もう片方の再生時間
	* @param boneIndex 分割するボーン
	*/
	void BindAnimationBlendToBone(ModelInfo& info, int animeIndex, float animeTime00, float animeTime01, int boneIndex);	
	/**
	* @brief アニメーションの再生時間を取得する
	* @param animationHandle アニメーションのハンドル
	* @param animeIndex アニメーションの番号
	* @return アニメーションの再生時間
	*/
	float GetAnimationTime(int animationHandle, int animeIndex);
	/**
	* @brief アニメーションのハンドルを取得
	* @param id 登録した名前
	* @return アニメーションのハンドル
	*/
	int GetAnimationHandle(Assets::Animation id);
	/**
	* @brief ３Dモデルのハンドルを取得
	* @param id 登録した名前
	* @return ３Dモデルのハンドル
	*/
	int GetModelHandle(Assets::Model id);
	/**
	* @brief 複製したモデルのハンドルを取得
	* @param id 登録した名前
	* @return 複製したモデルのハンドル
	*/
	int GetDeplicateModelHandle(Assets::Model id);
	/**
	* @brief エフェクトのハンドルを取得
	* @param id 登録した名前
	* @return エフェクトのハンドル
	*/
	int GetEffectHandle(Assets::Effect id);
	/**
	* @brief モデルを削除
	* @param modelHandle モデルのハンドル
	*/
	void DeleteModel(int modelHandle);
	/**
	* @brief ボーンのワールド座標を取得
	* @param modelHandle モデルのハンドル
	* @param boneIndex ボーン番号
	* @return ボーンのワールド座標
	*/
	Vector3 GetBonePosition(int modelHandle, int boneIndex);
	/**
	* @brief ボーンのローカル行列を取得
	* @param modelHandle モデルのハンドル
	* @param boneIndex ボーン番号
	* @return ボーンのローカル行列
	*/
	Matrix4 GetBoneLocalMatrix(int modelHandle, int boneIndex);
	/**
	* @brief ボーンのワールド行列を取得
	* @param modelHandle モデルのハンドル
	* @param boneIndex ボーン番号
	* @return ボーンのワールド行列
	*/
	Matrix4 GetBoneLocalWorldMatrix(int modelHandle, int boneIndex);
	/**
	* @brief ディフューズマップとして使用されているテクスチャ番号を取得する
	* @param modelHandle モデルのID・ハンドル
	* @param index マテリアルの番号
	* @return ディフューズマップとして使用されているテクスチャ番号
	*/
	int GetModelTextureIndex(int modelHandle, int index);
	/**
	* @brief モデルのテクスチャを変更する
	* @param modelHandle モデルのID・ハンドル
	* @param id 変更するテクスチャの名前
	* @param textureIndex ディフューズマップとして使用されているテクスチャ番号
	*/
	void ChangeModelTexture(int modelHandle, Assets::Texture id, int textureIndex);	
	/**
	 * @brief 全リソースの削除
	 */
	void Clear();
	/**
	* @brief エフェクトが再生中かどうか取得する
	* @param エフェクトのハンドル
	* @return 再生中かどうか[true 再生中: false 再生していない]
	*/
	bool IsPlayEffect3D(int effectHandle);

private:
	//!モデル情報を管理するコンテナ
	std::unordered_map<Assets::Model, int> models;
	//!アニメーションを管理するコンテナ
	std::unordered_map<Assets::Animation, int> animations;
	//!テクスチャを管理するコンテナ
	std::unordered_map<Assets::Texture, int> textures;
	//!フォントを管理するコンテナ
	std::unordered_map<Assets::Font, int> fonts;
	//!エフェクトを管理するコンテナ
	std::unordered_map<Assets::Effect, int> effects;
private:
	//!補間する時間
	static const float LerpTime;
};