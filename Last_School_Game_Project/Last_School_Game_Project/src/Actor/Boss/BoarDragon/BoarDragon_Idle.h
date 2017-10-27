#pragma once
#include "Actor/State/IState.h"
#include"BoarDragon.h"

class BoarDragon_Idle : public IState {
public:
	BoarDragon_Idle(Actor& playerPtr,Actor& bossPtr);
	~BoarDragon_Idle();
private:
	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Initialize() override;

	/// <summary>
	/// 状態の更新
	/// </summary>
	/// <param name="deltaTime">１フレーム</param>
	virtual void Update(float deltaTime) override;
	/// <summary>
	/// 状態の終了
	/// </summary>
	virtual void Finalize() override;

	/// <summary>
	/// アクターのメッセージを受け取る
	/// </summary>
	/// <param name="message">メッセージの種類</param>
	/// <param name="param">メッセージと一緒に送られる情報</param>
	virtual void HandleMessage(EventMessage message, void* param) override;
	/// <summary>
	/// 次の状態に遷移するかどうか
	/// </summary>
	/// <returns>
	/// [true:遷移する false:遷移しない]
	/// </returns>
	virtual bool IsEnd() const override;
	/// <summary>
	/// 次に遷移する状態を取得する
	/// </summary>
	/// <returns>次の状態</returns>
	virtual int GetNextState() const override;
	/// <summary>
	/// 次に再生するアニメーション番号を取得する
	/// </summary>
	/// <returns>次に再生するアニメーション番号</returns>
	virtual int GetNextAnime() const override;
private:
	bool isEnd;
	BoarDragon::State state;
	BoarDragon::Anime anime;
	Actor& playerPtr;
	Actor& bossPtr;
};

