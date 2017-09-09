#pragma once

/**
 * @file World.h
 * @brief アクターが共有するクラス
 * @author 阿曽
 * @date 2015/9/12
 */

#include "IWorld.h"
#include "Actor/Base/ActorManager.h"
#include"Actor/Camera/CameraPtr.h"
#include"Actor/Field/FieldPtr.h"

class Renderer;

/*! @class World
*   @brief  アクターが共有するクラス
*/
class World : public IWorld {
public:
	/// <summary>
	 /// コンストラクタ<see cref="World"/>
	 /// </summary>
	World();	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~World();	
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();	
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="deltaTime">1秒</param>
	void Update(float deltaTime);	
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="renderer">描画クラス</param>
	void Draw(Renderer& renderer);	
	/// <summary>
	/// 終了
	/// </summary>
	void Finalize();	
	/// <summary>
	/// カメラを追加
	/// </summary>
	/// <param name="camera">カメラのポインタ</param>
	void AddCamera(const CameraPtr& camera);	
	/// <summary>
	/// カメラのポインタを取得
	/// </summary>
	/// <returns>カメラのポインタ</returns>
	virtual ICamera& GetCamera() override;
	/// <summary>
	/// ステージを追加
	/// </summary>
	/// <param name="field">ステージのポインタ</param>
	void AddField(const FieldPtr& field);
	/// <summary>
	/// ステージのポインタを取得
	/// </summary>
	/// <returns>ステージのポインタ</returns>
	virtual IField& GetField() const override;
	/// <summary>
	/// アクターを追加する
	/// </summary>
	/// <param name="group">追加するグループ</param>
	/// <param name="actor">追加するアクターポインタ</param>
	virtual void AddActor(ActorGroup group, const ActorPtr& actor) override;
	/// <summary>
	/// アクターを検索する
	/// </summary>
	/// <param name="name">検索するアクターの名前</param>
	/// <returns>[true ActorPtr] : [false nullptr]</returns>
	virtual ActorPtr FindActor(const std::string& name) override;
	/// <summary>
	/// アクターを検索する
	/// </summary>
	/// <param name="group">検索するアクターのグループ</param>
	/// <param name="name">検索するアクターの名前</param>
	/// <returns>[true ActorPtr] : [false nullptr]</returns>
	virtual ActorPtr FindActor(ActorGroup group, const std::string& name) override;
	/// <summary>
	/// グループの親のポインタを取得する
	/// </summary>
	/// <param name="group">アクターのグループ</param>
	/// <returns>[true ActorPtr] : [false nullptr]</returns>
	virtual ActorPtr GetRoot(ActorGroup group) override;
	/// <summary>
	/// 全アクターにイベントメッセージを送信
	/// </summary>
	/// <param name="message">登録したイベントメッセージ</param>
	/// <param name="param">イベントと一緒に送る変数</param>
	virtual void SendEventMessage(EventMessage message, void* param = nullptr) override;
	/// <summary>
	 /// EventMessageを受け取る関数を登録 主にアクター以外が登録する
	 /// </summary>
	 /// <param name="listener">EventMessageを受け取る関数</param>
	void AddEventMessageListener(std::function<void(EventMessage, void*)> listener);
private:
	//!アクター管理クラス
	ActorManager actorManager;
	//!カメラのポインタ
	CameraPtr camera;
	//!ステージのポインタ
	FieldPtr field;
	//!リスナー用の関数
	std::function<void(EventMessage, void*)> listener;
};
