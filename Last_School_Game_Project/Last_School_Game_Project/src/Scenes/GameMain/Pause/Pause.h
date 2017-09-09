#pragma once

/**
* @file Pause.h
* @brief ポーズの処理をまとめたクラス定義ファイル
* @author 阿曽
* @date 2017/3/23
*/


class Renderer;
enum class EventMessage;
enum class Scene;
class IWorld;
#include"Utility/Assets.h"
#include"Math/Vector2/Vector2.h"
#include"Utility/Color/Color.h"
#include<array>

/*! @class Pause
*   @brief  ポーズ
*/
class Pause {
public:
	/*! @struct PauseItem
	 * @brief  ポーズで表示する情報をまとめた構造体
	 */
	struct PauseItem {
		//!定義したテクスチャ
		Assets::Texture texture;
		//!座標
		Vector2 position;
		//!中心座標
		Vector2 center;
		//!補間で使う大きさ比
		float t_scale;
		//!色
		Color color;

		/**
		 * @brief デフォルトコンストラクタ
		 */
		PauseItem(){}
		/**
		* @brief コンストラクタ
		* @param texture 定義したテクスチャ
		* @param position 座標
		* @param center 中心座標
		* @param t_scale 補間で使う大きさ比
		* @param color 色
		*/
		PauseItem(Assets::Texture texture, const Vector2& position = Vector2::Zero, const Vector2& center = Vector2(128,27), float t_scale = 0.0f, const Color& color = Color::White)
			: texture(texture)
			, position(position)
			, center(center)
			, t_scale(t_scale)
			, color(color){

		}

	};

public:	
	/**
	 * @brief コンストラクタ
	 * @param world ワールドポインタ
	 */
	explicit Pause(IWorld& world);
	/**
	* @brief デストラクタ
	*/
	~Pause();

	/**
	* @brief 初期化
	*/
	void Initialize();
	/**
	* @brief 更新
	* @param deltaTime １秒
	*/
	void Update(float deltaTime);
	/**
	* @brief 描画
	* @param renderer 描画クラス
	*/
	void Draw(Renderer& renderer)const;
	/**
	* @brief 終了
	*/
	void Finalize();
	/**
	* @brief イベントメッセージを受け取る
	* @param message 登録したイベントメッセージ
	* @param param イベントと一緒に送る変数
	*/
	void HandleMessage(EventMessage message, void* param);

	/**
	* @brief 選んだシーンを取得
	* @return 選んだシーン
	*/
	Scene GetSelectScene() const;
	/**
	* @brief シーンが終了したか判定
	* @return [true 終了した] : [false まだ終了していない]
	*/
	bool IsEnd() const;

private:
	/**
	* @enum SelectContent
	* ポーズの項目定義
	*/
	enum SelectContent {
		//!ポーズをやめる
		BackToGame_ = 0,
		//!操作方法
		Manual_,
		//!ゲームをもう一度やり直す
		Continue_,
		//!タイトルへ移行
		Title_,
		//最大数
		Max_Num
	};


private:

	//!ワールドポインタ
	IWorld& world;
	//!選んだシーン
	Scene selectScene;
	//!シーンが終了したか判定用
	bool isEnd;
	//!選んでいる項目（シーン）
	int selectContaint;
	//!1フレーム前のコントローラーのスティック入力
	float prevInput;
	//!現在のコントローラーのスティック入力
	float curInput;
	//!ポーズで表示する情報をまとめた配列
	std::array<PauseItem, SelectContent::Max_Num> pauseItems;
};