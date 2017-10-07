#pragma once
#include "Actor/Base/Actor.h"
#include "Mesh/SimpleMesh/SimpleMesh.h"
#include "Mesh/SkinningMesh/SkinningMesh.h"

class Bow : public Actor {
public:
	Bow(IWorld& world, SkinningMesh& parentMesh);
	~Bow();
private:
	virtual void OnUpdate(float deltaTime) override;
	virtual void OnDraw(Renderer& renderer) override;
	virtual void OnMessage(EventMessage message, void* param = nullptr) override;
private:
	SimpleMesh mesh;
	SkinningMesh& parentMesh;
};