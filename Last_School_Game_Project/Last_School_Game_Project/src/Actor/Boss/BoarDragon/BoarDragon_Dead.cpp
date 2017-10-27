#include "BoarDragon_Dead.h"

BoarDragon_Dead::BoarDragon_Dead(Actor& bossPtr, SkinningMesh& meshPtr)
	: bossPtr(bossPtr)
	, meshPtr(meshPtr)
	, isEnd(false)
	, state(BoarDragon::State::Idle)
	, anime(BoarDragon::Anime::Idle_)
{
}

BoarDragon_Dead::~BoarDragon_Dead()
{
}

void BoarDragon_Dead::Initialize()
{
	isEnd = false;
	state = BoarDragon::State::Idle;
	anime = BoarDragon::Anime::Idle_;
}

void BoarDragon_Dead::Update(float deltaTime)
{
	if (meshPtr.IsEndMotion()) {
		bossPtr.ChangeStatus(Status::DrawOnly);
	}
}

void BoarDragon_Dead::Finalize()
{
}

void BoarDragon_Dead::HandleMessage(EventMessage message, void * param)
{
}

bool BoarDragon_Dead::IsEnd() const
{
	return false;
}

int BoarDragon_Dead::GetNextState() const
{
	return 0;
}

int BoarDragon_Dead::GetNextAnime() const
{
	return 0;
}
