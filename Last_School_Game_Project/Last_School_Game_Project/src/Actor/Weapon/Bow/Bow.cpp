#include "Bow.h"

Bow::Bow(IWorld & world, SkinningMesh & parentMesh)
	: Actor(world,"Bow",Vector3::Zero,nullptr)
	, mesh(Assets::Model::Bow)
	, parentMesh(parentMesh)
{
	matrix = parentMesh.GetBoneWorldMatrix(35);
	position = parentMesh.GetBonePosition(35);
}

Bow::~Bow()
{
}

void Bow::OnUpdate(float deltaTime)
{
	matrix = parentMesh.GetBoneWorldMatrix(35);
	position = parentMesh.GetBonePosition(35);
}

void Bow::OnDraw(Renderer & renderer)
{
	mesh.Draw(renderer, GetMatrix());
}

void Bow::OnMessage(EventMessage message, void * param)
{
}
