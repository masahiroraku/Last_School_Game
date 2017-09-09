#pragma once

/************************************************************
* File Name	: EventMessage.h
* Description	: アクターに対して行うイベントの定義
*																Date		:	Unknown.
*															  Author	:	阿曽
*************************************************************/
enum class EventMessage {
	//プレイヤーの攻撃
	PlayerAttack,
	//爆破ダメージを与える
	Explosion,
	//重ならないように押し出し
	Push,
	//必殺技ゲージの数値を上げる
	AttackPoint_Add,
	//吸い取りを行う
	Drain,
	//ボスが死んだ
	Boss_Dead,
	//プレイヤーが死んだ
	Player_Dead,
	//プレイヤーまたはボスの死亡アニメーションの再生終了
	DeadAnimation_End,
	//回復
	Heal,
	//敵の攻撃
	EnemyAttack,
	//ボスのキック
	BossKick,
	//ポーズ画面終了
	PauseEnd,
	//ボスのチャージ開始
	Boss_Charge,
	//生成地点に移動
	Boss_MoveToSpawnPoint,
	//生成し終わり
	Boss_EndSpawn,
	Ball_Collide,
	DisableActive,
	BossChangeMode
};