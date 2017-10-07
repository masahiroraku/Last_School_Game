#include "Shield.h"
#include"Collision/Capsule/Capsule.h"

Shield::Shield(IWorld & world, SkinningMesh & parentMesh)
	: Actor(world, "Sword", Vector3::Zero, std::make_shared<Capsule>(Vector3(), Vector3(), 1.0f))
	, mesh(Assets::Model::Shield)
	, parentMesh(parentMesh)
{
	matrix = parentMesh.GetBoneWorldMatrix(24);
	position = parentMesh.GetBonePosition(24);
}

Shield::~Shield()
{
}

void Shield::OnUpdate(float deltaTime)
{
	matrix = parentMesh.GetBoneWorldMatrix(24);
	position = parentMesh.GetBonePosition(24);
}

void Shield::OnDraw(Renderer & renderer)
{
	mesh.Draw(renderer, GetMatrix());
}

void Shield::OnCollide(const HitInfo & hitInfo)
{
}

void Shield::OnMessage(EventMessage message, void * param)
{
}
