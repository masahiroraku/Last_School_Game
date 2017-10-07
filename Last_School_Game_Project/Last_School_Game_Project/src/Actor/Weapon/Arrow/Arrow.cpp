#include "Arrow.h"
#include"Collision/Line/Line.h"
#include"Math/Math.h"
#include"Collision/HitInfo.h"
#include"Actor/Weapon/WeaponHitInfo.h"

Arrow::Arrow(IWorld & world, SkinningMesh & parentMesh)
	: Actor(world,"Arrow",Vector3::Zero,std::make_shared<Line>(Vector3(0,0,0),Vector3(0,0,2)))
	, mesh(Assets::Model::Arrow)
	, parentMesh(parentMesh)
	, damage(10)
{
	tag = ActorTag::PlayerWeapon;
	matrix = parentMesh.GetBoneWorldMatrix(35);
	position = parentMesh.GetBonePosition(35);
}

Arrow::~Arrow()
{
}

void Arrow::OnUpdate(float deltaTime)
{
	matrix = parentMesh.GetBoneWorldMatrix(35);
	position = parentMesh.GetBonePosition(35);
}

void Arrow::OnDraw(Renderer & renderer)
{
#if _DEBUG
	body->Transform(GetMatrix())->Draw();
#endif
	mesh.Draw(renderer, GetMatrix());
}

void Arrow::OnCollide(const HitInfo & hitInfo)
{
	WeaponHitInfo weaponInfo(tag, damage);
	hitInfo.collideActor->HandleMessage(EventMessage::Damage, &weaponInfo);
}

void Arrow::OnMessage(EventMessage message, void * param)
{
}
