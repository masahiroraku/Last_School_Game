#pragma once

/**
 * @file iostreamHelper.h
 * @brief テキストファイルから情報を読み取るための補助関数の定義ファイル
 * @author 阿曽
 * @date Unknown
 */

#include"Math/MathType.h"
#include<algorithm>
#include<iterator>
#include<vector>
#include<istream>


  /// <summary>
  /// Vector2の読み込み定義オペレーター
  /// </summary>
  /// <param name="in">std::istream</param>
  /// <param name="v">Vector2</param>
  /// <returns>次の行</returns>
inline std::istream& operator >> (std::istream& in, Vector2& v) {
	return in >> v.x >> v.y;
}

/// <summary>
/// Vector3の読み込み定義オペレーター
/// </summary>
/// <param name="in">std::istream</param>
/// <param name="v">Vector3</param>
/// <returns>次の行</returns>
inline std::istream& operator >> (std::istream& in, Vector3& v) {
	return in >> v.x >> v.y >> v.z;
}

/// <summary>
/// Matrix4の読み込み定義オペレーター
/// </summary>
/// <param name="in">std::istream</param>
/// <param name="m">Matrix4</param>
/// <returns>次の行</returns>
inline std::istream& operator >> (std::istream& in, Matrix4& m) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			in >> m.m[i][j];
		}
	}
	return in;
}
/// <summary>
/// Quaternionの読み込み定義オペレーター
/// </summary>
/// <param name="in">std::istream</param>
/// <param name="q">Quaternion</param>
/// <returns>次の行</returns>
inline std::istream& operator >> (std::istream& in, Quaternion& q) {
	return in >> q.x >> q.y >> q.z >> q.w;
}
/// <summary>
/// vectorの読み込み定義オペレーター
/// </summary>
/// <param name="in">std::istream</param>
/// <param name="vector">vector</param>
/// <returns>次の行</returns>
template <typename T>
inline std::istream& operator >> (std::istream& in, std::vector<T>& vector) {
	std::size_t n = 0;
	in >> n;
	std::copy_n(std::istream_iterator<T>(in), n, std::back_inserter(vector));
	return in;
}