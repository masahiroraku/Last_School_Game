#include "BoarDragon_Attack.h"
#include"Input/Input.h"
#include"BiteAttack/BiteAttack.h"
#include"World/IWorld.h"

BoarDragon_Attack::BoarDragon_Attack(IWorld& world, Actor& bossPtr, SkinningMesh& meshPtr)
	: world(world)
	, bossPtr(bossPtr)
	, meshPtr(meshPtr)
	, isEnd(false)
	, state()
	, anime()
	, attackType()
{
}

BoarDragon_Attack::~BoarDragon_Attack()
{
}

void BoarDragon_Attack::Initialize()
{
	isEnd = false;
	state = BoarDragon::State::Idle;
	anime = BoarDragon::Anime::Idle_;
	attackType = AttackType::Bite;
	if (attackType == AttackType::Bite) {
		world.AddActor(ActorGroup::Enemy, std::make_shared<BiteAttack>(world, meshPtr));
		meshPtr.ChangeMotion(BoarDragon::Anime::Bite_);
	}
}

void BoarDragon_Attack::Update(float deltaTime)
{
	if (meshPtr.IsEndMotion()) {
		isEnd = true;
	}
}

void BoarDragon_Attack::HandleMessage(EventMessage message, void * param)
{
}

bool BoarDragon_Attack::IsEnd() const
{
	return isEnd;
}

int BoarDragon_Attack::GetNextState() const
{
	return static_cast<int>(state);
}

int BoarDragon_Attack::GetNextAnime() const
{
	return anime;
}
