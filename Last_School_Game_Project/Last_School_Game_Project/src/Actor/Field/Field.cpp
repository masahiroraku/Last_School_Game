#include "Field.h"
#include "Renderer/Renderer.h"
#include"Collision/Collision.h"
#include"Collision/HitInfo.h"

Field::Field(int collisionModelHandle)
	: mesh(Assets::Model::Stage, Matrix4::IdentityMatrix)
	, collisionStageHandle(collisionModelHandle)
	, collisionMesh(collisionModelHandle)
{
	SetUpOctree();
}

Field::Field()
	: mesh(Assets::Model::Stage, Matrix4::IdentityMatrix)
	, collisionStageHandle(-1)
	, collisionMesh(-1)
{
}

Field::~Field()
{
}

bool Field::Collision(const Line & line, HitInfo & hitInfo)
{
	return collisionMesh.Collide_Line(line,&hitInfo.intersect,&hitInfo.normal);
}

bool Field::Collision(const BoundingSphere & sphere, HitInfo & hitInfo)
{
	return collisionMesh.Collide_Sphere(sphere, &hitInfo.intersect);
}

bool Field::Collision(const Capsule & capsule, HitInfo & hitInfo)
{
	return Collision::Octree_Capsule(collisionStageHandle, capsule, hitInfo);
}

void Field::Draw(Renderer & renderer)
{
	mesh.Draw(renderer);
}

void Field::SetUpOctree()
{
	Collision::SetUpOctree(collisionStageHandle);
}