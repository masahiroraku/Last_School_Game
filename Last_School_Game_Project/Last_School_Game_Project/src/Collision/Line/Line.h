#pragma once

#include"Math\Vector3\Vector3.h"
#include"Utility\Color\Color.h"
class Matrix4;
class BoundingSphere;
class HitInfo;
class Vector2;
#include"Collision/ShapeBase.h"

/**
 * @file Line.h
 * @brief �����蔻��̐�����`�t�@�C��
 * @author ���]
 * @date Unknown
 */

/*! @class Line
 *   @brief  �����蔻��̐���
 */
class Line : public ShapeBase{
public:	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="p1">�n�_</param>
	/// <param name="p2">�I�_</param>
	Line(const Vector3& p1, const Vector3& p2);	
	/// <summary>
	/// �R���X�g���N�^ �}�E�X�|�C���^�̂����蔻��ݒ�
	/// </summary>
	/// <param name="screenPosition">�}�E�X�|�C���^�̍��W</param>
	/// <param name="screen">�X�N���[���s��</param>
	/// <param name="projection">���e�s��</param>
	/// <param name="view">�J�����s��</param>
	Line(const Vector2& screenPosition, const Matrix4& screen, const Matrix4& projection, const Matrix4& view);	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Line();	
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
	/// <summary>
	/// �F��t���Ă����蔻���`�悷��
	/// </summary>
	/// <param name="color">color</param>
	void Draw(const Color& color);

public:
	//!�n�_
	Vector3 p1;
	//!�I�_
	Vector3 p2;
	//!�n�_�ƏI�_�̃x�N�g��
	Vector3 vector;
};