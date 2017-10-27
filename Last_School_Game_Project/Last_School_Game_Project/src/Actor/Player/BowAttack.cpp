#include "BowAttack.h"
#include"Input/Input.h"
#include"Actor/Camera/ICamera.h"

BowAttack::BowAttack(IWorld & world, Actor& playerPtr, ICamera& cameraPtr, SkinningMesh & meshPtr)
	: isEnd(false)
	, state(Player::State::Idle)
	, anime(Player::Anime::Idle_)
	, world(world)
	, playerPtr(playerPtr)
	, meshPtr(meshPtr)
	, WalkSpeed(0.1f)
	, cameraPtr(cameraPtr)
	, position()
{
}

BowAttack::~BowAttack()
{
}

void BowAttack::Initialize()
{
	isEnd = false;
	state = Player::State::Idle;
	anime = Player::Anime::Idle_;
	position = playerPtr.GetPosition();
}

void BowAttack::Update(float deltaTime)
{
	if (Input::GetInstance().GetCommand(Command::Shoot_Arrow) == false) {
		isEnd = true;
		return;
	}

	Vector3 velocity = Input::GetInstance().GetVelocity();
	if (velocity.SquareLength() <= 0.1f) {
		return;
	}


	velocity.Normalize();


	Matrix4 cameraMatrix = cameraPtr.GetMatrix();
	position += -cameraMatrix.GetFront() * velocity.z * WalkSpeed  * deltaTime;
	position += -cameraMatrix.GetLeft()  * velocity.x * WalkSpeed  * deltaTime;
	playerPtr.SetPosition(position);
}

void BowAttack::Finalize()
{
}

void BowAttack::HandleMessage(EventMessage message, void * param)
{
}

bool BowAttack::IsEnd() const
{
	return isEnd;
}

int BowAttack::GetNextState() const
{
	return static_cast<int>(state);
}

int BowAttack::GetNextAnime() const
{
	return anime;
}

void BowAttack::LookAtFront(const Vector3 & velocity)
{
	Vector3 front = cameraPtr.GetMatrix().GetFront();

	float cameraYow = front.Yaw();
	float inputYaw = velocity.Yaw();

	Vector3 f = Vector3::CreateFromYawPitch(cameraYow + inputYaw, 0.0f);

	playerPtr.SetMatrix(Matrix4::CreateLookAt(Vector3::Zero, f, playerPtr.GetMatrix().GetUp()));

}
