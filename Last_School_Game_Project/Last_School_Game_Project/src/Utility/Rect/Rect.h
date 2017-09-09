#pragma once

/**
 * @file Rect.h
 * @brief ��`�̒�`�t�@�C��
 * @author ��|
 * @date 2016/6/10
 */

 /*! @class Rect
 *   @brief  ��`
 */
class Rect {
public:
	 /// <summary>
	 /// �R���X�g���N�^<see cref="Rect"/>
	 /// </summary>
	 /// <param name="left">�����x���W</param>
	 /// <param name="top">�����y���W</param>
	 /// <param name="right">�E����x���W</param>
	 /// <param name="bottom">�E����y���W</param>
	Rect(float left = 0.0f, float top = 0.0f, float right = 1.0f, float bottom = 1.0f)
		: left(left)
		, top(top)
		, right(right)
		, bottom(bottom) {
	}
public:
	//!�����x���W
	float left;
	//!�����y���W
	float top;
	//!�E����x���W
	float right;
	//!�E����y���W
	float bottom;
};