#pragma once

#include<DxLib.h>

/**
 * @file RenderTarget.h
 * @brief �����_�[�^�[�Q�b�g��`�t�@�C��
 * @author ���]
 * @date 2017/6/22
 */

/*! @class RenderTarget
*   @brief  �����_�[�^�[�Q�b�g
*/
class RenderTarget {
public:		
	/// <summary>
	/// �R���X�g���N�^<see cref="RenderTarget"/>
	/// </summary>
	/// <param name="width">�ݒ肷��X�N���[���̉���</param>
	/// <param name="height">�ݒ肷��X�N���[���̏c��</param>
	/// <param name="hdr">HDR�摜�ɂ��邩�ǂ����̐ݒ�</param>
	/// <param name="z_buffer">Z�o�b�t�@���g�p���邩</param>
	/// <param name="bit_depth">�r�b�g�̐[��</param>
	/// <param name="channel">�`�����l����</param>
	RenderTarget(int width, int height, bool hdr = false, bool z_buffer = true, int bit_depth = 32, int channel = 4);	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~RenderTarget();	
	/// <summary>
	/// �J�n
	/// </summary>
	void Begin();	
	/// <summary>
	/// �I��
	/// </summary>
	void End();	
	/// <summary>
	/// �`��
	/// </summary>
	void Draw() const;	
	/// <summary>
	/// �ݒ肵���摜�̉������擾
	/// </summary>
	/// <returns>�ݒ肵���摜�̉������擾</returns>
	int Width()const;	
	/// <summary>
	/// �ݒ肵���摜�̏c�����擾
	/// </summary>
	/// <returns>�ݒ肵���摜�̏c�����擾</returns>
	int Height() const;	
	/// <summary>
	/// ���������e�N�X�`���̃n���h�����擾
	/// </summary>
	/// <returns>���������e�N�X�`���̃n���h��</returns>
	int Texture() const;
private:
	//!�ݒ肵���摜�̉���
	int width;
	//!�ݒ肵���摜�̏c��
	int height;
	//!�e�N�X�`���̃n���h��
	int texture;
	//!�e�N�X�`����\��|���S��
	VERTEX2DSHADER vertices[4];
	//!�P�t���[���O�̃X�N���[�����
	int preview_draw_screen;
};