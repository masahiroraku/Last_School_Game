#include "TitleCamera.h"
#include"Math/Convert/Convert.h"


static const Vector3 InitializeTitleCameraPosition = Vector3(0, 10, 0);

TitleCamera::TitleCamera(IWorld & world)
	: CameraBase(world)
	, angle(0.0f)
{
	position = InitializeTitleCameraPosition;



	//�J�����ʒu�ƒ����_��ݒ�
	SetCameraPositionAndTargetAndUpVec(
		Convert::ToVECTOR(position),
		Convert::ToVECTOR(matrix.GetFront() * 50.0f),
		Convert::ToVECTOR(Vector3::Up)
	);

}

TitleCamera::~TitleCamera()
{
}

void TitleCamera::OnUpdate(float deltaTime)
{
	angle += deltaTime / 5.0f;

	if (angle > 360.0f) {
		angle = 0.0f;
	}

	matrix.SetRotateY(angle);

	//�J�����ʒu�ƒ����_��ݒ�
	SetCameraPositionAndTargetAndUpVec(
		Convert::ToVECTOR(position),
		Convert::ToVECTOR(matrix.GetFront() * 50.0f),
		Convert::ToVECTOR(matrix.GetUp())
	);

}

void TitleCamera::OnDraw(Renderer & renderer)
{
}

void TitleCamera::OnMessage(EventMessage message, void * param)
{
}

