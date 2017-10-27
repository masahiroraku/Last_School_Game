#include "FreeLookAtCamera.h"
#include"Actor/Base/Actor.h"
#include"Input/Input.h"
#include"Math/Convert/Convert.h"
#include"Utility/Utility.h"
#include"DefaultCameraState.h"
#include"AimCameraState.h"
FreeLookAtCamera::FreeLookAtCamera(IWorld & world)
	: CameraBase(world)
	, skybox(Assets::Model::Skybox,false)
	, lookDistance(10.0f)
	, stateManager()
	, lookat()
{
}

FreeLookAtCamera::~FreeLookAtCamera()
{
}

void FreeLookAtCamera::OnInitialize()
{
	stateManager.Add(static_cast<int>(State::Default), std::make_shared<DefaultCameraState>(matrix,lookat, *target));
	stateManager.Add(static_cast<int>(State::Aim), std::make_shared<AimCameraState>(matrix,lookat, *target));
	stateManager.Change(static_cast<int>(State::Default));
	
	lookat = target->GetPosition() + Vector3(0, 1, 0);
	//カメラ位置と注視点を設定
	SetCameraPositionAndTargetAndUpVec(
		Convert::ToVECTOR(matrix.GetPosition()),
		Convert::ToVECTOR(lookat),
		Convert::ToVECTOR(matrix.GetUp())
	);

}

void FreeLookAtCamera::OnUpdate(float deltaTime)
{
	stateManager.Update(deltaTime);
	
	//カメラ位置と注視点を設定
	SetCameraPositionAndTargetAndUpVec(
		Convert::ToVECTOR(matrix.GetPosition()),
		Convert::ToVECTOR(lookat),
		Convert::ToVECTOR(matrix.GetUp())
	);
}

void FreeLookAtCamera::OnDraw(Renderer & renderer)
{
	skybox.Draw(renderer, Matrix4::Translate(matrix.GetPosition()));
}

void FreeLookAtCamera::OnMessage(EventMessage message, void * param)
{
	stateManager.HandleMessage(message, param);
}

