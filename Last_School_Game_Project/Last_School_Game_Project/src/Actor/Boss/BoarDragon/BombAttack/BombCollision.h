#pragma once

#include"Actor/Base/Actor.h"
#include"Mesh/SkinningMesh/SkinningMesh.h"
#include"Math/Bezier/Bezier.h"

class BombCollision : public Actor {
public:
	BombCollision(IWorld& world,const Vector3& start, const Vector3& end);
	~BombCollision();
private:
	virtual void OnInitialize() override;
	virtual void OnUpdate(float deltaTime) override;
	virtual void OnDraw(Renderer& renderer) override;
	virtual void OnCollide(const HitInfo& hitInfo) override;
	virtual void OnMessage(EventMessage message, void* param = nullptr) override;
private:
	void InitializeBezier();
private:
	int damage;
	float t;
	Vector3 end;
	Bezier bezier;
};