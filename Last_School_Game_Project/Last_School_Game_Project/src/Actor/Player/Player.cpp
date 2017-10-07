#include "Player.h"
#include"Actor/Camera/ICamera.h"
#include"Collision/Capsule/Capsule.h"
#include"World/IWorld.h"
#include"Actor/State/IStatePtr.h"
#include"Idle.h"
#include"Move.h"
#include"Actor/Base/EventMessage.h"
#include"Actor/Base/ActorUtility.h"
#include"Collision/HitInfo.h"
#include"SwordAttack.h"
#include"Actor/Weapon/Sword/Sword.h"
#include"Actor/Weapon/Shield/Shield.h"
#include"Actor/Player/Guard.h"
#include"Damage.h"
#include"Dead.h"
#include"Actor/Field/IField.h"
#include"Input/Input.h"
#include"Actor/Weapon/Bow/Bow.h"
#include"BowAttack.h"

Player::Player(IWorld & world, const Vector3 & position)
	: Actor(world,"Player",position,std::make_shared<Capsule>(Vector3(0,0.5f,0),Vector3(0,2.5f,0),0.5f))
	, mesh(Assets::Model::Player, Assets::Animation::Player)
	, camera(nullptr)
	, stateManager()
	, isGround(true)
	, hp(100)
{
	camera = &world.GetCamera();
	camera->SetTarget(*this);

	ActorPtr sword = std::make_shared<Sword>(world, mesh);
	world.AddActor(ActorGroup::Weapon, sword);
	world.AddActor(ActorGroup::Weapon, std::make_shared<Shield>(world, mesh));
	world.AddActor(ActorGroup::Weapon, std::make_shared<Bow>(world, mesh));

	stateManager.SetChangeFunc([&](int state, int motion) {
		mesh.ChangeMotion(motion);
	});
	stateManager.Add(static_cast<int>(State::Idle), std::make_shared<Idle>());
	stateManager.Add(static_cast<int>(State::Move), std::make_shared<Move>(*this, *camera,mesh));
	stateManager.Add(static_cast<int>(State::SwordAttack), std::make_shared<SwordAttack>(*sword, mesh));
	stateManager.Add(static_cast<int>(State::Guard), std::make_shared<Guard>(mesh));
	stateManager.Add(static_cast<int>(State::Damage), std::make_shared<Damage>(mesh,hp));
	stateManager.Add(static_cast<int>(State::Dead), std::make_shared<Dead>(*this,mesh));
	stateManager.Add(static_cast<int>(State::BowAttack), std::make_shared<BowAttack>(world, *this, *camera , mesh));

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
	hitInfo.collideActor->HandleMessage(EventMessage::Push, &position);
}

void Player::OnMessage(EventMessage message, void * param)
{
	if (message == EventMessage::Damage && hp.IsDead() == false) {
		stateManager.Change(static_cast<int>(State::Damage), Anime::Damage_);
	}
	stateManager.HandleMessage(message, param);
}
