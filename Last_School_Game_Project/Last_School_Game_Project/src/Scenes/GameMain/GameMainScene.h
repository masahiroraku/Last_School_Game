#pragma once

/**
 * @file GameMainScene.h
 * @brief ゲームメインシーン定義ファイル
 * @author 阿曽
 * @date 2017/3/23
*/


#include "Scenes/Base/IScene.h"
#include"World/IWorld.h"
#include"World/WorldPtr.h"
#include"Pause/Pause.h"
#include"Utility/Timer/Timer.h"

class Renderer;
enum class EventMessage;

/*! @class GameMainScene
 *   @brief  ゲームメインシーン
 */
class GameMainScene : public IScene {
public:
	/**
	* @brief コンストラクタ
	* @param world ワールドポインタ
	*/
	explicit GameMainScene(WorldPtr& world);
	/**
	* @brief デストラクタ
	*/
	virtual ~GameMainScene();
	/**
	* @brief アセットを読み込む
	*/
	virtual void LoadAssets() override;
	/**
	* @brief 初期化
	*/
	virtual void Initialize() override;
	/**
	* @brief 更新
	* @param deltaTime １秒
	*/
	virtual void Update(float deltaTime)override;
	/**
	* @brief 描画
	*/
	virtual void Draw() const override;
	/**
	* @brief シーンが終了か判定
	* @return [true 終了] : [false まだ終了していない]
	*/
	virtual bool IsEnd() const override;
	/**
	* @brief 次に移動するシーンを取得
	* @return 次に移動するシーン
	*/
	virtual Scene Next()const override;
	/**
	* @brief 終了
	*/
	virtual void Finalize() override;
	/**
	* @brief フェードする
	* @param alpha アルファ値
	*/
	virtual void DrawFade(float alpha) const override;

private:
	/**
	* @brief イベントメッセージを受け取る
	* @param message 登録したイベントメッセージ
	* @param param イベントと一緒に送る変数
	*/
	void HandleMessage(EventMessage message, void* param);

private:

private:
	//!ワールドポインタ
	WorldPtr world;
	//!描画クラス
	Renderer* renderer;
	//!シーンが終了したか判定用
	bool isEnd_;
	//!ポーズ中か判定用
	bool pause;
	//!ポーズシーン
	Pause pauseScene;
};
