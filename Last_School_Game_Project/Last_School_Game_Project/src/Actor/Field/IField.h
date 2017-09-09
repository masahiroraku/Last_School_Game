#pragma once

class Line;
class BoundingSphere;
class Capsule;
class HitInfo;

/**
 * @file IField.h
 * @brief �t�B�[���h�̃C���^�[�t�F�[�X��`�t�@�C��
 * @author ���]
 * @date Unknown
 */

 /*! @class IField
 *   @brief �t�B�[���h�̃C���^�[�t�F�[�X
 */
class IField {
public:	
	/// <summary>
	/// ���z�f�X�g���N�^
	/// </summary>
	virtual ~IField() {}	
	/// <summary>
	/// �����Ƃ����蔻����s��
	/// </summary>
	/// <param name="line">����</param>
	/// <param name="hitInfo">�Փˏ��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	virtual bool Collision(const Line& line, HitInfo& hitInfo) = 0;
	/// <summary>
	/// ���Ƃ����蔻����s��
	/// </summary>
	/// <param name="sphere">��</param>
	/// <param name="hitInfo">�Փˏ��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	virtual bool Collision(const BoundingSphere& sphere, HitInfo& hitInfo) = 0;
	/// <summary>
	/// �J�v�Z���Ƃ����蔻����s��
	/// </summary>
	/// <param name="capsule">�J�v�Z��</param>
	/// <param name="hitInfo">�Փˏ��</param>
	/// <returns>[true �Փ˂���: false �Փ˂��Ă��Ȃ�]</returns>
	virtual bool Collision(const Capsule& capsule, HitInfo& hitInfo) = 0;
};