#pragma once

#include"Mesh/SimpleMesh/SimpleMesh.h"
#include"CameraBase.h"
#include"Actor/Base/ActorPtr.h"
#include"Actor/Status/HitPoint/HitPoint.h"
#include"Utility/Timer/Timer.h"
#include "Collision/ShapePtr.h"
#include"Collision/BoundingSphere/BoundingSphere.h"

/************************************************************
* File Name	: Camera.h
* Description	: 3D空間を映すカメラ
*																Date		:	Unknown.
*															  Author	:	阿曽
*************************************************************/
class Camera : public CameraBase {
public:	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="world">world</param>
	explicit Camera(IWorld& world);
	~Camera();

	virtual void OnUpdate(float deltaTime) override;
	virtual void OnDraw(Renderer& renderer)override;
	virtual void OnMessage(EventMessage message, void* param)override;


private:
	void CalcYawPitch(float deltaTime);
	void Rotate();
	void RotateRockOn();

	void SearchRockOnActor();

private:
	enum class State {
		//!通常状態　注視点をグルグル
		Default,
		//!ロックオン状態
		LockOn,
		//!構えている状態
		Aim
	};

private:
	SimpleMesh skybox;
	//回転用のヨー（Z軸回転）
	float yaw;
	//回転用のピッチ（Y軸回転）
	float pitch;

	//回転用のヨーの合計（Z軸回転）
	float yaw_total;
	//回転用のピッチの合計（Y軸回転）
	float pitch_total;

	float lerp_start_yaw;
	float lerp_end_yaw;
	float lerp_t_yaw;


	//加減速する割合
	const float Accelerate_rate;
	//最大スピード
	const float Speed_max;
	//最大ヨー角度
	const float Yaw_max;
	//最大ピッチ角度
	const float Pitch_max;

	//ボスかプレイヤーが死んだか判定するフラグ
	bool isGameEnd;

	//オートロックオンできるプレイヤーからの距離
	const float TargetCanRockOnDistance;

	//ロックオンを解除する距離
	const float UnRockOnDistance;

	//あたり判定
	BoundingSphere body;
	State state;
	Actor* lockOnTarget;

};