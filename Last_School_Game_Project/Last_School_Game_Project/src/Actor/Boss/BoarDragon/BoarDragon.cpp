#include "BoarDragon.h"
#include"Collision/Capsule/Capsule.h"
#include"World/IWorld.h"
#include"BoarDragon_Idle.h"
#include"BoarDragon_Move.h"
#include"Actor/State/IStatePtr.h"
#include"Actor/Base/EventMessage.h"
#include"Actor/Base/ActorUtility.h"
#include"Collision/HitInfo.h"
#include"BoarDragon_Damage.h"
#include"BoarDragon_Dead.h"
#include"BoarDragon_Attack.h"

BoarDragon::BoarDragon(IWorld & world, const Vector3 & position, Actor& player)
	: Actor(world, "BoarDragon", position, std::make_shared<Capsule>(Vector3(0, 0, 0), Vector3(0, 0, -5), 2.0f))
	, mesh(Assets::Model::BoarDragon, Assets::Animation::BoarDragon)
	, state(State::Idle)
	, stateManager()
	, player(player)
	, hp(200)
{
	stateManager.SetChangeFunc([&](int state, int motion) {
		mesh.ChangeMotion(motion);
	});
	this->position.y += 3.2f;
	stateManager.Add(static_cast<int>(State::Idle), std::make_shared<BoarDragon_Idle>());
	stateManager.Add(static_cast<int>(State::Move), std::make_shared<BoarDragon_Move>());
	stateManager.Add(static_cast<int>(State::Attack), std::make_shared<BoarDragon_Attack>(world, *this, mesh));
	stateManager.Add(static_cast<int>(State::Damage), std::make_shared<BoarDragon_Damage>(mesh, hp));
	stateManager.Add(static_cast<int>(State::Dead), std::make_shared<BoarDragon_Dead>(*this, mesh));
	stateManager.Change(static_cast<int>(State::Idle));
}

BoarDragon::~BoarDragon()
{
}

void BoarDragon::OnUpdate(float deltaTime)
{
	mesh.Update(deltaTime);
	stateManager.Update(deltaTime);
}

void BoarDragon::OnDraw(Renderer & renderer)
{
#if _DEBUG
	body->Transform(GetMatrix())->Draw();
#endif
	mesh.Draw(renderer, GetMatrix());
}

void BoarDragon::OnCollide(const HitInfo & hitInfo)
{
	hitInfo.collideActor->HandleMessage(EventMessage::Push, &position);
}

void BoarDragon::OnMessage(EventMessage message, void * param)
{
	if (message == EventMessage::Damage && hp.IsDead() == false) {
		stateManager.Change(static_cast<int>(State::Damage), Anime::Damage_);
	}
	stateManager.HandleMessage(message, param);
}

