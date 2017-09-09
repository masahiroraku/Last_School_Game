#include "SceneNull.h"
#include "Scene.h"

void SceneNull::LoadAssets() {
}

void SceneNull::Initialize() {
}

void SceneNull::Update(float deltaTime) {
	static_cast<void>(deltaTime);
}

void SceneNull::Draw() const {
}

bool SceneNull::IsEnd() const {
	return false;
}

Scene SceneNull::Next() const {
	return Scene::None;
}

void SceneNull::Finalize() {
}

void SceneNull::DrawFade(float alpha) const {
	static_cast<void>(alpha);
}