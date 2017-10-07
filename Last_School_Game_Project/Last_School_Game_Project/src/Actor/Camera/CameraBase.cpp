#include"Utility/cpplinq.hpp"
#include "CameraBase.h"
#include"Math/Convert/Convert.h"
#include"World/IWorld.h"
#include"Actor/Base/Actor.h"
#include<DxLib.h>

CameraBase::CameraBase(IWorld & world)
	: world(&world)
	, matrix()
	, target(nullptr)
	, position()
{
	//Near Far@‚ðÝ’è
	SetCameraNearFar(0.1f, 1000.0f);
}

CameraBase::~CameraBase()
{
}

Matrix4 CameraBase::GetMatrix()
{
	return matrix.SetPosition(position);
}

void CameraBase::SetTarget(const Actor & target)
{
	this->target = &target;
}


bool CameraBase::IsInsideCameraView(const Vector3 & position) const
{
	return CheckCameraViewClip(Convert::ToVECTOR(position)) == 0;
}

std::list<ActorPtr> CameraBase::IsInsideCameraViewActors(ActorGroup group) const
{
	using namespace cpplinq;
	return 	from(world->GetRoot(group)->GetChildren()) >> where([&](const ActorPtr& child) {
		return IsInsideCameraView(child->GetPosition());
	}) >> to_list();
}


void CameraBase::Update(float deltaTime)
{
	OnUpdate(deltaTime);
}

void CameraBase::Draw(Renderer & renderer)
{
	OnDraw(renderer);
}

void CameraBase::HandleMessage(EventMessage message, void * param)
{
	OnMessage(message, param);
}

void CameraBase::OnUpdate(float deltaTime)
{
	static_cast<void>(deltaTime);
}

void CameraBase::OnDraw(Renderer & renderer)
{
	static_cast<void>(renderer);
}

void CameraBase::OnMessage(EventMessage message, void * param)
{
	static_cast<void>(message);
	static_cast<void>(param);
}
