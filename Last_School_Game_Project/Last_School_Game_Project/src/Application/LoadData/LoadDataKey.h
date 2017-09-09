#pragma once

/************************************************************
* File Name	: LoadDataKey.h
* Description	: ゲームで使う変数の初期値のファイル判別定義
*																Date		:	2017-04-01.
*															  Author	:	阿曽
*************************************************************/

/**
 * @file LoadDataKey.h
 * @brief ゲームで使う変数を使うキャラクターのファイル判別定義
 * @author 阿曽
 * @date 2017/4/1
 */

 /**
  * @enum LoadDataKey
  * ゲームで使う変数を使うキャラクター定義
  */
enum class LoadDataKey {
	//!プレイヤー
	Player,
	//!武器
	Weapon,
	//!敵
	Enemy
};
