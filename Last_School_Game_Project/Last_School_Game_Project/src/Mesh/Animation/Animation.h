#pragma once

#include<string>

/**
 * @file Animation.h
 * @brief �RD���f���̃A�j���[�V�����Ǘ��N���X��`�t�@�C��
 * @author ���]
 * @date 2017/1/31
 */


 /*! @class Animation
 *   @brief  �RD���f���̃A�j���[�V�����Ǘ��N���X
 */
class Animation {
public:	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="motion">�ŏ��ɍĐ�����A�j���[�V����</param>
	explicit Animation(int motion);	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Animation();
	
	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name="dt">�P�b</param>
	void Update(float dt);	
	/// <summary>
	/// �A�j���[�V������ύX����
	/// </summary>
	/// <param name="motion">�Đ�����A�j���[�V�����ԍ�</param>
	void ChangeMotion(int motion);	
	/// <summary>
	/// �Đ����Ă���A�j���[�V�������Ԃ��擾����
	/// </summary>
	/// <returns>�Đ����Ă���A�j���[�V��������</returns>
	float GetMotionTime() const;	
	/// <summary>
	/// ���Đ����Ă���A�j���[�V�����ԍ����擾����
	/// </summary>
	/// <returns>���Đ����Ă���A�j���[�V�����ԍ�</returns>
	int GetMotion() const;	
	/// <summary>
	/// �Đ����Ă���A�j���[�V�����̏I�����Ԃ��擾����
	/// </summary>
	/// <returns>�Đ����Ă���A�j���[�V�����̏I������</returns>
	float GetEndTime() const;
	
	/// <summary>
	///�@�Q�Ƃ���A�j���[�V������ID�E�n���h����ݒ肷��
	/// </summary>
	/// <param name="animeID">�Q�Ƃ���A�j���[�V������ID�E�n���h��</param>
	void SetAnimeID(int animeID);
	int GetAnimeID()const;

private:
	//!�A�j���[�V������ID�E�n���h��
	int animeID;
	//!�Đ����Ă���A�j���[�V�����ԍ�
	int motion;
	//!�A�j���[�V�����^�C��
	float motionTimer;

};