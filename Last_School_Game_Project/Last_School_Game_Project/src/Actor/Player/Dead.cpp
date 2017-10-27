#include "Dead.h"

Dead::Dead(Actor& playerPtr, SkinningMesh& meshPtr)
	: playerPtr(playerPtr)
	, meshPtr(meshPtr)
	, state(Player::State::Idle)
	, anime(Player::Anime::Idle_)
	, isEnd(false)
{
}

Dead::~Dead()
{
}

void Dead::Initialize()
{
	isEnd = false;
	state = Player::State::Idle;
	anime = Player::Anime::Idle_;
}

void Dead::Update(float deltaTime)
{
	if (meshPtr.IsEndMotion()) {
		playerPtr.ChangeStatus(Status::DrawOnly);
	}
}

void Dead::Finalize()
{
}

void Dead::HandleMessage(EventMessage message, void * param)
{
}

bool Dead::IsEnd() const
{
	return false;
}

int Dead::GetNextState() const
{
	return 0;
}

int Dead::GetNextAnime() const
{
	return 0;
}
