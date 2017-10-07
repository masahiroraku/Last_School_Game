#include "Pillar.h"

Pillar::Pillar(IWorld & world, const Vector3 & position)
	: Actor(world,"Pillar",position,nullptr)
	, mesh(Assets::Model::Pillar,GetMatrix())
	, hp(120){

}

Pillar::~Pillar()
{
}

void Pillar::OnUpdate(float deltaTime)
{
}

void Pillar::OnDraw(Renderer & renderer)
{
	mesh.Draw(renderer);
}

void Pillar::OnCollide(const HitInfo & hitInfo)
{
}

void Pillar::OnMessage(EventMessage message, void * param)
{
}
