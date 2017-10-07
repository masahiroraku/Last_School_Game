#pragma once
#include "Actor/Base/Actor.h"
#include "Mesh/SimpleMesh/SimpleMesh.h"
#include "Mesh/SkinningMesh/SkinningMesh.h"

class Sword : public Actor
{
public:
	Sword(IWorld& world, SkinningMesh& parentMesh);
	~Sword();
private:
	virtual void OnUpdate(float deltaTime) override;
	virtual void OnDraw(Renderer& renderer) override;
	virtual void OnCollide(const HitInfo& hitInfo) override;
	virtual void OnMessage(EventMessage message, void* param = nullptr) override;
private:
	SimpleMesh mesh;
	SkinningMesh& parentMesh;
	int damage;
};
