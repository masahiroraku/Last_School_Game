#pragma once

#include"Math/Matrix4/Matrix4.h"
class Renderer;
#include<string>
#include"Utility/Timer/Timer.h"
#include"Utility/Assets.h"
#include"Actor/Base/Actor.h"

/**
 * @file Effect3D.h
 * @brief �RD�G�t�F�N�g��`�t�@�C��
 * @author ���]
 * @date 2017/1/23
 */


 /*! @class Effect3D
 *   @brief  3D�G�t�F�N�g
 */
class Effect3D : public Actor {
public:		
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="world">world</param>
	/// <param name="id">�o�^�������O</param>
	/// <param name="matrix">�p���s��</param>
	/// <param name="isPlayOnce">1��݂̂̍Đ����ǂ���</param>
	Effect3D(IWorld& world, Assets::Effect id, const Matrix4& matrix, bool isPlayOnce = false);	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Effect3D();

public:	
	/// <summary>
	/// �Đ������ǂ���
	/// </summary>
	/// <returns>
	/// [true �Đ���: false �Đ����Ă��Ȃ�]
	/// </returns>
	bool IsPlay() const;
	
private:	
	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name="deltaTime">1�b</param>
	virtual void OnUpdate(float deltaTime) override;	
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name="renderer">�`��N���X</param>
	virtual void OnDraw(Renderer& renderer) override;	
	/// <summary>
	/// �Փˌ��m
	/// </summary>
	/// <param name="hitInfo">�Փˏ��</param>
	virtual void OnCollide(const HitInfo& hitInfo) override;	
	/// <summary>
	/// �C�x���g���b�Z�[�W���󂯎��
	/// </summary>
	/// <param name="message">�C�x���g���b�Z�[�W</param>
	/// <param name="param">�C�x���g���b�Z�[�W�ƈꏏ�ɑ�����ϐ�</param>
	virtual void OnMessage(EventMessage message, void* param = nullptr) override;



private:
	//!�o�^�����G�t�F�N�g
	Assets::Effect id;
	//!�P�񂾂��Đ����邩����t���O
	bool isPlayOnce;
	//!�Đ����̃G�t�F�N�g��ID�E�n���h��
	int playHandle;
	//!�Đ������ǂ����̃t���O
	bool isPlay;

};