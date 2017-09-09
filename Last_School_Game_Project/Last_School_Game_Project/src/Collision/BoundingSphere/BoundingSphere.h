#pragma once

#include"Math/Vector3/Vector3.h"
class Matrix4;
class HitInfo;
#include"Collision/ShapeBase.h"

/**
 * @file BoundingSphere.h
 * @brief �����蔻��̋���`�t�@�C��
 * @author ���]
 * @date Unknown
 */


/*! @class BoundingSphere
 *   @brief  �����蔻��̋�
 */
class BoundingSphere : public ShapeBase {
public:	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="center">���S���W</param>
	/// <param name="radius">���a</param>
	BoundingSphere(const Vector3& center, float radius);	
	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	/// <param name="radius">���a</param>
	explicit BoundingSphere(float radius = 0.0f);

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
	//!���S���W
	Vector3 center;
	//!���a
	float radius;
};
