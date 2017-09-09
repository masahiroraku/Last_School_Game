#pragma once

/************************************************************
* File Name	: ActorTag.h
* Description	: アクターを判別するタグ
*																Date		:	2017-02-23.
*															  Author	:	阿曽
*************************************************************/
enum class ActorTag {
	//特になし　デフォルトで使用
	None,
	//プレイヤー
	Player,
	//骨の敵
	Skeleton,
	Punch_Left,
	Punch_Right,
	Kick,
	Ball,
	BossAttack,
	UnLockOnTarget
};