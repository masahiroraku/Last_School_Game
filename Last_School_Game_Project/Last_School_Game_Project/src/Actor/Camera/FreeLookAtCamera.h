#pragma once

#include"Mesh/SimpleMesh/SimpleMesh.h"
#include"CameraBase.h"
#include"Actor/Base/ActorPtr.h"
#include"Actor/Status/HitPoint/HitPoint.h"
#include "Collision/ShapePtr.h"
#include"Collision/BoundingSphere/BoundingSphere.h"
#include"Math/Quaternion/Quaternion.h"
#include"Actor/State/StateManager.h"

/************************************************************
* File Name	: FreeLookAtCamera.h
* Description	: 3D空間を映すカメラ
*																Date		:	Unknown.
*															  Author	:	阿曽
*************************************************************/
class FreeLookAtCamera : public CameraBase {
public:
	enum class State {
		//!ターゲットを中心に回転する
		Default,
		//!射撃物を構える
		Aim,
		//!ロックオン
		LockOn
	};
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="world">world</param>
	explicit FreeLookAtCamera(IWorld& world);
	~FreeLookAtCamera();
	virtual void OnInitialize() override;
	virtual void OnUpdate(float deltaTime) override;
	virtual void OnDraw(Renderer& renderer)override;
	virtual void OnMessage(EventMessage message, void* param)override;
private:

private:
	SimpleMesh skybox;

	const float lookDistance;
	StateManager stateManager;

	Vector3 lookat;

};