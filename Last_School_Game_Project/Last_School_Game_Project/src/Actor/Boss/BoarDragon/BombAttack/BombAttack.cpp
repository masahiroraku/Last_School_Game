#include "BombAttack.h"
#include "BombCollision.h"
#include "World/IWorld.h"
BombAttack::BombAttack(IWorld & world, SkinningMesh & meshPtr, const Actor& playerPtr)
	: isEnd(false)
	, world(world)
	, meshPtr(meshPtr)
	, MouseBoneIndex(15)
	, playerPtr(playerPtr)
{
}

BombAttack::~BombAttack()
{
}

void BombAttack::Initialize()
{
	world.AddActor(ActorGroup::Enemy, std::make_shared<BombCollision>(world, meshPtr.GetBonePosition(MouseBoneIndex), playerPtr.GetPosition()));
	isEnd = false;
}

void BombAttack::Update(float deltaTime)
{
	if (meshPtr.IsEndMotion()) {
		isEnd = true;
	}
}

void BombAttack::Finalize()
{
}

void BombAttack::HandleMessage(EventMessage message, void * param)
{
}

bool BombAttack::IsEnd() const
{
	return isEnd;
}

int BombAttack::GetNextState() const
{
	return -2;
}

int BombAttack::GetNextAnime() const
{
	return 0;
}

