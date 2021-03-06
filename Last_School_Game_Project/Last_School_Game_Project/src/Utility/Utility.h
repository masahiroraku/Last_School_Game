#pragma once

/**
 * @file Utility.h
 * @brief 汎用的な関数をまとめたクラス
 * @author 阿曽
 * @date 2016/8/14
 */

#include"Math/Convert/Convert.h"
#include<string>

 /*! @class Utility
 *   @brief 汎用的な関数をまとめたクラス
 */
class Utility {
public:	
	/// <summary>
	/// 数値を文字列に変換する
	/// </summary>
	/// <param name="value">変換したい数値</param>
	/// <returns>変換した文字列</returns>
	template<typename T>
	static std::string ToString(const T& value) {
		return std::to_string(value);
	}
	 /// <summary>
	 /// ワールド座標をスクリーン座標に変換する
	 /// </summary>
	 /// <param name="worldPosition">ワールド座標</param>
	 /// <returns>スクリーン座標</returns>
	static Vector2 WorldPosToScreenPos(const Vector3& worldPosition) {
		VECTOR screenPosision = ConvWorldPosToScreenPos(Convert::ToVECTOR(worldPosition));
		return Convert::ToVector2(screenPosision);
	}
	 /// <summary>
	 /// 画面上に3次元座標を表示する　デバック用
	 /// </summary>
	 /// <param name="position">座標</param>
	static void PrintDxVector3(const Vector3& position) {
		printfDx("X = %0.2f, Y = %0.2f, Z = %0.2f\n", position.x, position.y, position.z);
	}
	static void DrawXYZ(const Matrix4& matrix, const Vector3& position = Vector3::Zero) {
		Vector3 p;
		if (position.Length() <= 0.0f) {
			p = matrix.GetPosition();
		}
		else {
			p = position;
		}
		DrawLine3D(Convert::ToVECTOR(p + Vector3(0,1,0)), Convert::ToVECTOR((p + Vector3(0,1,0) + -matrix.GetFront())), GetColor(0, 0, 255));
		DrawLine3D(Convert::ToVECTOR(p + Vector3(0,1,0)), Convert::ToVECTOR((p + Vector3(0,1,0) + matrix.GetLeft())), GetColor(255, 0, 0));
		DrawLine3D(Convert::ToVECTOR(p + Vector3(0,1,0)), Convert::ToVECTOR((p + Vector3(0,1,0) + matrix.GetUp())), GetColor(0, 255, 0));
	}

};