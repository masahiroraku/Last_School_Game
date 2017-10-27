#include "Menu.h"
#include "Scenes/Base/Scene.h"
#include"World/World.h"
#include"Renderer/Renderer.h"
#include"Application/GameApplication/GameApplication.h"

Menu::Menu(WorldPtr & world)
	: world(world)
	, renderer(nullptr)
	, isEnd_(false)
{
}

Menu::~Menu()
{
}

void Menu::LoadAssets()
{
	renderer = Renderer::GetInstance();
	renderer->LoadTexture(Assets::Texture::Fade, "fade.bmp");
}

void Menu::Initialize()
{
	isEnd_ = false;
	world->Initialize();
}

void Menu::Update(float deltaTime)
{
	//!この関数を呼ぶとウィンドウが閉じる
	//GameApplication::ShutDown();
	world->Update(deltaTime);
}

void Menu::Draw() const
{
	world->Draw(*renderer);
}

bool Menu::IsEnd() const
{
	return isEnd_;
}

Scene Menu::Next() const
{
	return Scene::GameMain;
}

void Menu::Finalize()
{
	world->Finalize();
	renderer->Clear();

}

void Menu::DrawFade(float alpha) const
{
	renderer->DrawTexture(Assets::Texture::Fade, Vector2(0, 0), Vector2(0, 0), Vector2(1, 1), 0.0f, Color(0, 0, 0, alpha));

}

void Menu::HandleMessage(EventMessage message, void * param)
{
}
