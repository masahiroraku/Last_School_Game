#include"StateManager.h"
#include"IState.h"
#include"Actor/Base/EventMessage.h"
#include"StateNull.h"

StateManager::StateManager()
	: stateContainer()
	, currentState(nullptr)
	, onChangeFunc([](int,int) {})
	, id(-1)
{
	currentState = std::make_shared<StateNull>();
}
StateManager::~StateManager() {
}
void StateManager::Update(float deltaTime) {
	if (!currentState->IsEnd()) {
		currentState->Update(deltaTime);
		return;
	}
	Change(currentState->GetNextState(),currentState->GetNextAnime());
}
void StateManager::HandleMessage(EventMessage message, void * param)
{
	currentState->HandleMessage(message, param);
}
void StateManager::Add(int id, const IStatePtr & state)
{
	stateContainer.emplace(id, state);
}
void StateManager::Change(int id, int motion)
{
	onChangeFunc(id,motion);
	if (this->id == id || id < -1)
		return;
	this->id = id;
	currentState->Finalize();
	currentState = stateContainer.at(id);
	currentState->Initialize();
}

void StateManager::SetChangeFunc(const Function & func)
{
	onChangeFunc = func;
}

int StateManager::GetState() const
{
	return id;
}

int StateManager::GetStateNum() const
{
	return static_cast<int>(stateContainer.size());
}

void StateManager::Reset()
{
	id = -1;
}
