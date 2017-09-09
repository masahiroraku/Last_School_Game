#pragma once

#include"Math/Vector3/Vector3.h"
#include"Math/Matrix4/Matrix4.h"
#include"Collision/ShapeBase.h"

/**
 * @file Capsule.h
 * @brief �����蔻��̃J�v�Z����`�t�@�C��
 * @author ���]
 * @date Unknown
 */

/*! @class Capsule
 *  @brief �����蔻��̃J�v�Z��
 */
class Capsule : public ShapeBase {
public:	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="p1">�n�_</param>
	/// <param name="p2">�I�_</param>
	/// <param name="radius">���a</param>
	Capsule(const Vector3& p1, const Vector3& p2, float radius);	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Capsule();
	/// <summary>
	/// ���s�ړ�������
	/// </summary>
	/// <param name="position">�ړ���</param>
	/// <returns>���s�ړ����������蔻��̃|�C���^</returns>
	virtual ShapePtr Translate(const Vector3& position) const override;
	/// <summary>
	/// ���W�ϊ�������
	/// </summary>
	/// <param name="matrix">�s��</param>
	/// <returns>���W�ϊ����������蔻��̃|�C���^</returns>
	virtual ShapePtr Transform(const Matrix4& matrix) const	override;
	/// <summary>
	/// �����蔻��̌`��̎�ނ��擾����
	/// </summary>
	/// <returns>�����蔻��̌`��̎��</returns>
	virtual ShapeType GetShapeType() const override;
	/// <summary>
	/// ���Ƃ����蔻����s��
	/// </summary>
	/// <param name="shape">��</param>
	/// <param name="hitInfo">�Փˏ��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	virtual bool Collide_BoundingSphere(const ShapeBase& shape, HitInfo& hitInfo) override;
	/// <summary>
	/// �J�v�Z���Ƃ����蔻����s��
	/// </summary>
	/// <param name="shape">��</param>
	/// <param name="hitInfo">�Փˏ��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	virtual bool Collide_Capsule(const ShapeBase& shape, HitInfo& hitInfo)override;
	/// <summary>
	/// �����Ƃ����蔻����s��
	/// </summary>
	/// <param name="shape">��</param>
	/// <param name="hitInfo">�Փˏ��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	virtual bool Collide_Line(const ShapeBase& shape, HitInfo& hitInfo)override;
	/// <summary>
	/// �����蔻������C���[�t���[���ŕ`�悷��
	/// </summary>
	virtual void Draw() const override;

public:
	//!�n�_
	Vector3 p1;
	//!�I�_
	Vector3 p2;
	//!�n�_�ƏI�_�̃x�N�g��
	Vector3 vector;
	//!���a
	float radius;
};