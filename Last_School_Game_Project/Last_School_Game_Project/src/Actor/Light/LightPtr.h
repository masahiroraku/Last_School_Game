#pragma once

/**
* @file LightPtr.h
* @brief �Ɩ��̃|�C���^�[��`�t�@�C��
* @author ���]
* @date 2017/9/9
*/

#include<memory>
class ILight;
//!�Ɩ��N���X��shared_ptr�^�Ē�`
using LightPtr = std::shared_ptr<ILight>;