#include"StateManager.h"
#include"IState.h"

StateManager::StateManager()
	: stateContainer()
	, currentState(nullptr)
	, onChangeFunc([]() {})
{

}
StateManager::~StateManager() {

}
void StateManager::Update(float deltaTime) {
	if (!currentState->IsEnd()) {
		currentState->Update(deltaTime);
		return;
	}
	Change(currentState->GetNextState());
}
void StateManager::Add(int id, const IStatePtr & state)
{
	stateContainer.emplace(id, state);
}
void StateManager::Change(int id)
{
	onChangeFunc();
	currentState = stateContainer.at(id);
}

void StateManager::SetChangeFunc(const Function & func)
{
	onChangeFunc = func;
}
