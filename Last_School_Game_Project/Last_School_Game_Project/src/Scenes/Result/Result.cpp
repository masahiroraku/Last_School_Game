#include "Result.h"
#include "Scenes/Base/Scene.h"
#include"World/World.h"
#include"Renderer/Renderer.h"

Result::Result(WorldPtr & world)
	: world(world)
	, renderer(nullptr)
	, isEnd_(false)
{
}

Result::~Result()
{
}

void Result::LoadAssets()
{
	renderer = Renderer::GetInstance();
	renderer->LoadTexture(Assets::Texture::Fade, "fade.bmp");
}

void Result::Initialize()
{
	isEnd_ = false;
	world->Initialize();

}

void Result::Update(float deltaTime)
{
	world->Update(deltaTime);

}

void Result::Draw() const
{
	world->Draw(*renderer);
}

bool Result::IsEnd() const
{
	return isEnd_;
}

Scene Result::Next() const
{
	return Scene::Menu;
}

void Result::Finalize()
{
	world->Finalize();
	renderer->Clear();

}

void Result::DrawFade(float alpha) const
{
	renderer->DrawTexture(Assets::Texture::Fade, Vector2(0, 0), Vector2(0, 0), Vector2(1, 1), 0.0f, Color(0, 0, 0, alpha));
}

void Result::HandleMessage(EventMessage message, void * param)
{
}
