#pragma once

/**
 * @file ILight.h
 * @brief �RD��Ԃ̏Ɩ��N���X�𒊏ۉ������N���X��`�t�@�C��
 * @author ���]
 * @date 2017/9/9
 */

class Vector3;

 /*! @class ILight
 *   @brief �RD��Ԃ̏Ɩ��N���X�𒊏ۉ������N���X
 */
class ILight
{
public:
	/// <summary>
	///�@���z�f�X�g���N�^
	/// </summary>
	virtual ~ILight() {}
	/// <summary>
	/// �Ɩ��̍��W���擾����
	/// </summary>
	/// <returns>�Ɩ��̍��W</returns>
	virtual Vector3 GetPosition() const = 0;
	/// <summary>
	/// �Ɩ��̕������擾����
	/// </summary>
	/// <returns>�Ɩ��̕���</returns>
	virtual Vector3 GetDirection() const = 0;
	/// <summary>
	/// �Ɩ��̍��W��ݒ�
	/// </summary>
	/// <param name="position">���W</param>
	virtual void SetPosition(const Vector3& position) = 0;
	/// <summary>
	/// �Ɩ��̕�����ݒ�
	/// </summary>
	/// <param name="direction">����</param>
	virtual void SetDirection(const Vector3& direction) = 0;


};

