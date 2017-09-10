#include "World.h"
#include "Actor/Base/ActorGroup.h"
#include"Actor/Camera/Camera.h"
#include"Actor/Field/Field.h"
#include"Actor/Base/EventMessage.h"

World::World()
	: actorManager()
	, camera()
	, field()
	, listener([](EventMessage, void*) {}) {
}

World::~World() {
}

void World::Initialize() {
	actorManager.Initialize();
}
void World::Update(float deltaTime) {
	camera->Update(deltaTime);
	actorManager.Update(deltaTime);
}

void World::Draw(Renderer& renderer) {
	camera->Draw(renderer);
	//field->Draw(renderer);
	actorManager.Draw(renderer);

}

void World::Finalize() {
	actorManager.Finalize();
}

void World::AddCamera(const CameraPtr& camera) {
	this->camera = camera;
}

ICamera& World::GetCamera() {
	return *camera;
}

void World::AddField(const FieldPtr & field) {
	this->field = field;
}

IField & World::GetField() const {
	return *field;
}

void World::AddActor(ActorGroup group, const ActorPtr& actor) {
	actorManager.AddActor(group, actor);
}

ActorPtr World::FindActor(const std::string& name) {
	return actorManager.FindActor(name);
}

ActorPtr World::FindActor(ActorGroup group, const std::string& name) {
	return actorManager.FindActor(group, name);
}

ActorPtr World::GetRoot(ActorGroup group) {
	return actorManager.GetRoot(group);
}

void World::SendEventMessage(EventMessage message, void * param) {
	listener(message, param);
	actorManager.HandleMessage(message, param);
	camera->HandleMessage(message, param);
}

void World::AddEventMessageListener(std::function<void(EventMessage, void*)> listener) {
	this->listener = listener;
}

