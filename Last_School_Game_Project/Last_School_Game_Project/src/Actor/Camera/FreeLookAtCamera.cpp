#include "FreeLookAtCamera.h"
#include"Actor/Base/Actor.h"
#include"Input/Input.h"
#include"Math/Convert/Convert.h"

FreeLookAtCamera::FreeLookAtCamera(IWorld & world)
	: CameraBase(world)
	, skybox(Assets::Model::Skybox)
	, moveSpeed(0.1f)
	, turnSpeed(1.5f)
	, tiltMax(75.0f)
	, tiltMin(45.0f)
	, lookDistance(10.0f)
	, localPosition(0,5,-8)
	, lookAngle(0.0f)
	, tiltAngle(0.0f)
	, pivotEulers()
	, pivotTargetRotate()
	, transformTargetRotate()
{
	//pivotEulers = pivot.GetRotateAngle_Degree();
	//pivotTargetRotate = pivot.GetRotation();
	//transformTargetRotate = matrix.GetRotation();

	//カメラ位置と注視点を設定
	SetCameraPositionAndTargetAndUpVec(
		Convert::ToVECTOR(localPosition),
		Convert::ToVECTOR(Vector3(0,1,0)),
		Convert::ToVECTOR(matrix.GetUp())
	);
}

FreeLookAtCamera::~FreeLookAtCamera()
{
}

void FreeLookAtCamera::OnUpdate(float deltaTime)
{
	//RotationMovement(deltaTime);

	position = position.Lerp(target->GetPosition(),moveSpeed * deltaTime);

	Vector3 lookat = target->GetPosition() - (position + localPosition);
	lookat.y = 0.0f;
	matrix = Matrix4::CreateLookAt(position + localPosition, -lookat, matrix.GetUp());

	//カメラ位置と注視点を設定
	SetCameraPositionAndTargetAndUpVec(
		Convert::ToVECTOR(matrix.GetPosition()),
		Convert::ToVECTOR(target->GetPosition() + Vector3(0,1,0)),
		Convert::ToVECTOR(matrix.GetUp())
	);
}

void FreeLookAtCamera::OnDraw(Renderer & renderer)
{
	skybox.Draw(renderer, Matrix4::Translate(position));
}

void FreeLookAtCamera::OnMessage(EventMessage message, void * param)
{
}

void FreeLookAtCamera::RotationMovement(float deltaTime)
{
	//入力された横軸の数値を取得
	float x = Input::GetInstance().GetAxis(Axis::Horizontal2) * deltaTime;
	//入力された縦軸の数値を取得
	float y = -Input::GetInstance().GetAxis(Axis::Vertical2) * deltaTime;

	lookAngle += x * turnSpeed;

	transformTargetRotate = Quaternion(0, lookAngle, 0.0f);

	tiltAngle -= y * turnSpeed;
	tiltAngle = Math::Clamp(tiltAngle, -tiltMin, tiltMax);

	pivotTargetRotate = Quaternion(tiltAngle, pivotEulers.y, pivotEulers.z);

	pivot = pivotTargetRotate.ToRotateMatrix();
	matrix = transformTargetRotate.ToRotateMatrix();

}
