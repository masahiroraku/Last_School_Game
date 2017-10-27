#include "StateNull.h"

StateNull::StateNull()
{
}

StateNull::~StateNull()
{
}

void StateNull::Initialize()
{
}

void StateNull::Update(float deltaTime)
{
}

void StateNull::Finalize()
{
}

void StateNull::HandleMessage(EventMessage message, void * param)
{
}

bool StateNull::IsEnd() const
{
	return false;
}

int StateNull::GetNextState() const
{
	return 0;
}

int StateNull::GetNextAnime() const
{
	return 0;
}
