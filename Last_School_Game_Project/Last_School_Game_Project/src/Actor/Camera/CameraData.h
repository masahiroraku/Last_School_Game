#pragma once

/**
* @file CameraData.h
* @brief カメラの設定構造体の定義ファイル
* @author 阿曽
* @date 2017/10/27
*/

/*! @struct CameraData
*   @brief カメラの設定構造体
*/
struct CameraData {
	//!カメラの縦軸の移動を反転させるか
	bool isVertivalReverce;
	//!カメラの横軸の移動を反転させるか
	bool isHorizontalReverce;
	//!移動スピード
	float moveSpeed;
};