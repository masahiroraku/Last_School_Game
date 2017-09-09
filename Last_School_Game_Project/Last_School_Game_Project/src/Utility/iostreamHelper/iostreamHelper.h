#pragma once

/**
 * @file iostreamHelper.h
 * @brief �e�L�X�g�t�@�C���������ǂݎ�邽�߂̕⏕�֐��̒�`�t�@�C��
 * @author ���]
 * @date Unknown
 */

#include"Math/MathType.h"
#include<algorithm>
#include<iterator>
#include<vector>
#include<istream>


  /// <summary>
  /// Vector2�̓ǂݍ��ݒ�`�I�y���[�^�[
  /// </summary>
  /// <param name="in">std::istream</param>
  /// <param name="v">Vector2</param>
  /// <returns>���̍s</returns>
inline std::istream& operator >> (std::istream& in, Vector2& v) {
	return in >> v.x >> v.y;
}

/// <summary>
/// Vector3�̓ǂݍ��ݒ�`�I�y���[�^�[
/// </summary>
/// <param name="in">std::istream</param>
/// <param name="v">Vector3</param>
/// <returns>���̍s</returns>
inline std::istream& operator >> (std::istream& in, Vector3& v) {
	return in >> v.x >> v.y >> v.z;
}

/// <summary>
/// Matrix4�̓ǂݍ��ݒ�`�I�y���[�^�[
/// </summary>
/// <param name="in">std::istream</param>
/// <param name="m">Matrix4</param>
/// <returns>���̍s</returns>
inline std::istream& operator >> (std::istream& in, Matrix4& m) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			in >> m.m[i][j];
		}
	}
	return in;
}
/// <summary>
/// Quaternion�̓ǂݍ��ݒ�`�I�y���[�^�[
/// </summary>
/// <param name="in">std::istream</param>
/// <param name="q">Quaternion</param>
/// <returns>���̍s</returns>
inline std::istream& operator >> (std::istream& in, Quaternion& q) {
	return in >> q.x >> q.y >> q.z >> q.w;
}
/// <summary>
/// vector�̓ǂݍ��ݒ�`�I�y���[�^�[
/// </summary>
/// <param name="in">std::istream</param>
/// <param name="vector">vector</param>
/// <returns>���̍s</returns>
template <typename T>
inline std::istream& operator >> (std::istream& in, std::vector<T>& vector) {
	std::size_t n = 0;
	in >> n;
	std::copy_n(std::istream_iterator<T>(in), n, std::back_inserter(vector));
	return in;
}