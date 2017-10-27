#include "RushAttack.h"

RushAttack::RushAttack(IWorld & world, Actor& bossPtr, const SkinningMesh & meshPtr, const Actor & playerPtr)
	: isEnd(false)
	, world(world)
	, bossPtr(bossPtr)
	, meshPtr(meshPtr)
	, playerPtr(playerPtr)
{
}

RushAttack::~RushAttack()
{
}

void RushAttack::Initialize()
{
	isEnd = false;
}

void RushAttack::Update(float deltaTime)
{
}

void RushAttack::Finalize()
{
}

void RushAttack::HandleMessage(EventMessage message, void * param)
{
}

bool RushAttack::IsEnd() const
{
	return isEnd;
}

int RushAttack::GetNextState() const
{
	return -2;
}

int RushAttack::GetNextAnime() const
{
	return 0;
}
