#pragma once

/**
 * @file Assets.h
 * @brief ゲーム内で使用するアセットの定義ファイル
 * @author 阿曽
 * @date 2017/2/23
 */

 //! Assetsの名前空間
namespace Assets {
	/**
	 * @enum Model
	 * 使用するモデルの定義
	 */	
	enum class Model {
		//!プレイヤー
		Player,
		//!ボス
		Boss,
		//!ステージ
		Stage,
		//!あたり判定用のステージ
		CollisionStage,
	};
	/**
	* @enum Animation
	* 使用するアニメーションの定義
	*/
	enum class Animation {
		//!プレイヤーのアニメーション
		Player,
		//ボスのアニメーション
		Boss
	};
	/**
	* @enum Texture
	* 使用するテクスチャの定義
	*/
	enum class Texture {
		//!フェード用
		Fade,
		//!ボスモデルのテクスチャ
		BossTexture,
		//!ゲームメインで使うUI　：　ロックオン
		GameMainUI_RockOn,
	};
	/**
	 * @enum Font
	 * 使用するフォントの定義
	 */
	enum class Font {
		//!デフォルトのフォント　MS　ゴシック
		Default
	};
	/**
	* @enum Font
	* 使用するエフェクトの定義
	*/
	enum class Effect {
	};
	/**
	 * @enum Sound
	 * 使用する音楽の定義 BGM & SE
	 */
	enum class Sound {
	};
}