#pragma once

/************************************************************
* File Name	: ActorGroup.h
* Description	: アクターグループクラス
*																Date		:	2015-09-12.
*															  Author	:	阿曽
*************************************************************/
enum class ActorGroup {
	//!デフォルト
	None,
	//プレイヤー
	Player,
	//敵
	Enemy,
	//武器
	Weapon,
	//エフェクト
	Effect,
	//ユーザーインターフェース
	UI,
	//ステージ
	Stage
};