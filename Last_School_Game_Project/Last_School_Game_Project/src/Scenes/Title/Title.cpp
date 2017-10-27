#include "Title.h"
#include "Scenes/Base/Scene.h"
#include"World/World.h"
#include"Renderer/Renderer.h"

Title::Title(WorldPtr & world)
	: world(world)
	, renderer(nullptr)
	, isEnd_(false)
{
}

Title::~Title()
{
}

void Title::LoadAssets()
{
	renderer = Renderer::GetInstance();
	renderer->LoadTexture(Assets::Texture::Fade, "fade.bmp");

}

void Title::Initialize()
{
	isEnd_ = false;
	world->Initialize();

}

void Title::Update(float deltaTime)
{
	world->Update(deltaTime);
}

void Title::Draw() const
{
	world->Draw(*renderer);
}

bool Title::IsEnd() const
{
	return isEnd_;
}

Scene Title::Next() const
{
	return Scene::Menu;
}

void Title::Finalize()
{
	world->Finalize();
	renderer->Clear();
}

void Title::DrawFade(float alpha) const
{
	renderer->DrawTexture(Assets::Texture::Fade, Vector2(0, 0), Vector2(0, 0), Vector2(1, 1), 0.0f, Color(0, 0, 0, alpha));
}

void Title::HandleMessage(EventMessage message, void * param)
{
}
