#pragma once

#include<memory>
class CameraBase;
/************************************************************
* File Name	: CameraPtr.h
* Description	: カメラポインタの定義
*																Date		:	Unknown.
*															  Author	:	阿曽
*************************************************************/
using CameraPtr = std::shared_ptr<CameraBase>;