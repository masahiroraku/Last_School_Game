#pragma once

#include"Mesh/SimpleMesh/SimpleMesh.h"
#include"CameraBase.h"
#include"Actor/Base/ActorPtr.h"
#include"Actor/Status/HitPoint/HitPoint.h"
#include"Utility/Timer/Timer.h"
#include "Collision/ShapePtr.h"
#include"Collision/BoundingSphere/BoundingSphere.h"

/************************************************************
* File Name	: Camera.h
* Description	: 3D��Ԃ��f���J����
*																Date		:	Unknown.
*															  Author	:	���]
*************************************************************/
class Camera : public CameraBase {
public:	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="world">world</param>
	explicit Camera(IWorld& world);
	~Camera();

	virtual void OnUpdate(float deltaTime) override;
	virtual void OnDraw(Renderer& renderer)override;
	virtual void OnMessage(EventMessage message, void* param)override;


private:
	void CalcYawPitch(float deltaTime);
	void Rotate();
	void RotateRockOn();

	void SearchRockOnActor();

private:
	enum class State {
		//!�ʏ��ԁ@�����_���O���O��
		Default,
		//!���b�N�I�����
		LockOn,
		//!�\���Ă�����
		Aim
	};

private:
	SimpleMesh skybox;
	//��]�p�̃��[�iZ����]�j
	float yaw;
	//��]�p�̃s�b�`�iY����]�j
	float pitch;

	//��]�p�̃��[�̍��v�iZ����]�j
	float yaw_total;
	//��]�p�̃s�b�`�̍��v�iY����]�j
	float pitch_total;

	float lerp_start_yaw;
	float lerp_end_yaw;
	float lerp_t_yaw;


	//���������銄��
	const float Accelerate_rate;
	//�ő�X�s�[�h
	const float Speed_max;
	//�ő僈�[�p�x
	const float Yaw_max;
	//�ő�s�b�`�p�x
	const float Pitch_max;

	//�{�X���v���C���[�����񂾂����肷��t���O
	bool isGameEnd;

	//�I�[�g���b�N�I���ł���v���C���[����̋���
	const float TargetCanRockOnDistance;

	//���b�N�I�����������鋗��
	const float UnRockOnDistance;

	//�����蔻��
	BoundingSphere body;
	State state;
	Actor* lockOnTarget;

};