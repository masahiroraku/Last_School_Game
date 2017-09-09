#include "GameFrame.h"
#include"Application/Screen/Screen.h"

#include"Scenes/Base/SceneManager.h"
#include"Scenes/Base/Scene.h"
#include"Scenes/GameMain/GameMainScene.h"
#include"World/World.h"

GameFrame::GameFrame()
	: GameApplication(Screen::Width, Screen::Height, Screen::Name , Screen::IsWindowMode)
	, sceneManager()
	, world()
{
}

GameFrame::~GameFrame()
{
}

void GameFrame::Initialize()
{
	world = std::make_shared<World>();
	sceneManager.Initialize();
	sceneManager.Add(Scene::GamePlay, std::make_shared<GameMainScene>(world));
	sceneManager.Change(Scene::GamePlay);
}

void GameFrame::Update(float deltaTime)
{
	sceneManager.Update(deltaTime);
}

void GameFrame::Draw()
{
	sceneManager.Draw();
}

void GameFrame::Finalize()
{
	sceneManager.Finalize();
}