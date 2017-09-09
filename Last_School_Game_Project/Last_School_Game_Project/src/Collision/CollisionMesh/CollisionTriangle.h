#pragma once

/**
 * @file CollisionTriangle.h
 * @brief �O�����̎O�p�`��`�t�@�C��
 * @author ���]
 * @date 2017/7/13
 */

#include"Math/Vector3/Vector3.h"
#include"Collision/BoundingSphere/BoundingSphere.h"
#include<array>
#include<DxLib.h>

/*! @class CollisionTriangle
 *   @brief  �O�����̎O�p�`
 */
class CollisionTriangle {
public:	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="p1">���_���W</param>
	/// <param name="p2">���_���W</param>
	/// <param name="p3">���_���W</param>
	CollisionTriangle(const Vector3& p1, const Vector3& p2, const Vector3& p3);
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="p1">���_���W</param>
	/// <param name="p2">���_���W</param>
	/// <param name="p3">���_���W</param>
	CollisionTriangle(const VECTOR& p1, const VECTOR& p2, const VECTOR& p3);	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~CollisionTriangle();	
	/// <summary>
	/// �O�p�`�̒��ɍ��W�������Ă��邩�ǂ���
	/// </summary>
	/// <param name="point">���W</param>
	/// <returns>
	/// [true ���ɓ����Ă��� : false ���ɓ����Ă��Ȃ�]
	/// </returns>
	bool IsInside(const Vector3& point)const;	
	/// <summary>
	/// ���Ɖ��̂����蔻��
	/// </summary>
	/// <param name="sphere">��</param>
	/// <param name="result">�ڐG�_</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	bool Collide_Edge_And_Sphere(const BoundingSphere& sphere, Vector3* result = nullptr);
private:
	//!�R���_
	std::array<VECTOR, 3> points;
};