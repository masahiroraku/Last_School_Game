#include "GameMainScene.h"
#include "Scenes/Base/Scene.h"

#include<DxLib.h>

#include"World/World.h"
#include"Actor/Base/ActorGroup.h"
#include"Actor/Camera/Camera.h"
#include"Renderer/Renderer.h"
#include"Input/Input.h"
#include"Actor/Field/Field.h"
#include"Actor/Base/EventMessage.h"
#include"Sound/Sound.h"
#include"Math/Ease/Ease.h"
#include"Effect/EffectManager.h"
#include"Utility/Utility.h"

GameMainScene::GameMainScene(WorldPtr& world)
	: isEnd_(false)
	, pause(false)
	, world(world)
	, renderer(nullptr)
	, pauseScene(*world)
{
}

GameMainScene::~GameMainScene() {
}

void GameMainScene::LoadAssets()
{
	renderer = Renderer::GetInstance();


	renderer->LoadTexture(Assets::Texture::Fade, "fade.bmp");


	renderer->Load3DModel(Assets::Model::Player, "Player/player.mv1");
	renderer->LoadAnimation(Assets::Animation::Player, "Player/playerAnime.mv1");
	renderer->Load3DModel(Assets::Model::Boss, "Bosses/dragon.mv1");
	renderer->LoadAnimation(Assets::Animation::Boss, "Bosses/dragonAnime.mv1");



#ifdef NDEBUG
	Sound::GetInstance().PlayBGM(Assets::Sound::BGM_GameMain);
#endif
}

void GameMainScene::Initialize() {

	pause = false;
	isEnd_ = false;


	world->Initialize();
	//world->AddCamera(std::make_shared<Camera>(*world));
	//world->AddField(std::make_shared<Field>(renderer->GetModelHandle(Assets::Model::CollisionStage)));

	//ActorPtr player = std::make_shared<Player>(*world, Vector3(0, 0, 0));
	//world->AddActor(ActorGroup::Player, player);

	//ActorPtr boss = std::make_shared<Boss>(*world, Vector3(0,0,8), *player);
	//world->AddActor(ActorGroup::Enemy, boss);

	//world->AddActor(ActorGroup::UI, std::make_shared<PlayerStatus>(static_cast<Player&>(*player.get())));
	//world->AddActor(ActorGroup::UI, std::make_shared<BossStatus>(static_cast<EnemyBase&>(*boss.get())));
	//world->AddActor(ActorGroup::UI, std::make_shared<RockOn>(*world));

	//!ワールドのイベントメッセージを受け取る
	world->AddEventMessageListener([&](EventMessage message, void* param) {
		HandleMessage(message, param);
	});

	pauseScene.Initialize();


}

void GameMainScene::Update(float deltaTime) {

	//if (Input::GetInstance().GetCommand(Command::Pause) && isGameEnd == false) {
	//	//Sound::GetInstance().PlaySE(Assets::Sound::SE_Decide);
	//	pause = !pause;
	//	pauseScene.Initialize();
	//}

	//if (isResultDraw) {
	//	UpdateResult(deltaTime);
	//}

	//if (!pause) {
	//	world->Update(deltaTime);
	//	EffectManager::GetInstance().Update(deltaTime);
	//	EffectManager::GetInstance().Sync3DSetting();
	//	return;
	//}


	//pauseScene.Update(deltaTime);
}

void GameMainScene::Draw() const {
	//world->Draw(*renderer);

	//EffectManager::GetInstance().Draw();

	//if (pause) {
	//	pauseScene.Draw(*renderer);
	//}
	//if (isResultDraw) {
	//	DrawResult(*renderer);
	//}
}

bool GameMainScene::IsEnd() const {
	return pause == false ? isEnd_ : pauseScene.IsEnd();
}

Scene GameMainScene::Next() const {
	return pause == false ? Scene::None : pauseScene.GetSelectScene();
}

void GameMainScene::Finalize() {
	Sound::GetInstance().SoundClear();
	pauseScene.Finalize();
	world->Finalize();
	renderer->Clear();
	
}

void GameMainScene::DrawFade(float alpha) const
{
	renderer->DrawTexture(Assets::Texture::Fade, Vector2(0, 0), Vector2(0, 0), Vector2(1, 1), 0.0f,Color(0,0,0,alpha));
}

void GameMainScene::HandleMessage(EventMessage message, void * param)
{
	pauseScene.HandleMessage(message, param);

}

