#include "Move.h"
#include"Actor/Camera/ICamera.h"
#include"Input/Input.h"
#include"Actor/Player/Player.h"

Move::Move(Actor & player, ICamera & camera)
	: isEnd(false)
	, player(player)
	, camera(camera)
	, state(0)
	, WalkSpeed(1.0f)
	, RunSpeed(3.0f)
	, speed(WalkSpeed)
	, position()
{
}

Move::~Move()
{
}

void Move::Initialize()
{
	isEnd = false;
}

void Move::Update(float deltaTime)
{
	Vector3 velocity = Input::GetInstance().GetVelocity();
	if (velocity.SquareLength() <= 0.1f) {
		isEnd = true;
		state = static_cast<int>(Player::State::Idle);
		return;
	}

	velocity.Normalize();
	LookAtFront(velocity);
	Matrix4 cameraMatrix = camera.GetMatrix();
	position += -cameraMatrix.GetFront() * speed  * deltaTime;
	position += -cameraMatrix.GetLeft()  * speed  * deltaTime;
	player.SetPosition(position);
}

bool Move::IsEnd() const
{
	return isEnd;
}

int Move::GetNextState() const
{
	return state;
}
int Move::GetNextAnime() const
{
	return Player::Anime::Idle_;
}

void Move::LookAtFront(const Vector3 & velocity)
{
	Vector3 front = camera.GetMatrix().GetFront();

	float cameraYow = front.Yaw();
	float inputYaw = velocity.Yaw();

	Vector3 f = Vector3::CreateFromYawPitch(cameraYow + inputYaw, 0.0f);

	player.SetMatrix(Matrix4::CreateLookAt(Vector3::Zero, f, player.GetMatrix().GetUp()));
}
