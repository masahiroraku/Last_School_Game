#pragma once

/**
* @file StatePtr.h
* @brief ��ԃN���X�̒��ۃN���X��shared_pre�^��`�t�@�C��
* @author ���]
* @date 2017/09/01
*/

#include<memory>
class IState;

using IStatePtr = std::shared_ptr<IState>;