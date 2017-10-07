#pragma once

/**
 * @file ShapeType.h
 * @brief �����蔻��p�̊�{�`���`�t�@�C��
 * @author ���]
 * @date Unknown
 */

 /**
  * @enum ShapeType
  * �����蔻��p�̊�{�`��
  */
enum class ShapeType {
	//!��
	BoundingSphere,
	//!�J�v�Z��
	Capsule,
	//!����
	Line,
	//!���E�{�b�N�X(AABB)
	BoundingBox,
	//!�w�������E�{�b�N�X(OBB)
	OrientedBoundingBox,
	//!�`��̐�
	Max_Num
};