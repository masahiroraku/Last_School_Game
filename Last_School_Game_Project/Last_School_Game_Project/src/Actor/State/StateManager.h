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

/*! @class StateManager
*   @brief ��ԃN���X���Ǘ�����N���X
*/
class StateManager {
public:
	using Function = std::function<void(void)>;
public:
	StateManager();
	~StateManager();
	void Update(float deltaTime);
	void Add(int id, const IStatePtr& state);
	void Change(int id);
	void SetChangeFunc(const Function& func);
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
};
