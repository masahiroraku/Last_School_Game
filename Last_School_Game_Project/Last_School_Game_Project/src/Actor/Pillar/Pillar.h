#pragma once
#include"Actor/Base/Actor.h"
#include"Mesh/StaticMesh/StaticMesh.h"
#include"Actor/Status/HitPoint/HitPoint.h"

class Pillar : public Actor {
public:
	Pillar(IWorld& world, const Vector3& position);
	~Pillar();
private:
	virtual void OnUpdate(float deltaTime) override;
	virtual void OnDraw(Renderer& renderer) override;
	virtual void OnCollide(const HitInfo& hitInfo) override;
	virtual void OnMessage(EventMessage message, void* param = nullptr) override;
private:
	StaticMesh mesh;
	//!‘Ï‹v“x
	HitPoint hp;
};