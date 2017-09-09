#pragma once

#include"IField.h"
#include"Mesh/StaticMesh/StaticMesh.h"
#include"Collision/CollisionMesh/CollisionMesh.h"
class Renderer;

class Field : public IField {
public:
	Field(int collisionModelHandle);
	Field();
	~Field();

	virtual bool Collision(const Line& line, HitInfo& hitInfo) override;
	virtual bool Collision(const BoundingSphere& sphere, HitInfo& hitInfo) override;
	virtual bool Collision(const Capsule& capsule, HitInfo& hitInfo) override;

	void Draw(Renderer& renderer);

private:
	void SetUpOctree();

private:
	StaticMesh mesh;
	int collisionStageHandle;
	CollisionMesh collisionMesh;
};