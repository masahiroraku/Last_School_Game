#pragma once

/**
 * @file CollisionMesh.h
 * @brief �����蔻��������Ȃ����b�V���t�@�C��
 * @author ���]
 * @date 2017/7/13
 */

#include"Math/Vector3/Vector3.h"
#include"Collision/Line/Line.h"
#include"Collision/BoundingSphere/BoundingSphere.h"

/*! @class�@CollisionMesh 
 *  @brief  �����蔻��������Ȃ����b�V��
 */
class CollisionMesh {
public:	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="modelHandle">�����蔻����s�����f���̃n���h��</param>
	CollisionMesh(int modelHandle);	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~CollisionMesh();	
	/// <summary>
	/// �����Ƃ����蔻����s��
	/// </summary>
	/// <param name="line">����</param>
	/// <param name="point">�ڐG�_</param>
	/// <param name="normal">�@���x�N�g��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	bool Collide_Line(const Line& line, Vector3* point = nullptr, Vector3* normal = nullptr)const;	
	/// <summary>
	/// ���Ƃ����蔻����s��
	/// </summary>
	/// <param name="sphere">��</param>
	/// <param name="result">�ڐG�_</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	bool Collide_Sphere(const BoundingSphere& sphere, Vector3* result = nullptr) const;

private:
	//!�����蔻����s�����f���̃n���h��
	int modelHandle;
};