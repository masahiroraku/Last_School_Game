#include "GameFrame.h"
#include"Application/Screen/Screen.h"

#include"Scenes/Base/SceneManager.h"
#include"Scenes/Base/Scene.h"
#include"Scenes/Title/Title.h"
#include"Scenes/Menu/Menu.h"
#include"Scenes/GameMain/GameMain.h"
#include"Scenes/Result/Result.h"
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
	sceneManager.Add(Scene::Title, std::make_shared<GameMain>(world));
	sceneManager.Add(Scene::Menu, std::make_shared<GameMain>(world));
	sceneManager.Add(Scene::GameMain, std::make_shared<GameMain>(world));
	sceneManager.Add(Scene::Result, std::make_shared<GameMain>(world));
	sceneManager.Change(Scene::GameMain);
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