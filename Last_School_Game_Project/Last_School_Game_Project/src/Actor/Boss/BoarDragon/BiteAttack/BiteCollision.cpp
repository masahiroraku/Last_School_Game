#include "BiteCollision.h"
#include "Collision/BoundingSphere/BoundingSphere.h"
#include "Collision/HitInfo.h"
#include "Actor/Weapon/WeaponHitInfo.h"

BiteCollision::BiteCollision(IWorld & world, SkinningMesh & meshPtr)
	: Actor(world, "BiteAttack", Vector3::Zero, std::make_shared<BoundingSphere>(Vector3::Zero, 1.0f))
	, meshPtr(meshPtr)
	, ToggleBoneIndex(17)
	, enableCollideTime()
	, damage(30)
{
	tag = ActorTag::EnemyWeapon;
	enableCollideTime = std::make_pair(19.0f, 21.0f);
	body->isActive = false;
	position = meshPtr.GetBonePosition(ToggleBoneIndex);
}

BiteCollision::~BiteCollision()
{
}

void BiteCollision::OnInitialize()
{
}

void BiteCollision::OnUpdate(float deltaTime)
{
	if (meshPtr.IsEndMotion()) {
		status = Status::Dead;
		return;
	}
	position = meshPtr.GetBonePosition(ToggleBoneIndex);
	body->isActive = IsEnableCollideTime();
}

void BiteCollision::OnDraw(Renderer & renderer)
{
#if _DEBUG
	body->Transform(GetMatrix())->Draw();
#endif
}

void BiteCollision::OnCollide(const HitInfo & hitInfo)
{

	WeaponHitInfo weaponInfo(tag, damage);
	hitInfo.collideActor->HandleMessage(EventMessage::Damage, &weaponInfo);
}

void BiteCollision::OnMessage(EventMessage message, void * param)
{

}

bool BiteCollision::IsEnableCollideTime() const
{
	return meshPtr.GetMotionTime() >= enableCollideTime.first && enableCollideTime.second >= meshPtr.GetMotionTime();
}
