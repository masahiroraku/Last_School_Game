#include "Move.h"
#include"Actor/Camera/ICamera.h"
#include"Input/Input.h"
#include"Actor/Player/Player.h"

Move::Move(Actor & player, ICamera & camera, SkinningMesh& meshPtr)
	: isEnd(false)
	, player(player)
	, camera(camera)
	, meshPtr(meshPtr)
	, state(Player::State::Move)
	, WalkSpeed(0.1f)
	, RunSpeed(0.3f)
	, speed(WalkSpeed)
	, position()
{
}

Move::~Move()
{
}

void Move::Initialize()
{
	position = player.GetPosition();
	isEnd = false;
	state = Player::State::Idle;
	anime = Player::Anime::Idle_;
}

void Move::Update(float deltaTime)
{
	if (Input::GetInstance().GetCommand(Command::Shoot_Arrow)) {
		isEnd = true;
		state = Player::State::BowAttack;
		anime = Player::Anime::Aim_OverDraw_;
	}

	Vector3 velocity = Input::GetInstance().GetVelocity();
	if (velocity.SquareLength() <= 0.1f) {
		isEnd = true;
		state = Player::State::Idle;
		anime = Player::Anime::Idle_;
		return;
	}
	if (Input::GetInstance().GetCommand(Command::SwordAttack)) {
		isEnd = true;
		state = Player::State::SwordAttack;
		return;
	}

	if (Input::GetInstance().GetCommand(Command::Dash)) {
		speed = RunSpeed;
		meshPtr.ChangeMotion(Player::Anime::Run_);
	}
	else {
		speed = WalkSpeed;
		meshPtr.ChangeMotion(Player::Anime::Walk_);
	}

	velocity.Normalize();
	LookAtFront(velocity);
	Matrix4 cameraMatrix = camera.GetMatrix();
	position += -cameraMatrix.GetFront() * velocity.z * speed  * deltaTime;
	position += -cameraMatrix.GetLeft()  * velocity.x * speed  * deltaTime;
	player.SetPosition(position);
}

void Move::Finalize()
{
}

void Move::HandleMessage(EventMessage message, void * param)
{
}

bool Move::IsEnd() const
{
	return isEnd;
}

int Move::GetNextState() const
{
	return static_cast<int>(state);
}
int Move::GetNextAnime() const
{
	return anime;
}

void Move::LookAtFront(const Vector3 & velocity)
{
	Vector3 front = camera.GetMatrix().GetFront();

	float cameraYow = front.Yaw();
	float inputYaw = velocity.Yaw();

	Vector3 f = Vector3::CreateFromYawPitch(cameraYow + inputYaw, 0.0f);

	player.SetMatrix(Matrix4::CreateLookAt(Vector3::Zero, f, player.GetMatrix().GetUp()));
}
