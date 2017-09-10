#pragma once

/**
 * @file ILight.h
 * @brief ３D空間の照明クラスを抽象化したクラス定義ファイル
 * @author 阿曽
 * @date 2017/9/9
 */

class Vector3;

 /*! @class ILight
 *   @brief ３D空間の照明クラスを抽象化したクラス
 */
class ILight
{
public:
	/// <summary>
	///　仮想デストラクタ
	/// </summary>
	virtual ~ILight() {}
	/// <summary>
	/// 照明の座標を取得する
	/// </summary>
	/// <returns>照明の座標</returns>
	virtual Vector3 GetPosition() const = 0;
	/// <summary>
	/// 照明の方向を取得する
	/// </summary>
	/// <returns>照明の方向</returns>
	virtual Vector3 GetDirection() const = 0;
	/// <summary>
	/// 照明の座標を設定
	/// </summary>
	/// <param name="position">座標</param>
	virtual void SetPosition(const Vector3& position) = 0;
	/// <summary>
	/// 照明の方向を設定
	/// </summary>
	/// <param name="direction">方向</param>
	virtual void SetDirection(const Vector3& direction) = 0;


};

