#pragma once

class Matrix4;
class Actor;
class Vector3;

#include<list>
#include"Actor/Base/ActorPtr.h"
enum class ActorGroup;

/************************************************************
* File Name	: ICamera.h
* Description	: カメラのインターフェース
*																Date		:	Unknown.
*															  Author	:	阿曽
*************************************************************/
class ICamera {
public:	
	/// <summary>
	///　仮想デストラクタ
	/// </summary>
	virtual ~ICamera() {}
	
	/// <summary>
	/// カメラの姿勢行列を取得
	/// </summary>
	/// <returns>カメラの姿勢行列</returns>
	virtual Matrix4 GetMatrix() = 0;	
	/// <summary>
	/// 注目するアクターを設定
	/// </summary>
	/// <param name="target">注目するアクター</param>
	virtual void SetTarget(const Actor& target) = 0;	
	/// <summary>
	/// 指定した座標がカメラに映っているかどうか取得する
	/// </summary>
	/// <param name="position">映っているか知りたい座標</param>
	/// <returns>
	/// 映っている場合は真
	/// </returns>
	virtual bool IsInsideCameraView(const Vector3& position) const = 0;
	
	/// <summary>
	/// カメラに映っているアクターが入ったリストを取得する
	/// </summary>
	/// <param name="group">取得したいアクター</param>
	/// <returns>
	/// カメラに映っているアクターが入ったリスト
	/// </returns>
	virtual std::list<ActorPtr> IsInsideCameraViewActors(ActorGroup group) const = 0;


};