#pragma once

/**
* @file IState.h
* @brief アクターの状態関数の抽象クラス定義ファイル
* @author 阿曽
* @date 2017/09/01
*/

enum class EventMessage;

/*! @class IState
*   @brief アクターの状態関数の抽象クラス
*/
class IState {
public:	
	/// <summary>
	/// 仮想デストラクタ
	/// </summary>
	virtual ~IState() {}
	/// <summary>
	/// 状態の初期化
	/// </summary>
	virtual void Initialize() = 0;
	/// <summary>
	/// 状態の更新
	/// </summary>
	/// <param name="deltaTime">１フレーム</param>
	virtual void Update(float deltaTime) = 0;
	/// <summary>
	/// 状態の終了
	/// </summary>
	virtual void Finalize() = 0;

	/// <summary>
	/// アクターのメッセージを受け取る
	/// </summary>
	/// <param name="message">メッセージの種類</param>
	/// <param name="param">メッセージと一緒に送られる情報</param>
	virtual void HandleMessage(EventMessage message, void* param) = 0;
	/// <summary>
	/// 次の状態に遷移するかどうか
	/// </summary>
	/// <returns>
	/// [true:遷移する false:遷移しない]
	/// </returns>
	virtual bool IsEnd() const = 0;	
	/// <summary>
	/// 次に遷移する状態を取得する
	/// </summary>
	/// <returns>次の状態</returns>
	virtual int GetNextState() const = 0;
	/// <summary>
	/// 次に再生するアニメーション番号を取得する
	/// </summary>
	/// <returns>次に再生するアニメーション番号</returns>
	virtual int GetNextAnime() const = 0;
};
