#pragma once

class Ray;
class Line;
class Capsule;
class BoundingSphere;
class HitInfo;

/**
 * @file Collision.h
 * @brief �����蔻��̊֐����܂Ƃ߂��N���X��`�t�@�C��
 * @author ���]
 * @date Unknown
 */

/*! @class Collision
 *   @brief �����蔻��̊֐����܂Ƃ߂��N���X
 */
class Collision {
public:

	/// <summary>
	/// �X�e�[�W�̂����蔻�������������
	/// </summary>
	/// <param name="modelID">�����蔻���ݒ肷�郂�f���̃n���h��</param>
	/// <param name="XDivNum">X�������̋�ԕ�����</param>
	/// <param name="YDivNum">Y�������̋�ԕ�����</param>
	/// <param name="ZDivNum">Z�������̋�ԕ�����</param>
	static void SetUpOctree(unsigned int modelID, int XDivNum = 32, int YDivNum = 8, int ZDivNum = 32);	
	/// <summary>
	/// ���Ƌ��̂����蔻��
	/// </summary>
	/// <param name="sphere1">��</param>
	/// <param name="sphere2">��</param>
	/// <param name="hitInfo">�Փˏ��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	static bool BoundingShpere_BoundingSphere(const BoundingSphere& sphere1, const BoundingSphere& sphere2, HitInfo& hitInfo);	
	/// <summary>
	/// ���Ɛ����̂����蔻��
	/// </summary>
	/// <param name="sphere">��</param>
	/// <param name="line">����</param>
	/// <param name="hitInfo">�Փˏ��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	static bool BoundingSphere_Line(const BoundingSphere& sphere, const Line& line, HitInfo& hitInfo);
	/// <summary>
	/// ���ƃJ�v�Z���̂����蔻��
	/// </summary>
	/// <param name="sphere">��</param>
	/// <param name="capsule">�J�v�Z��</param>
	/// <param name="hitInfo">�Փˏ��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	static bool BoundingSphere_Capsule(const BoundingSphere& sphere, const Capsule& capsule, HitInfo& hitInfo);
	/// <summary>
	/// �J�v�Z���ƃJ�v�Z���̂����蔻��
	/// </summary>
	/// <param name="capsule1">�J�v�Z��</param>
	/// <param name="capsule2">�J�v�Z��</param>
	/// <param name="hitInfo">�Փˏ��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	static bool Capsule_Capsule(const Capsule& capsule1, const Capsule& capsule2, HitInfo& hitInfo);
	/// <summary>
	/// �J�v�Z���Ɛ����̂����蔻��
	/// </summary>
	/// <param name="capsule">�J�v�Z��</param>
	/// <param name="line">����</param>
	/// <param name="hitInfo">�Փˏ��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	static bool Capsule_Line(const Capsule& capsule, const Line& line, HitInfo& hitInfo);
	/// <summary>
	/// �����Ɛ����̂����蔻��
	/// </summary>
	/// <param name="line1">����</param>
	/// <param name="line2">����</param>
	/// <param name="hitInfo">�Փˏ��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	static bool Line_Line(const Line& line1, const Line& line2, HitInfo& hitInfo);
	/// <summary>
	/// �X�e�[�W�Ɛ����̂����蔻��
	/// </summary>
	/// <param name="modelID">�����蔻����s�����f���̃n���h��</param>
	/// <param name="line">����</param>
	/// <param name="hitInfo">�Փˏ��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	static bool Octree_Line(int modelID, const Line& line, HitInfo& hitInfo);
	/// <summary>
	/// �X�e�[�W�Ƌ��̂����蔻��
	/// </summary>
	/// <param name="modelID">�����蔻����s�����f���̃n���h��</param>
	/// <param name="sphere">��</param>
	/// <param name="hitInfo">�Փˏ��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	static bool Octree_BoundingSphere(int modelID, const BoundingSphere& sphere, HitInfo& hitInfo);
	/// <summary>
	/// �X�e�[�W�ƃJ�v�Z���̂����蔻��
	/// </summary>
	/// <param name="modelID">�����蔻����s�����f���̃n���h��</param>
	/// <param name="capsule">�J�v�Z��</param>
	/// <param name="hitInfo">�Փˏ��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	static bool Octree_Capsule(int modelID, const Capsule& capsule, HitInfo& hitInfo);

};