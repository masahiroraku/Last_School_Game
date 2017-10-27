#include "BoarDragon_Attack.h"
#include"Input/Input.h"
#include"BiteAttack/BiteAttack.h"
#include"BombAttack/BombAttack.h"
#include"RushAttack/RushAttack.h"
#include"World/IWorld.h"

BoarDragon_Attack::BoarDragon_Attack(IWorld& world,Actor& playerPtr, Actor& bossPtr, SkinningMesh& meshPtr)
	: world(world)
	, playerPtr(playerPtr)
	, bossPtr(bossPtr)
	, meshPtr(meshPtr)
	, isEnd(false)
	, state()
	, anime()
	, stateManager()
{
	//TODO: -2‚ð‚â‚ß‚é
	stateManager.SetChangeFunc([&](int state, int motion) {
		if (state == -2) {
			isEnd = true;
			return;
		}
		meshPtr.ChangeMotion(motion);
	});

	stateManager.Add(static_cast<int>(AttackType::Bite), std::make_shared<BiteAttack>(world,meshPtr));
	stateManager.Add(static_cast<int>(AttackType::Bomb), std::make_shared<BombAttack>(world, meshPtr,playerPtr));
	stateManager.Add(static_cast<int>(AttackType::Rush), std::make_shared<RushAttack>(world,bossPtr,meshPtr,playerPtr));
}

BoarDragon_Attack::~BoarDragon_Attack()
{
}

void BoarDragon_Attack::Initialize()
{
	isEnd = false;
	state = BoarDragon::State::Idle;
	anime = BoarDragon::Anime::Idle_;

	BranchAttackType();
}

void BoarDragon_Attack::Update(float deltaTime)
{
	stateManager.Update(deltaTime);
}

void BoarDragon_Attack::Finalize()
{
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

void BoarDragon_Attack::BranchAttackType()
{
	stateManager.Reset();

	float squarelength = (playerPtr.GetPosition() - bossPtr.GetPosition()).SquareLength();
	static const float BiteLength = 15.0f;
	static const float BombLength = 25.0f;

	if (squarelength <= BiteLength * BiteLength) {
		stateManager.Change(static_cast<int>(AttackType::Bite), BoarDragon::Anime::Bite_);
	}
	else if (squarelength <= BombLength * BombLength) {
		stateManager.Change(static_cast<int>(AttackType::Bomb), BoarDragon::Anime::Scream_);
	}
	else {
		stateManager.Change(static_cast<int>(AttackType::Rush), BoarDragon::Anime::Run_);
	}
} 
