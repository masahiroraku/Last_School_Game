#pragma once

#include"Collision/ShapeBase.h"
#include"Math/Vector3/Vector3.h"
#include"Math/Matrix4/Matrix4.h"
class BoundingBox;

class OrientedBoundingBox : public ShapeBase {
public:
	OrientedBoundingBox();
	OrientedBoundingBox(const Vector3& position, const Vector3& extents, const Vector3& axis_x, const Vector3& axis_y, const Vector3& axis_z);
	explicit OrientedBoundingBox(const BoundingBox& aabb);
	/// <summary>
	/// �����蔻����s���֐�
	/// </summary>
	/// <param name="shape">�����蔻��p�̌`��</param>
	/// <param name="hitInfo">�����蔻����</param>
	/// <returns></returns>
	bool Intersect(const ShapeBase& shape, HitInfo& hitInfo);

	/// <summary>
	/// ���W�ړ�
	/// </summary>
	/// <param name="position">���W</param>
	/// <returns>�ړ������`��|�C���^</returns>
	virtual ShapePtr Translate(const Vector3& position) const = 0;
	/// <summary>
	/// ���W�ϊ�
	/// </summary>
	/// <param name="matrix">�p���s��</param>
	/// <returns>���W�ϊ����ꂽ�`��|�C���^</returns>
	virtual ShapePtr Transform(const Matrix4& matrix) const = 0;

	/// <summary>
	/// �`��̎�ނ��擾
	/// </summary>
	/// <returns>�`��̎��</returns>
	virtual ShapeType GetShapeType() const { return ShapeType::Max_Num; }

	/// <summary>
	/// ���Ƃ̂����蔻��
	/// </summary>
	/// <param name="shape">���̃|�C���^</param>
	/// <param name="hitInfo">�����蔻����</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	virtual bool Collide_BoundingSphere(const ShapeBase& shape, HitInfo& hitInfo);

	/// <summary>
	/// �J�v�Z���Ƃ̂����蔻��
	/// </summary>
	/// <param name="shape">�J�v�Z���̃|�C���^</param>
	/// <param name="hitInfo">�����蔻��̏��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	virtual bool Collide_Capsule(const ShapeBase& shape, HitInfo& hitInfo);

	/// <summary>
	/// �����Ƃ̂����蔻��
	/// </summary>
	/// <param name="shape">�����̃|�C���^</param>
	/// <param name="hitInfo">�����蔻��̏��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	virtual bool Collide_Line(const ShapeBase& shape, HitInfo& hitInfo);

	virtual bool Collide_BoundingBox(const ShapeBase& shape, HitInfo& hitInfo);
	virtual bool Collide_OrientedBoundingBox(const ShapeBase& shape, HitInfo& hitInfo);
	/// <summary>
	/// �����蔻������C���[�t���[���ŕ`��
	/// </summary>
	virtual void Draw() const;

public:
	// OBB����^�[�Q�b�g�ɑ΂��Ĉ�ԋ߂����W��Ԃ�
	Vector3 ClosestPoint(const Vector3& target) const;
	// ���[���h���W�ɕϊ�����s����쐬
	Matrix4 LocalToWorld() const;
	// ���[�J�����W�ɕϊ�����s����쐬
	Matrix4 WorldToLocal() const;

	// �R�[�i�[�̍��W���擾
	Vector3 CornerPoint(int cornerIndex) const;
	// �T�C�Y���擾
	Vector3 Size() const;
	// ���S���W���擾
	Vector3 Center() const;

public:
	Vector3 position;
	Vector3 extents;
	Vector3 axis[3];
};