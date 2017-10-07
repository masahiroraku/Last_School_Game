#pragma once

#include"Math/Matrix4/Matrix4.h"
#include"../Animation/Animation.h"
#include"Renderer/ModelInfo.h"
class Renderer;
#include"Utility/Assets.h"

/**
 * @file SkinningMesh.h
 * @brief �A�j���[�V��������RD���f����`�t�@�C��
 * @author ���]
 * @date 2017/1/23
 */

/*! @class SkinningMesh
 *   @brief  �A�j���[�V��������RD���f��
 */
class SkinningMesh {
public:	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="modelName">�o�^�������O</param>
	/// <param name="animationID">�o�^�������O</param>
	/// <param name="isDeplicate">�������邩�H</param>
	SkinningMesh(Assets::Model modelID, Assets::Animation animationID, bool isDeplicate = false);	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~SkinningMesh();
	
	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name="dt">�P�b</param>
	void Update(float dt);	

	/// <summary>
	/// �`��
	/// </summary>
	/// <param name="renderer">�`��N���X</param>
	/// <param name="world">�p���s��i���[���h���W�j</param>
	void Draw(Renderer& renderer, const Matrix4& world) const;	
	/// <summary>
	/// �A�j���[�V������ς���
	/// </summary>
	/// <param name="motion">�A�j���[�V�����ԍ�</param>
	void ChangeMotion(int motion);	
	/// <summary>
	/// �f�B�t���[�Y�e�N�X�`����ς���
	/// </summary>
	/// <param name="textureID">�o�^�������O</param>
	/// <param name="materialNumber">�ύX����}�e���A���̔ԍ�</param>
	void ChangeTexture(Assets::Texture textureID, int materialNumber);
	
	/// <summary>
	/// ���f��ID�E�n���h�����擾
	/// </summary>
	/// <returns>���f��ID�E�n���h��</returns>
	int GetModelHandle() const;

	/// <summary>
	/// �A�j���[�V�����̍Đ����I��������H
	/// </summary>
	/// <returns>
	/// �I���Ftrue �Đ����F false
	/// </returns>
	bool IsEndMotion() const;
	/// <summary>
	/// �A�j���[�V�����^�C�}�[���擾����
	/// </summary>
	/// <returns>�Đ�����</returns>
	float GetMotionTime() const;
	/// <summary>
	/// �A�j���[�V�����̏I�����Ԃ��擾����
	/// </summary>
	/// <returns>�I������</returns>
	float GetMotionEndTime() const;
	
	/// <summary>
	/// ���f�����폜
	/// </summary>
	void Clear();

	Vector3 GetBonePosition(int boneIndex) const;
	Matrix4 GetBoneLocalMatrix(int boneIndex) const;
	Matrix4 GetBoneWorldMatrix(int boneIndex) const;


	//-------------�R�s�[�֎~---------------
public:
	SkinningMesh(const SkinningMesh& other) = delete;
	SkinningMesh& operator = (const SkinningMesh& other) = delete;


private:
	//!�������邩�ǂ����̃t���O
	bool isDeplicate;
	//!�A�j���[�V�����N���X
	Animation animation;
	//!���f�����
	ModelInfo modelInfo;
};