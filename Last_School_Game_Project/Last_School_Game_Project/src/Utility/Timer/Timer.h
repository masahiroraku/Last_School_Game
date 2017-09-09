#pragma once
/**
 * @file Timer.h
 * @brief 秒数をカウントするクラスの定義ファイル
 * @author 阿曽
 * @date 2017/1/23
 */

 /*! @class Timer
 *   @brief  設定した秒数をカウントダウンするクラス
 */
class Timer {
public:	
	 /// <summary>
	 ///  コンストラクタ<see cref="Timer"/> 
	 /// </summary>
	 /// <param name="setTime">設定する秒数　1.0f = 1秒</param>
	explicit Timer(float setTime);	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Timer();	
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();	
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="deltaTime">１秒</param>
	void Update(float deltaTime);
	 /// <summary>
	 /// 0秒になったか判定
	 /// </summary>
	 /// <returns>
	 /// [true 0秒] : [false まだ0秒ではない]
	 /// </returns>
	bool IsTimeUp() const;
	 /// <summary>
	 /// 計測中の秒数を取得
	 /// </summary>
	 /// <returns>秒数</returns>
	float GetSecond() const;	
	 /// <summary>
	 /// 設定した秒数を取得
	 /// </summary>
	 /// <returns>設定した秒数</returns>
	float GetMaxTime() const;
private:	
	//!設定した秒数
	const float maxTime;
	//!カウントダウン用の変数
	float timer;
};