#include "Sword.h"
#include"Collision/Capsule/Capsule.h"
#include"Math/Math.h"
#include"Collision/HitInfo.h"
#include"Actor/Weapon/WeaponHitInfo.h"

Sword::Sword(IWorld& world, SkinningMesh& parentMesh)
	: Actor(world,"Sword",Vector3::Zero,std::make_shared<Capsule>(Vector3(0,0,0),Vector3(0,0,-2),0.5f))
	, mesh(Assets::Model::Sword)
	, parentMesh(parentMesh)
	, damage(30)
{
	tag = ActorTag::PlayerWeapon;
	matrix = parentMesh.GetBoneWorldMatrix(20);
	position = parentMesh.GetBonePosition(20);
	body->isActive = false;
}


Sword::~Sword()
{
}

void Sword::OnUpdate(float deltaTime)
{
	matrix = parentMesh.GetBoneWorldMatrix(20);
	position = parentMesh.GetBonePosition(20);
}

void Sword::OnDraw(Renderer & renderer)
{
#if _DEBUG
	body->Transform(GetMatrix())->Draw();
#endif
	mesh.Draw(renderer, GetMatrix());
}

void Sword::OnCollide(const HitInfo & hitInfo)
{
	WeaponHitInfo weaponInfo(tag, damage);
	hitInfo.collideActor->HandleMessage(EventMessage::Damage, &weaponInfo);
}

void Sword::OnMessage(EventMessage message, void * param)
{
}
