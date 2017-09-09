#pragma once

/**
 * @file IWorld.h
 * @brief アクターが共有するインターフェースクラス
 * @author 阿曽
 * @date 2015/09/12
 */

#include "Actor/Base/ActorPtr.h"
#include<string>

enum class ActorGroup;
class ICamera;
class IField;
enum class EventMessage;

/*! @class IWorld
*	@brief  アクターが共有するインターフェースクラス
*/
class IWorld {
public:		
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~IWorld() {}
	/// <summary>
	/// アクターを追加する
	/// </summary>
	/// <param name="group">追加するグループ</param>
	/// <param name="actor">追加するアクターポインタ</param>
	virtual void AddActor(ActorGroup group, const ActorPtr& actor) = 0;
	/// <summary>
	/// アクターを検索する
	/// </summary>
	/// <param name="name">検索するアクターの名前</param>
	/// <returns>[true ActorPtr] : [false nullptr]</returns>
	virtual ActorPtr FindActor(const std::string& name) = 0;
	/// <summary>
	/// アクターを検索する
	/// </summary>
	/// <param name="group">検索するアクターのグループ</param>
	/// <param name="name">検索するアクターの名前</param>
	/// <returns>[true ActorPtr] : [false nullptr]</returns>
	virtual ActorPtr FindActor(ActorGroup group, const std::string& name) = 0;
	/// <summary>
	/// グループの親のポインタを取得する
	/// </summary>
	/// <param name="group">アクターのグループ</param>
	/// <returns>[true ActorPtr] : [false nullptr]</returns>
	virtual ActorPtr GetRoot(ActorGroup group) = 0;
	/// <summary>
	/// カメラのポインタを取得
	/// </summary>
	/// <returns>カメラのポインタ</returns>
	virtual ICamera& GetCamera() = 0;
	/// <summary>
	/// ステージのポインタを取得
	/// </summary>
	/// <returns>ステージのポインタ</returns>
	virtual IField& GetField() const = 0;
	/// <summary>
	/// 全アクターにイベントメッセージを送信
	/// </summary>
	/// <param name="message">登録したイベントメッセージ</param>
	/// <param name="param">イベントと一緒に送る変数</param>
	virtual void SendEventMessage(EventMessage message, void* param = nullptr) = 0;
};
