#include "BiteAttack.h"
#include "Collision/BoundingSphere/BoundingSphere.h"
#include "Collision/HitInfo.h"
#include "Actor/Weapon/WeaponHitInfo.h"
#include "World/IWorld.h"
#include"BiteCollision.h"

BiteAttack::BiteAttack(IWorld& world, SkinningMesh & meshPtr)
	: isEnd(false)
	, world(world)
	, meshPtr(meshPtr)
{
}

BiteAttack::~BiteAttack()
{
}

void BiteAttack::Initialize()
{
	isEnd = false;
	world.AddActor(ActorGroup::Enemy, std::make_shared<BiteCollision>(world, meshPtr));
}

void BiteAttack::Update(float deltaTime)
{
	if (meshPtr.IsEndMotion()) {
		isEnd = true;
	}
}

void BiteAttack::Finalize()
{
}

void BiteAttack::HandleMessage(EventMessage message, void * param)
{
}

bool BiteAttack::IsEnd() const
{
	return isEnd;
}

int BiteAttack::GetNextState() const
{
	return -2;
}

int BiteAttack::GetNextAnime() const
{
	return 0;
}
