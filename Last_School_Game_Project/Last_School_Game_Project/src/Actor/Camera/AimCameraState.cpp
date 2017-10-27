#include "AimCameraState.h"
#include"Actor/Base/Actor.h"
#include"Input/Input.h"

#include"Utility/Utility.h"

AimCameraState::AimCameraState(Matrix4 & matrix, Vector3& lookat, const Actor & target)
	: matrix(matrix)
	, lookat(lookat)
	, target(target)
	, localPosition(-1.5f,3.0f,2.0f)
	, position()
	, nextState()
	, isEnd(false)
{
}

AimCameraState::~AimCameraState()
{
}

void AimCameraState::Initialize()
{
	position = matrix.GetPosition();
	isEnd = false;
	nextState = FreeLookAtCamera::State::Default;
}

void AimCameraState::Update(float deltaTime)
{
	if (Input::GetInstance().GetCommand(Command::Shoot_Arrow) == false) {
		isEnd = true;
	}

	position = target.GetMatrix().Transform(localPosition);
	matrix.SetPosition(position);
	lookat = -matrix.GetFront() + position;
}

void AimCameraState::Finalize()
{

}

void AimCameraState::HandleMessage(EventMessage message, void * param)
{
}

bool AimCameraState::IsEnd() const
{
	return isEnd;
}

int AimCameraState::GetNextState() const
{
	return static_cast<int>(nextState);
}

int AimCameraState::GetNextAnime() const
{
	return 0;
}
