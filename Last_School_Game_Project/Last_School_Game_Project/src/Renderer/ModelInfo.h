#pragma once

/**
 * @file ModelInfo.h
 * @brief モデル情報をまとめた構造体の定義ファイル
 * @author 阿曽
 * @date Unknown
 */

/*! @struct ModelInfo
 *	@brief モデル情報をまとめた構造体
 */
struct ModelInfo {
	//!描画するモデルのID
	int modelID;
	//!アニメーションID
	int animeID;
	//!前回のアニメーションID
	int previousAnimeID;
	//!今再生しているアニメーション番号
	int nowPlayAnimeIndex;
	//!前回再生していたアニメーション番号
	int previousPlayAnimeIndex;
	//!補間アニメーション時間
	float lerpTime;
	//!アニメーションの参照元のモデルID
	int sourceAnimeModelID;
	/**
	 * @brief コンストラクタ
	 */
	ModelInfo() {
		Initialize();
	}	
	/**
	 * @brief 初期化
	 */
	void Initialize() {
		modelID = -1;
		animeID = -1;
		previousAnimeID = -1;
		nowPlayAnimeIndex = -1;
		previousPlayAnimeIndex = -1;
		lerpTime = 0.0f;
		sourceAnimeModelID = -1;
	}	
};
