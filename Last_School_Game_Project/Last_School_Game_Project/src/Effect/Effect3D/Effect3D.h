#pragma once

#include"Math/Matrix4/Matrix4.h"
class Renderer;
#include<string>
#include"Utility/Timer/Timer.h"
#include"Utility/Assets.h"
#include"Actor/Base/Actor.h"

/**
 * @file Effect3D.h
 * @brief ３Dエフェクト定義ファイル
 * @author 阿曽
 * @date 2017/1/23
 */


 /*! @class Effect3D
 *   @brief  3Dエフェクト
 */
class Effect3D : public Actor {
public:		
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="world">world</param>
	/// <param name="id">登録した名前</param>
	/// <param name="matrix">姿勢行列</param>
	/// <param name="isPlayOnce">1回のみの再生かどうか</param>
	Effect3D(IWorld& world, Assets::Effect id, const Matrix4& matrix, bool isPlayOnce = false);	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Effect3D();

public:	
	/// <summary>
	/// 再生中かどうか
	/// </summary>
	/// <returns>
	/// [true 再生中: false 再生していない]
	/// </returns>
	bool IsPlay() const;
	
private:	
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="deltaTime">1秒</param>
	virtual void OnUpdate(float deltaTime) override;	
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="renderer">描画クラス</param>
	virtual void OnDraw(Renderer& renderer) override;	
	/// <summary>
	/// 衝突検知
	/// </summary>
	/// <param name="hitInfo">衝突情報</param>
	virtual void OnCollide(const HitInfo& hitInfo) override;	
	/// <summary>
	/// イベントメッセージを受け取る
	/// </summary>
	/// <param name="message">イベントメッセージ</param>
	/// <param name="param">イベントメッセージと一緒に送られる変数</param>
	virtual void OnMessage(EventMessage message, void* param = nullptr) override;



private:
	//!登録したエフェクト
	Assets::Effect id;
	//!１回だけ再生するか判定フラグ
	bool isPlayOnce;
	//!再生中のエフェクトのID・ハンドル
	int playHandle;
	//!再生中かどうかのフラグ
	bool isPlay;

};