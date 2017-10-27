#pragma once

#include"Actor/Base/Actor.h"
#include"Mesh/SkinningMesh/SkinningMesh.h"

class BiteCollision : public Actor {
public:
	BiteCollision(IWorld& world, SkinningMesh& meshPtr);
	~BiteCollision();
private:
	virtual void OnInitialize() override;
	virtual void OnUpdate(float deltaTime) override;
	virtual void OnDraw(Renderer& renderer) override;
	virtual void OnCollide(const HitInfo& hitInfo) override;
	virtual void OnMessage(EventMessage message, void* param = nullptr) override;
private:
	bool IsEnableCollideTime() const;
private:
	SkinningMesh& meshPtr;
	const int ToggleBoneIndex;
	std::pair<float, float> enableCollideTime;
	int damage;
};