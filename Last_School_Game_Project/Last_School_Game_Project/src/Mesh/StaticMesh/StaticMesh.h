#pragma once

#include"Math/Matrix4/Matrix4.h"
class Renderer;
#include"Utility/Assets.h"

/**
 * @file StaticMesh.h
 * @brief �����Ȃ��RD���f����`�t�@�C��
 * @author ���]
 * @date 2017/1/23
 */

/*! @class StaticMesh
 *   @brief  �����Ȃ��RD���f��
 */
class StaticMesh {
public:	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="modelName">�o�^�������O</param>
	/// <param name="world">�����p���s��</param>
	/// <param name="isUseZBuffer">Z�\�[�g���邩�H</param>
	StaticMesh(Assets::Model id, const Matrix4& world, bool isUseZBuffer = true);	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~StaticMesh();
	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name="dt">�P�b</param>
	void Update(float dt);	
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name="renderer">�`��N���X</param>
	void Draw(Renderer& renderer) const;	
	/// <summary>
	///�@���f��ID�E�n���h�����擾
	/// </summary>
	/// <returns>���f��ID�E�n���h��</returns>
	int GetModelHandle();

public:
	//!--------�R�s�[�֎~---------
	StaticMesh(const StaticMesh& other) = delete;
	//!--------�R�s�[�֎~---------
	StaticMesh& operator = (const StaticMesh& other) = delete;

private:
	//!���f��ID�E�n���h��
	int modelHandle;

};