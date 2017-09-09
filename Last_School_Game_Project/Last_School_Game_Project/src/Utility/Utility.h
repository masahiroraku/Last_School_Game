#pragma once

/**
 * @file Utility.h
 * @brief �ėp�I�Ȋ֐����܂Ƃ߂��N���X
 * @author ���]
 * @date 2016/8/14
 */

#include"Math/Convert/Convert.h"
#include<string>

 /*! @class Utility
 *   @brief �ėp�I�Ȋ֐����܂Ƃ߂��N���X
 */
class Utility {
public:	
	/// <summary>
	/// ���l�𕶎���ɕϊ�����
	/// </summary>
	/// <param name="value">�ϊ����������l</param>
	/// <returns>�ϊ�����������</returns>
	template<typename T>
	static std::string ToString(const T& value) {
		return std::to_string(value);
	}
	 /// <summary>
	 /// ���[���h���W���X�N���[�����W�ɕϊ�����
	 /// </summary>
	 /// <param name="worldPosition">���[���h���W</param>
	 /// <returns>�X�N���[�����W</returns>
	static Vector2 WorldPosToScreenPos(const Vector3& worldPosition) {
		VECTOR screenPosision = ConvWorldPosToScreenPos(Convert::ToVECTOR(worldPosition));
		return Convert::ToVector2(screenPosision);
	}
	 /// <summary>
	 /// ��ʏ��3�������W��\������@�f�o�b�N�p
	 /// </summary>
	 /// <param name="position">���W</param>
	static void PrintDxVector3(const Vector3& position) {
		printfDx("X = %0.2f, Y = %0.2f, Z = %0.2f\n", position.x, position.y, position.z);
	}

};