#pragma once

#include"Math/Matrix4/Matrix4.h"
class Renderer;
#include"Utility/Assets.h"

/**
 * @file SimpleMesh.h
 * @brief �A�j���[�V�������Ȃ��RD���f����`�t�@�C��
 * @author ���]
 * @date 2017/1/31
 */


 /*! @class SimpleMesh
 *   @brief �A�j���[�V�������Ȃ��RD���f��
 */
class SimpleMesh {
public:	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="modelName">�o�^�������O</param>
	/// <param name="isUseZBuffer">Z�\�[�g���邩�ǂ����H</param>
	SimpleMesh(Assets::Model id, bool isUseZBuffer = true);	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~SimpleMesh();
	
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
	/// ���f��ID�E�n���h�����擾
	/// </summary>
	/// <returns>���f��ID�E�n���h��</returns>
	int GetModelHandle();
	/// <summary>
	/// �f�B�t���[�Y�e�N�X�`����ς���
	/// </summary>
	/// <param name="textureID">�o�^�������O</param>
	/// <param name="materialNumber">�ύX����}�e���A���̔ԍ�</param>
	void ChangeTexture(Assets::Texture textureID, int materialNumber);


	//------------�R�s�[�֎~---------------
public:
	SimpleMesh(const SimpleMesh& other) = delete;
	SimpleMesh& operator = (const SimpleMesh& other) = delete;

private:
	//!���f��ID�E�n���h��
	int modelHandle;

};