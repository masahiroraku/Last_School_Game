#include "Idle.h"
#include"Actor/Player/Player.h"
#include"Input/Input.h"

Idle::Idle()
	: isEnd(false)
	, state(Player::State::Idle)
	, anime(Player::Anime::Idle_)
{
}


Idle::~Idle()
{
}

void Idle::Initialize()
{
	isEnd = false;
	state = Player::State::Idle;
	anime = Player::Anime::Idle_;
}

void Idle::Update(float deltaTime)
{
	if (Input::GetInstance().GetCommand(Command::Guard)) {
		isEnd = true;
		state = Player::State::Guard;
		anime = Player::Anime::Guard_Start_;
		return;
	}
	if (Input::GetInstance().GetVelocity().SquareLength() >= 0.1f) {
		isEnd = true;
		state = Player::State::Move;
		anime = Player::Anime::Walk_;
		return;
	}
	if (Input::GetInstance().GetCommand(Command::SwordAttack)) {
		isEnd = true;
		state = Player::State::SwordAttack;
		anime = Player::Anime::Slash_00_;
	}
	if (Input::GetInstance().GetCommand(Command::Shoot_Arrow)) {
		isEnd = true;
		state = Player::State::BowAttack;
		anime = Player::Anime::Aim_OverDraw_;
	}
}

void Idle::Finalize()
{
}

void Idle::HandleMessage(EventMessage message, void * param)
{
}

bool Idle::IsEnd() const
{
	return isEnd;
}

int Idle::GetNextState() const
{
	return static_cast<int>(state);
}

int Idle::GetNextAnime() const
{
	return anime;
}
