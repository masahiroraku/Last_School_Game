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

/*! @class StateManager
*   @brief 状態クラスを管理するクラス
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
	//!コピー禁止
	StateManager(const StateManager& other) = delete;
	//!コピー禁止
	StateManager& operator = (const StateManager& other) = delete;
private:
	using StateContainer = std::unordered_map<int, IStatePtr>;
	StateContainer stateContainer;
	IStatePtr currentState;
	Function onChangeFunc;
};
