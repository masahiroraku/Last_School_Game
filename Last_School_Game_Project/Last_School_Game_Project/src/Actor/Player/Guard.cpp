#include "Guard.h"
#include "Input/Input.h"

Guard::Guard(SkinningMesh& meshPtr)
	: meshPtr(meshPtr)
	, isEnd(false)
	, state(Player::State::Idle)
	, anime(Player::Anime::Idle_)
	, guardState(GuardState::Begin)
{
}
Guard::~Guard()
{
}

void Guard::Initialize()
{
	isEnd = false;
	state = Player::State::Idle;
	anime = Player::Anime::Idle_;
	guardState = GuardState::Begin;
	meshPtr.ChangeMotion(Player::Anime::Guard_Start_);
}

void Guard::Update(float deltaTime)
{
	if (meshPtr.IsEndMotion() == true && guardState == GuardState::End) {
		isEnd = true;
		return;
	}

	if (Input::GetInstance().GetCommand(Command::Guard) == false) {
		guardState = GuardState::End;
		return;
	}

	if (meshPtr.IsEndMotion() == true && guardState == GuardState::Begin) {
		guardState = GuardState::Do;
		meshPtr.ChangeMotion(Player::Anime::Guard_);
	}
}

void Guard::Finalize()
{
}

void Guard::HandleMessage(EventMessage message, void * param)
{
}

bool Guard::IsEnd() const
{
	return isEnd;
}

int Guard::GetNextState() const
{
	return static_cast<int>(state);
}

int Guard::GetNextAnime() const
{
	return anime;
}
