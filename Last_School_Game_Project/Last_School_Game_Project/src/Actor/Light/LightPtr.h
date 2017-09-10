#pragma once

/**
* @file LightPtr.h
* @brief 照明のポインター定義ファイル
* @author 阿曽
* @date 2017/9/9
*/

#include<memory>
class ILight;
//!照明クラスのshared_ptr型再定義
using LightPtr = std::shared_ptr<ILight>;