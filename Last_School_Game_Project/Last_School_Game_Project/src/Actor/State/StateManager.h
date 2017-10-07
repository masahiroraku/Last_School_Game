#pragma once

/**
* @file StateManager.h
* @brief ��ԃN���X���Ǘ�����N���X��`�t�@�C��
* @author ���]
* @date 2017/09/01
*/

#include"IStatePtr.h"
#include<unordered_map>
#include<functional>

enum class EventMessage;

/*! @class StateManager
*   @brief ��ԃN���X���Ǘ�����N���X
*/
class StateManager {
public:
	using Function = std::function<void(int,int)>;
public:
	StateManager();
	~StateManager();
	void Update(float deltaTime);
	void HandleMessage(EventMessage message, void* param);
	void Add(int id, const IStatePtr& state);
	void Change(int id, int motion = 0);
	void SetChangeFunc(const Function& func);
	int GetState() const;
	int GetStateNum() const;
	void Reset();
private:
	//!�R�s�[�֎~
	StateManager(const StateManager& other) = delete;
	//!�R�s�[�֎~
	StateManager& operator = (const StateManager& other) = delete;
private:
	using StateContainer = std::unordered_map<int, IStatePtr>;
	StateContainer stateContainer;
	IStatePtr currentState;
	Function onChangeFunc;
	int id;
};
