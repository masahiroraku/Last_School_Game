#include "Idle.h"
#include"Actor/Player/Player.h"
#include"Input/Input.h"

Idle::Idle()
	: isEnd(false)
{
}


Idle::~Idle()
{
}

void Idle::Initialize()
{
	isEnd = false;
}

void Idle::Update(float deltaTime)
{
	isEnd = Input::GetInstance().GetVelocity().SquareLength() >= 0.1f;
}

bool Idle::IsEnd() const
{
	return isEnd;
}

int Idle::GetNextState() const
{
	return static_cast<int>(Player::State::Move);
}

int Idle::GetNextAnime() const
{
	return Player::Anime::Walk_;
}
