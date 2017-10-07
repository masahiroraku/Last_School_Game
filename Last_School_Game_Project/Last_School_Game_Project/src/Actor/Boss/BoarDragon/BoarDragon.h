#pragma once
#include "Actor/Base/Actor.h"
#include"Mesh/SkinningMesh/SkinningMesh.h"
#include"Actor/State/StateManager.h"
#include"Actor/Status/HitPoint/HitPoint.h"

class BoarDragon :	public Actor
{
public:
	enum class State {
		Idle,
		Move,
		Attack,
		Damage,
		Dead
	};
	enum Anime {
		Idle_,
		Walk_,
		Run_,
		Bite_,
		Rush,
		Scream_,
		Damage_,
		Dead_
	};
public:
	BoarDragon(IWorld& world, const Vector3& position, Actor& player);
	~BoarDragon();
private:
	virtual void OnUpdate(float deltaTime) override;
	virtual void OnDraw(Renderer& renderer) override;
	virtual void OnCollide(const HitInfo& hitInfo) override;
	virtual void OnMessage(EventMessage message, void* param = nullptr) override;
private:
	SkinningMesh mesh;
	State state;
	StateManager stateManager;
	Actor& player;
public:
	HitPoint hp;
};

