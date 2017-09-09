#pragma once


class Renderer;
class Vector2;

/**
* @file HitPoint.h
* @brief キャラクターのヒットポイント定義ファイル
* @author 阿曽
* @date Unknown
*/

/*! @class HitPoint
*   @brief キャラクターのヒットポイント
*/
class HitPoint {
public:	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="maxHitPoint">最大HP</param>
	explicit HitPoint(int maxHitPoint);	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~HitPoint();	
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();	
	/// <summary>
	/// HPを増やす
	/// </summary>
	/// <param name="value">値</param>
	void AddValue(int value);	
	/// <summary>
	/// 最大HPを設定する
	/// </summary>
	/// <param name="maxValue">最大HP</param>
	void SetMaxHP(int maxValue);	
	/// <summary>
	/// 現在のHPを取得する
	/// </summary>
	/// <returns>現在のHP</returns>
	int GetHP()const;	
	/// <summary>
	/// 現在の最大HPを取得する
	/// </summary>
	/// <returns>現在の最大HP</returns>
	int GetMaxHP()const;	
	/// <summary>
	/// 死亡したかどうか　HPが0になったか
	/// </summary>
	/// <returns>
	/// [true 死亡した : false まだ生きている]
	/// </returns>
	bool IsDead()const;

private:
	//!現在の最大HP
	int maxHitPoint;
	//!現在のHP
	int hitPoint;
};