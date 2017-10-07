#pragma once


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
	//!剣攻撃
	SwordAttack,
	//!走り
	Dash,
	//!ジャンプ
	Jump,
	//!ガード
	Guard,
	//!矢を放つ
	Shoot_Arrow,
	//!最大コマンド数
	Max_Of_Num
};
