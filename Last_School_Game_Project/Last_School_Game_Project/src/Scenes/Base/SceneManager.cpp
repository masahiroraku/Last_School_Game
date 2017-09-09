#include "SceneManager.h"
#include "SceneNull.h"
#include "Scene.h"
#include "Math/Math.h"
#include "Application/FPS/FPS.h"

//!TODO:フェードの処理を直す

SceneManager::SceneManager()
	: currentScene(std::make_shared<SceneNull>())
	, alpha(1.0f)
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Initialize() {
	Finalize();
	scenes.clear();
}

void SceneManager::Update(float deltaTime) {
	if (!currentScene->IsEnd()) {
		alpha = Math::Max(0.0f, alpha - (deltaTime / FPS::fps));
	}
	else {
		alpha = Math::Min(1.0f, alpha + (deltaTime / FPS::fps));
		if (alpha >= 1.0f) {
			Change(currentScene->Next());
		}
	}

	if (alpha <= 0.0f) {  
		//!フェードイン終了後シーンのアップデート
		currentScene->Update(deltaTime);
	}
}

void SceneManager::Draw() const {
	currentScene->Draw();
	currentScene->DrawFade(alpha);
}

void SceneManager::Finalize() {
	currentScene->Finalize();
	currentScene = std::make_shared<SceneNull>();
}

void SceneManager::Add(Scene name, const IScenePtr & scene) {
	scenes[name] = scene;
}

void SceneManager::Change(Scene name) {
	Finalize();
	alpha = 1.0f;
	currentScene = scenes[name];
	currentScene->LoadAssets();
	currentScene->Initialize();
}