#include "DefaultCameraState.h"
#include"Actor/Base/Actor.h"
#include"Input/Input.h"

DefaultCameraState::DefaultCameraState(Matrix4 & matrix, Vector3& lookat, const Actor & target)
	: matrix(matrix)
	, target(target)
	, lookat(lookat)
	, moveSpeed(0.1f)
	, turnSpeed(1.5f)
	, tiltMax(45.0f)
	, tiltMin(-45.0f)
	, localPosition(0, 5, 8)
	, position()
	, yawTotal(180.0f)
	, pitchTotal(-30.0f)
	, nextState()
	, isEnd(false)
{
	
}

DefaultCameraState::~DefaultCameraState()
{
}

void DefaultCameraState::Initialize()
{
	position = matrix.GetPosition();
	isEnd = false;
	nextState = FreeLookAtCamera::State::Aim;
}

void DefaultCameraState::Update(float deltaTime)
{
	if (Input::GetInstance().GetCommand(Command::Shoot_Arrow)) {
		isEnd = true;
		return;
	}

	RotationMovement(deltaTime);

	Vector3 front = target.GetPosition() - position;
	front.y = 0.0f;
	front.Normalize();
	matrix = Matrix4::CreateLookAt(position, -front, matrix.GetUp());
	lookat = target.GetPosition() + Vector3(0, 1, 0);
}

void DefaultCameraState::Finalize()
{

}

void DefaultCameraState::HandleMessage(EventMessage message, void * param)
{
}

bool DefaultCameraState::IsEnd() const
{
	return isEnd;
}

int DefaultCameraState::GetNextState() const
{
	return static_cast<int>(nextState);
}

int DefaultCameraState::GetNextAnime() const
{
	return 0;
}


void DefaultCameraState::RotationMovement(float deltaTime)
{
	//“ü—Í‚³‚ê‚½‰¡²‚Ì”’l‚ğæ“¾
	yawTotal += Input::GetInstance().GetAxis(Axis::Horizontal2) * deltaTime;
	//“ü—Í‚³‚ê‚½c²‚Ì”’l‚ğæ“¾
	pitchTotal += -Input::GetInstance().GetAxis(Axis::Vertical2) * deltaTime;

	pitchTotal = Math::Clamp(pitchTotal, tiltMin, tiltMax);

	Vector3 anglePosition = Vector3::CreateFromYawPitch(yawTotal, pitchTotal) * localPosition.z;
	position = target.GetPosition() + anglePosition;
	matrix.SetPosition(position);
}
