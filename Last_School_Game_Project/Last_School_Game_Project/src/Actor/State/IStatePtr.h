#pragma once

/**
* @file StatePtr.h
* @brief 状態クラスの抽象クラスのshared_pre型定義ファイル
* @author 阿曽
* @date 2017/09/01
*/

#include<memory>
class IState;

using IStatePtr = std::shared_ptr<IState>;