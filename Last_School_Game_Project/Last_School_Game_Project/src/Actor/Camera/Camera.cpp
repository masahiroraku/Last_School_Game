#include"Utility/cpplinq.hpp"
#include "Camera.h"
#include"Renderer/Renderer.h"
#include"Input/Input.h"
#include"Math/Convert/Convert.h"
#include"Collision/Line/Line.h"
#include"Actor/Base/EventMessage.h"
#include"Actor/Base/Actor.h"
#include"World/IWorld.h"
#include<algorithm>
#include"Utility/Utility.h"
#include"Actor/Field/IField.h"
#include"Collision/HitInfo.h"
#include<DxLib.h>
#include"Actor/Field/IField.h"

static const Vector3 InitializePosition = Vector3(0, 1, -8);
Camera::Camera(IWorld & world)
	: CameraBase(world)
	, skybox(Assets::Model::Skybox,false)
	, body(0.2f)
	, yaw(0.0f)
	, pitch(0.0f)
	, yaw_total(0.0f)
	, pitch_total(0.0f)
	, Accelerate_rate(0.1f)
	, Speed_max(0.2f)
	, Yaw_max(2.0f)
	, Pitch_max(1.5f)
	, isGameEnd(false)
	, TargetCanRockOnDistance(8.0f)
	, UnRockOnDistance(20.0f)
	, lerp_start_yaw(0.0f)
	, lerp_end_yaw(0.0f)
	, lerp_t_yaw(0.0f)
	, state(State::Default)
	, lockOnTarget(nullptr)
{
	position = InitializePosition;

	//�J�����ʒu�ƒ����_��ݒ�
	SetCameraPositionAndTargetAndUpVec(
		Convert::ToVECTOR(position),
		Convert::ToVECTOR(Vector3(0, InitializePosition.y, 0)),
		Convert::ToVECTOR(Vector3::Up)
	);
}

Camera::~Camera()
{
}

void Camera::OnUpdate(float deltaTime)
{
	if (Input::GetInstance().GetCommand(Command::Shoot_Arrow)) {
		state = State::Aim;
	}
	else {
		state = State::Default;
	}

	if (state == State::Default) {
		CalcYawPitch(deltaTime);
		Rotate();
	}
	if (state == State::Aim) {
		//�����_��ݒ�
		Vector3 targetPosition = target->GetPosition() + Vector3(0, 3.5f, 0);

		position = targetPosition + (-target->GetMatrix().GetLeft() * 2.0f) + (target->GetMatrix().GetFront() * 2.0f);
		Vector3 lookat = targetPosition + -target->GetMatrix().GetFront() * 10.0f;
		lookat.y = 0.0f;
		matrix = Matrix4::CreateLookAt(position, -lookat, matrix.GetUp());


		//�J�����ʒu�ƒ����_��ݒ�
		SetCameraPositionAndTargetAndUpVec(
			Convert::ToVECTOR(position),
			Convert::ToVECTOR(lookat),
			Convert::ToVECTOR(matrix.GetUp())
		);
	}
	printfDx("X = %0.2f, Y = %0.2f, Z = %0.2f\n", position.x, position.y, position.z);

	
	//if (lockOnTarget != nullptr && (!IsInsideCameraView(lockOnTarget->GetPosition()) ||
		//	lockOnTarget->GetPosition().Distance(target->GetPosition()) >= UnRockOnDistance)) {
		//	lockOnTarget = nullptr;
		//	state = State::Default;
		//}
		//if (target == nullptr || isGameEnd == true)
		//	return;
		////if (Input::GetInstance().GetCommand(Command::Camera_RockOn) && rockOnTarget != nullptr) {
		////	isRockOn = !isRockOn;
		////	lerp_t_yaw = 0.0f;
		////}
		//CalcYawPitch(deltaTime);
		//if (state == State::LockOn) {
		//	return;
		//}
		//if (state == State::LockOn || lockOnTarget == nullptr) {
		//	SearchRockOnActor();
		//	Rotate();
		//	return;
		//}
		//RotateRockOn();
}

void Camera::OnDraw(Renderer & renderer)
{
	skybox.Draw(renderer, Matrix4::Translate(position));
}

void Camera::OnMessage(EventMessage message, void * param)
{
}

void Camera::CalcYawPitch(float deltaTime)
{
	//���͂��ꂽ�����̐��l���擾
	float yaw_ = Input::GetInstance().GetAxis(Axis::Horizontal2) * deltaTime;
	//���͂��ꂽ�c���̐��l���擾
	float pitch_ = -Input::GetInstance().GetAxis(Axis::Vertical2) * deltaTime;

	//�������̌v�Z��
	yaw += (yaw_ * Yaw_max - yaw) * Accelerate_rate;
	pitch += (pitch_ * Pitch_max - pitch) * Accelerate_rate;

	//���͂��ꂽ���l�𑫂��Ă���
	yaw_total += yaw;
	pitch_total += pitch;

	//�c����]�̐���
	pitch_total = Math::Clamp<float>(pitch_total, -10.0f, 45.0f);
}

void Camera::Rotate()
{
	//���[�A�s�b�`����x�N�g�������
	Vector3 anglePosition = Vector3::CreateFromYawPitch(yaw_total, pitch_total) * InitializePosition.z;

	//�����_��ݒ�
	Vector3 targetPosition = target->GetPosition() + Vector3(0, InitializePosition.y, 0);

	//�J�����̍��W��ݒ�
	position = Matrix4::Translate(targetPosition).Transform(anglePosition);

	//Y�̍��W��0�ɂ���@���@�v���C���[�̓J�����̑O�����ɐi�ނ̂ŁAY�v�f������ƁA��������n�ʂɂ߂荞�񂾂肷��B
	Vector3 xzOnlyVector = Vector3(anglePosition.x, 0.0f, anglePosition.z);


	//�J�����̎p���s���ݒ�
	matrix = Matrix4::CreateLookAt(position, xzOnlyVector, matrix.GetUp());


	//�J�����ʒu�ƒ����_��ݒ�
	SetCameraPositionAndTargetAndUpVec(
		Convert::ToVECTOR(position),
		Convert::ToVECTOR(targetPosition),
		Convert::ToVECTOR(matrix.GetUp())
	);
}

void Camera::RotateRockOn()
{
	if (lockOnTarget == nullptr)
		return;

	lerp_start_yaw = yaw_total;
	lerp_end_yaw = (lockOnTarget->GetPosition() - target->GetPosition()).Yaw();

	//----�⊮���Ċ��炩�ɂ���
	lerp_t_yaw = Math::Min(lerp_t_yaw + 0.05f, 1.0f);
	float yaw_ = Math::Lerp(lerp_start_yaw, lerp_end_yaw, lerp_t_yaw);
	//-----------------

	yaw_total = yaw_;

	//���[�A�s�b�`����x�N�g�������
	Vector3 anglePosition = Vector3::CreateFromYawPitch(yaw_, pitch_total) * InitializePosition.z;

	//�����_��ݒ�
	Vector3 targetPosition = target->GetPosition() + Vector3(0, InitializePosition.y, 0);
	//�J�����̍��W��ݒ�
	position = Matrix4::Translate(targetPosition).Transform(anglePosition);


	//Y�̍��W��0�ɂ���@���@�v���C���[�̓J�����̑O�����ɐi�ނ̂ŁAY�v�f������ƁA��������n�ʂɂ߂荞�񂾂肷��B
	Vector3 xzOnlyVector = Vector3(anglePosition.x, 0.0f, anglePosition.z);

	//�J�����̎p���s���ݒ�
	matrix = Matrix4::CreateLookAt(position, xzOnlyVector, matrix.GetUp());



	//�J�����ʒu�ƒ����_��ݒ�
	SetCameraPositionAndTargetAndUpVec(
		Convert::ToVECTOR(position),
		Convert::ToVECTOR(targetPosition),
		Convert::ToVECTOR(matrix.GetUp())
	);


}

void Camera::SearchRockOnActor()
{
	//using namespace cpplinq;
	//auto viewActors = IsInsideCameraViewActors(ActorGroup::Enemy);


	//auto rockOnTargets = from(viewActors) >>
	//where([&](const ActorPtr& child) {
	//	return child->GetPosition().Distance(target->GetPosition()) <= TargetCanRockOnDistance && child->GetTag() != ActorTag::UnLockOnTarget;
	//})
	//	>> to_vector();

	////���b�N�I���Ώۂ����Ȃ������牽�����Ȃ�
	//if (rockOnTargets.size() <= 0) {
	//	rockOnTarget = nullptr;
	//	return;
	//}

	//Vector3 velocity = Input::GetInstance().GetVelocity();

	//if (velocity.SquareLength() < 0.3f) {
	//	velocity = -target->GetMatrix().GetFront();
	//}

	////���͕����ƃ��b�N�I���Ώۂ̊p�x�������������ɕ��ёւ�
	//std::stable_sort(rockOnTargets.begin(), rockOnTargets.end(),
	//	[&](const ActorPtr& actor0, const ActorPtr& actor1) {

	//	Matrix4 rotate = matrix.SetPosition(0, 0, 0);
	//	float a = actor0->GetPosition().Angle(rotate.Transform(-velocity));
	//	float b = actor1->GetPosition().Angle(rotate.Transform(-velocity));
	//	return a < b;
	//});
	//rockOnTarget = rockOnTargets[0];
}

