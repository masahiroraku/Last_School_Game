#pragma once

/**
 * @file LoadDataValue.h
 * @brief ゲームで使う変数の初期値の要素定義
 * @author 阿曽
 * @date 2017/4/1
 */

 /// <summary>
 /// ゲームで使う変数の初期値の要素
 /// </summary>
namespace LoadDataValue {
	/**
	 * @enum PlayerData
	 * プレイヤーの変数の初期値定義
	 */
	enum class PlayerData {
		//!0番目調整用
		None,
		//!左手のボーン番号
		LeftHand,
		//!右手のボーン番号
		RightHand,
		//!右足のボーン番号
		RightFoot,
		//!ノックバック速度
		KnockBackSpeed,
		//!ノックバックする距離
		KnockBackDistance,
		//!あたり判定のカプセルの始点座標
		CollideCapsule_DownPosition,
		//!あたり判定のカプセルの終点座標
		CollideCapsule_UpPosition,
		//!あたり判定のカプセルの半径
		CollideCapsule_Radius,
		//!ヒットポイント
		HP,
		//!歩く速さ
		WalkSpeed,
		//!ダメージを受ける時間
		DamageTimer,
		//!パンチ攻撃0番目のあたり判定開始時間
		Punch00_BeginTime,
		//!パンチ攻撃0番目のあたり判定終了時間
		Punch00_EndTime,
		//!パンチ攻撃1番目のあたり判定開始時間
		Punch01_BeginTime,
		//!パンチ攻撃1番目のあたり判定終了時間
		Punch01_EndTime,
		//!パンチ攻撃2番目のあたり判定開始時間
		Punch02_BeginTime,
		//!パンチ攻撃2番目のあたり判定終了時間
		Punch02_EndTime,
		//!パンチ攻撃3番目のあたり判定開始時間
		Punch03_BeginTime,
		//!パンチ攻撃3番目のあたり判定終了時間
		Punch03_EndTime,
		//!パンチ攻撃4番目のあたり判定開始時間
		Punch04_BeginTime,
		//!パンチ攻撃4番目のあたり判定終了時間
		Punch04_EndTime,
		//!キック攻撃0番目のあたり判定開始時間
		Kick_BeginTime,
		//!キック攻撃0番目のあたり判定終了時間
		Kick_EndTime,
	};
	/**
	 * @enum EnemyData
	 * 敵の変数の初期値定義
	 */
	enum class EnemyData {
		None
	};
	/**
	 * @enum WeaponData
	 * 武器の変数の初期値定義
	 */
	enum class WeaponData {
		None,
	};
}