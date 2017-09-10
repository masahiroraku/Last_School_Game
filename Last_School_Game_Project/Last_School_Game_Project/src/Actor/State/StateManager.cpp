#include"StateManager.h"
#include"IState.h"

StateManager::StateManager()
	: stateContainer()
	, currentState(nullptr)
	, onChangeFunc([](int,int) {})
	, id(-1)
{

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
void StateManager::Add(int id, const IStatePtr & state)
{
	stateContainer.emplace(id, state);
}
void StateManager::Change(int id, int motion)
{
	onChangeFunc(id,motion);
	if (this->id == id)
		return;
	this->id = id;
	currentState = stateContainer.at(id);
	currentState->Initialize();
}

void StateManager::SetChangeFunc(const Function & func)
{
	onChangeFunc = func;
}
