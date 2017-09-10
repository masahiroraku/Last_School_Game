#include"Utility/cpplinq.hpp"
#include "Camera.h"
#include"Renderer\Renderer.h"
#include"Input/Input.h"
#include"Math/Convert/Convert.h"
#include"Collision/Line/Line.h"
#include"Actor/Base/EventMessage.h"
#include"Actor/Base/Actor.h"
#include"World/IWorld.h"
#include"Collision/BoundingSphere/BoundingSphere.h"
#include<algorithm>
#include"Utility/Utility.h"
#include"Actor/Field/IField.h"
#include"Collision/HitInfo.h"
#include<DxLib.h>

static const Vector3 InitializePosition = Vector3(0, 1, -8);
Camera::Camera(IWorld & world)
	: CameraBase(world)
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
	, body(std::make_shared<BoundingSphere>(Vector3::Zero, 0.1f))
	, bossPtr(nullptr)
	, isLookAtBoss(false)
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

	if (rockOnTarget != nullptr && (!IsInsideCameraView(rockOnTarget->GetPosition()) || rockOnTarget->GetPosition().Distance(target->GetPosition()) >= UnRockOnDistance || rockOnTarget->GetPosition().y <= -4.0f)) {
		rockOnTarget = nullptr;
		isRockOn = false;
	}


	if (target == nullptr || isGameEnd == true)
		return;

	if (Input::GetInstance().GetCommand(Command::Camera_RockOn) && rockOnTarget != nullptr) {
		isRockOn = !isRockOn;
		lerp_t_yaw = 0.0f;
	}

	CalcYawPitch(deltaTime);

	if (isLookAtBoss == true) {
		LookAtBoss();
		return;
	}

	if (isRockOn == false || rockOnTarget == nullptr) {
		SearchRockOnActor();
		Rotate();
		return;
	}
	RotateRockOn();

}

void Camera::OnDraw(Renderer & renderer)
{
#if _DEBUG
	//BoundingSphere(target->GetPosition(), TargetCanRockOnDistance).Draw();
	//body->Transform(GetMatrix())->Draw();
#endif
}

void Camera::OnMessage(EventMessage message, void * param)
{
	if (message == EventMessage::Boss_Dead || message == EventMessage::Player_Dead) {
		isGameEnd = true;
	}
	if (message == EventMessage::BossChangeMode) {
		isLookAtBoss = !isLookAtBoss;
		lerp_t_yaw = 0.0f;
		pitch_total = -2.0f;
	}
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
	pitch_total = Math::Clamp<float>(pitch_total, -10.0f, 30.0f);
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
	if (rockOnTarget == nullptr)
		return;

	lerp_start_yaw = yaw_total;
	lerp_end_yaw = (rockOnTarget->GetPosition() - target->GetPosition()).Yaw();

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

void Camera::LookAtBoss()
{
	if (bossPtr == nullptr) {
		bossPtr = world->FindActor(ActorGroup::Enemy,"Boss").get();
	}
	lerp_start_yaw = yaw_total;
	lerp_end_yaw = (bossPtr->GetPosition() - target->GetPosition()).Yaw();

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
	using namespace cpplinq;
	auto viewActors = IsInsideCameraViewActors(ActorGroup::Enemy);


	auto rockOnTargets = from(viewActors) >>
	where([&](const ActorPtr& child) {
		return child->GetPosition().Distance(target->GetPosition()) <= TargetCanRockOnDistance && child->GetTag() != ActorTag::UnLockOnTarget;
	})
		>> to_vector();

	//���b�N�I���Ώۂ����Ȃ������牽�����Ȃ�
	if (rockOnTargets.size() <= 0) {
		rockOnTarget = nullptr;
		return;
	}

	Vector3 velocity = Input::GetInstance().GetVelocity();

	if (velocity.SquareLength() < 0.3f) {
		velocity = -target->GetMatrix().GetFront();
	}

	//���͕����ƃ��b�N�I���Ώۂ̊p�x�������������ɕ��ёւ�
	std::stable_sort(rockOnTargets.begin(), rockOnTargets.end(),
		[&](const ActorPtr& actor0, const ActorPtr& actor1) {

		Matrix4 rotate = matrix.SetPosition(0, 0, 0);
		float a = actor0->GetPosition().Angle(rotate.Transform(-velocity));
		float b = actor1->GetPosition().Angle(rotate.Transform(-velocity));
		return a < b;
	});
	rockOnTarget = rockOnTargets[0];
}

