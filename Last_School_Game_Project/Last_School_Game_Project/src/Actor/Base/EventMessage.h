#pragma once

/************************************************************
* File Name	: EventMessage.h
* Description	: アクターに対して行うイベントの定義
*																Date		:	Unknown.
*															  Author	:	阿曽
*************************************************************/
enum class EventMessage {
	//!重ならないように押し出し
	Push,
	//!ダメージを与える
	Damage,
};