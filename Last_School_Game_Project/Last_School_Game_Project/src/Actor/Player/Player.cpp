#include "Player.h"
#include"Actor/Camera/ICamera.h"
#include"Collision/Capsule/Capsule.h"
#include"World/IWorld.h"
#include"Actor/State/IStatePtr.h"
#include"Idle.h"
#include"Move.h"

Player::Player(IWorld & world, const Vector3 & position)
	: Actor(world,"Player",position,std::make_shared<Capsule>(Vector3(0,1.0f,0),Vector3(0,2.5f,0),1.0f))
	, mesh(Assets::Model::Player, Assets::Animation::Player)
	, state(State::Idle)
	,camera(nullptr)
	,stateManager()
{
	camera = &world.GetCamera();
	camera->SetTarget(*this);

	stateManager.SetChangeFunc([&](int state, int motion) {
		mesh.ChangeMotion(motion);
	});
	stateManager.Add(static_cast<int>(State::Idle), std::make_shared<Idle>());
	stateManager.Add(static_cast<int>(State::Move), std::make_shared<Move>(*this, *camera));
	stateManager.Change(static_cast<int>(State::Idle));
}

Player::~Player()
{
}

void Player::OnUpdate(float deltaTime)
{
	mesh.Update(deltaTime);
	stateManager.Update(deltaTime);
}

void Player::OnDraw(Renderer & renderer)
{
#if _DEBUG
	body->Transform(GetMatrix())->Draw();
#endif
	mesh.Draw(renderer, GetMatrix());
}

void Player::OnCollide(const HitInfo & hitInfo)
{
}

void Player::OnMessage(EventMessage message, void * param)
{
}
