#pragma once

/**
* @file StateManager.h
* @brief 状態クラスを管理するクラス定義ファイル
* @author 阿曽
* @date 2017/09/01
*/

#include"IStatePtr.h"
#include<unordered_map>
#include<functional>

enum class EventMessage;

/*! @class StateManager
*   @brief 状態クラスを管理するクラス
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
	//!コピー禁止
	StateManager(const StateManager& other) = delete;
	//!コピー禁止
	StateManager& operator = (const StateManager& other) = delete;
private:
	using StateContainer = std::unordered_map<int, IStatePtr>;
	StateContainer stateContainer;
	IStatePtr currentState;
	Function onChangeFunc;
	int id;
};
