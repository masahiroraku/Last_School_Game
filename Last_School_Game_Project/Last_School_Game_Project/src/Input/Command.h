#pragma once

/************************************************************
* File Name	: Command.h
* Description	: 入力のゲーム用のボタン定義ヘッダー
*																Date		:	Unknown.
*															  Author	:	阿曽
*************************************************************/

/**
 * @file Command.h
 * @brief 入力のゲーム用のボタン定義ヘッダー
 * @author 阿曽
 * @date Unknown
 */

 /**
  * @enum Command
  * ゲーム用のボタン
  */
enum class Command {
	//!ゲームを閉じる
	ShutDown,
	//!弱攻撃
	Attack_Light,
	//!強攻撃
	Attack_High,
	//!走り
	Dash,
	//!ガード
	Guard,
	//!緊急回避
	QuickRoll,
	//!近距離必殺技
	NearAttack,
	//!遠距離必殺技
	FarAttack,
	//!ドレイン・吸い取る
	Drain,
	//!カメラリセット
	Camera_RockOn,
	//!項目決定ボタン　メニューとかに使う
	Decide,
	//!ポーズボタン　ゲームメインで使う
	Pause,
	//!最大コマンド数
	Max_Of_Num
};
