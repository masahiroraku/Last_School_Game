#pragma once

#include"Mesh/SimpleMesh/SimpleMesh.h"
#include"CameraBase.h"
#include"Actor/Base/ActorPtr.h"
#include"Actor/Status/HitPoint/HitPoint.h"
#include "Collision/ShapePtr.h"
#include"Collision/BoundingSphere/BoundingSphere.h"
#include"Math/Quaternion/Quaternion.h"

/************************************************************
* File Name	: FreeLookAtCamera.h
* Description	: 3D空間を映すカメラ
*																Date		:	Unknown.
*															  Author	:	阿曽
*************************************************************/
class FreeLookAtCamera : public CameraBase {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="world">world</param>
	explicit FreeLookAtCamera(IWorld& world);
	~FreeLookAtCamera();

	virtual void OnUpdate(float deltaTime) override;
	virtual void OnDraw(Renderer& renderer)override;
	virtual void OnMessage(EventMessage message, void* param)override;
private:
	void RotationMovement(float deltaTime);

private:
	SimpleMesh skybox;

	const float moveSpeed;
	const float turnSpeed;
	const float tiltMax;
	const float tiltMin;
	const float lookDistance;

	Vector3 localPosition;

	float lookAngle;
	float tiltAngle;
	Vector3 pivotEulers;
	Quaternion pivotTargetRotate;
	Quaternion transformTargetRotate;
};