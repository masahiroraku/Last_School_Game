#pragma once

#include"Math/Vector3/Vector3.h"
#include"Collision/ShapeBase.h"

class BoundingBox : public ShapeBase {
public:
	BoundingBox();
	BoundingBox(const Vector3& min, const Vector3& max);
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
	
	virtual bool Collide_BoundingBox(const ShapeBase& shape, HitInfo& hitInfo) override;
	virtual bool Collide_OrientedBoundingBox(const ShapeBase& shape, HitInfo& hitInfo) override;

	/// <summary>
	/// �����蔻������C���[�t���[���ŕ`�悷��
	/// </summary>
	virtual void Draw() const override;

public:
	// BoundingBox����^�[�Q�b�g�ɑ΂��Ĉ�ԋ߂����W��Ԃ�
	Vector3 ClosestPoint(const Vector3& target) const;
	// �R�[�i�[�̍��W���擾
	Vector3 CornerPoint(int cornerIndex) const;
	// �T�C�Y�̎擾
	Vector3 Size() const;
	// ���S���W�̎擾
	Vector3 Center() const;

public:
	Vector3 min;
	Vector3 max;

};