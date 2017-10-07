#pragma once

#include<string>

/**
 * @file Animation.h
 * @brief ３Dモデルのアニメーション管理クラス定義ファイル
 * @author 阿曽
 * @date 2017/1/31
 */


 /*! @class Animation
 *   @brief  ３Dモデルのアニメーション管理クラス
 */
class Animation {
public:	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="motion">最初に再生するアニメーション</param>
	explicit Animation(int motion);	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Animation();
	
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="dt">１秒</param>
	void Update(float dt);	
	/// <summary>
	/// アニメーションを変更する
	/// </summary>
	/// <param name="motion">再生するアニメーション番号</param>
	void ChangeMotion(int motion);	
	/// <summary>
	/// 再生しているアニメーション時間を取得する
	/// </summary>
	/// <returns>再生しているアニメーション時間</returns>
	float GetMotionTime() const;	
	/// <summary>
	/// 今再生しているアニメーション番号を取得する
	/// </summary>
	/// <returns>今再生しているアニメーション番号</returns>
	int GetMotion() const;	
	/// <summary>
	/// 再生しているアニメーションの終了時間を取得する
	/// </summary>
	/// <returns>再生しているアニメーションの終了時間</returns>
	float GetEndTime() const;
	
	/// <summary>
	///　参照するアニメーションのID・ハンドルを設定する
	/// </summary>
	/// <param name="animeID">参照するアニメーションのID・ハンドル</param>
	void SetAnimeID(int animeID);
	int GetAnimeID()const;

private:
	//!アニメーションのID・ハンドル
	int animeID;
	//!再生しているアニメーション番号
	int motion;
	//!アニメーションタイム
	float motionTimer;

};