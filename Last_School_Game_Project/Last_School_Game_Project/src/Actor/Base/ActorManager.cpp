#include "ActorManager.h"

#include "Actor.h"
#include"Renderer/Renderer.h"
#include "ActorGroup.h"

ActorManager::ActorManager()
	: root("Root")
{
}

void ActorManager::Initialize() {
	root.ClearChildren();
	RegisterGroup();
	root.Initialize();
}

void ActorManager::Update(float deltaTime) {
	root.Update(deltaTime);
	Collide();
	root.RemoveChildren();
}

void ActorManager::Draw(Renderer& renderer) {
	root.Draw(renderer);
}

void ActorManager::Finalize() {
	root.Finalize();
	root.ClearChildren();
	actors.clear();
}

void ActorManager::AddActor(ActorGroup group, const ActorPtr& actor) {
	actors[group]->AddChild(actor);
}

void ActorManager::AddGroup(ActorGroup group, const std::string& name, const ActorPtr& actor ) {
	ActorPtr target = actor == nullptr ? std::make_shared<Actor>(name) : actor;

	actors[group] = target;
	root.AddChild(actors[group]);
}

void ActorManager::HandleMessage(EventMessage message, void * param)
{
	root.HandleMessage(message, param);
}

ActorPtr ActorManager::FindActor(const std::string& name) {
	return root.FindChildren(name);
}

ActorPtr ActorManager::FindActor(ActorGroup group, const std::string& name) {
	if (actors[group]->GetName() == name)
		return actors[group];
	return actors[group]->FindChildren(name);
}

ActorPtr ActorManager::GetRoot(ActorGroup group)
{
	return actors[group];
}

void ActorManager::RegisterGroup() {
	AddGroup(ActorGroup::UI, "UIRoot");
	AddGroup(ActorGroup::Effect, "EffectRoot");
	AddGroup(ActorGroup::Player, "PlayerRoot");
	AddGroup(ActorGroup::Enemy, "EnemyRoot");
	AddGroup(ActorGroup::Weapon, "WeaponRoot");
	AddGroup(ActorGroup::Stage, "StageRoot");
}

void ActorManager::Collide() {
	actors[ActorGroup::Enemy]->CollideChildren(*actors[ActorGroup::Player]);
	actors[ActorGroup::Player]->CollideChildren(*actors[ActorGroup::Enemy]);
	actors[ActorGroup::Weapon]->CollideChildren(*actors[ActorGroup::Player]);
	actors[ActorGroup::Enemy]->CollideChildren(*actors[ActorGroup::Weapon]);
	actors[ActorGroup::Enemy]->CollideSibling();
	actors[ActorGroup::Player]->CollideChildren(*actors[ActorGroup::Stage]);
	actors[ActorGroup::Weapon]->CollideChildren(*actors[ActorGroup::Stage]);
	actors[ActorGroup::Enemy]->CollideChildren(*actors[ActorGroup::Stage]);
}