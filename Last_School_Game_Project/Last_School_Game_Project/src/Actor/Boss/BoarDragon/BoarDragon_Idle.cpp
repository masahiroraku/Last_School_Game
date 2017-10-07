#include "BoarDragon_Idle.h"
#include"Input/Input.h"

BoarDragon_Idle::BoarDragon_Idle()
	: isEnd(false)
	, state(BoarDragon::State::Idle)
	, anime(BoarDragon::Anime::Idle_)
{
}

BoarDragon_Idle::~BoarDragon_Idle()
{
}

void BoarDragon_Idle::Initialize()
{
	isEnd = false;
	state = BoarDragon::State::Idle;
	anime = BoarDragon::Anime::Idle_;
}

void BoarDragon_Idle::Update(float deltaTime)
{
	if (Input::GetInstance().IsKeyBoardDown(KEY_INPUT_1)) {
		isEnd = true;
		state = BoarDragon::State::Attack;
		anime = BoarDragon::Anime::Bite_;
	}
}

void BoarDragon_Idle::HandleMessage(EventMessage message, void * param)
{

}

bool BoarDragon_Idle::IsEnd() const
{
	return isEnd;
}

int BoarDragon_Idle::GetNextState() const
{
	return static_cast<int>(state);
}

int BoarDragon_Idle::GetNextAnime() const
{
	return anime;
}
