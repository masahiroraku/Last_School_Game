#include "Pause.h"
#include"Input/Input.h"
#include"Renderer/Renderer.h"
#include"Scenes/Base/Scene.h"
#include"World/IWorld.h"
#include"Actor/Base/EventMessage.h"
#include"Sound/Sound.h"
#include"Math/Ease/Ease.h"

Pause::Pause(IWorld& world)
	: world(world)
	, isEnd(false)
	, curInput(0.0f)
	, prevInput(0.0f)
	, selectScene(Scene::None)
	, selectContaint(SelectContent::BackToGame_)
	, pauseItems()
{
}

Pause::~Pause()
{
}

void Pause::Initialize()
{
	isEnd = false;
	curInput = 0.0f;
	prevInput = 0.0f;
	selectScene = Scene::None;
	selectContaint = SelectContent::BackToGame_;

	//pauseItems[SelectContent::BackToGame_] = PauseItem(Assets::Texture::Pause_BackToGame, Vector2(256 - 64, 64));
	//pauseItems[SelectContent::Manual_] = PauseItem(Assets::Texture::Menu_Manual, Vector2(256 - 64, 128 + 64));
	//pauseItems[SelectContent::Continue_] = PauseItem(Assets::Texture::Pause_Continue, Vector2(256 - 64, 128 + 128 + 64));
	//pauseItems[SelectContent::Title_] = PauseItem(Assets::Texture::Pause_BackToTitle, Vector2(256 - 64, 128 + 128 + 128 + 64));

}

void Pause::Update(float deltaTime)
{

	//prevInput = curInput;

	//curInput = Input::GetInstance().GetVelocity().z;


	////‚±‚±C³
	////TODOF@ã‰Ÿ‚µ‚½‚ç€–Ú‚ª‰º‚É‚¢‚Á‚Ä‚µ‚Ü‚¤–â‘è
	////‰ž‹}ˆ’uFˆ—‚ð‹t‚É‘‚¢‚½B

	//if (curInput >= 0.8f) {
	//	if (prevInput >= 0.8f)
	//		return;

	//	Sound::GetInstance().PlaySE(Assets::Sound::SE_Select);

	//	selectContaint--;
	//	if (selectContaint < SelectContent::BackToGame_) {
	//		selectContaint = SelectContent::Title_;
	//	}

	//}
	//if (curInput <= -0.8f) {
	//	if (prevInput <= -0.8f)
	//		return;

	//	Sound::GetInstance().PlaySE(Assets::Sound::SE_Select);

	//	selectContaint++;
	//	selectContaint %= SelectContent::Max_Num;
	//}


	//switch (selectContaint)
	//{
	//case SelectContent::BackToGame_:
	//	if (Input::GetInstance().GetCommand(Command::Decide)) {
	//		Sound::GetInstance().PlaySE(Assets::Sound::SE_Decide);
	//		world.SendEventMessage(EventMessage::PauseEnd, nullptr);
	//		Initialize();
	//	}
	//	break;
	//case SelectContent::Continue_:
	//	if (Input::GetInstance().GetCommand(Command::Decide) && isEnd == false) {
	//		isEnd = true;
	//		Sound::GetInstance().PlaySE(Assets::Sound::SE_Decide);
	//		selectScene = Scene::GamePlay;
	//	}
	//	break;
	//case SelectContent::Title_:
	//	if (Input::GetInstance().GetCommand(Command::Decide) && isEnd == false) {
	//		Sound::GetInstance().PlaySE(Assets::Sound::SE_Decide);
	//		selectScene = Scene::Title;
	//		isEnd = true;
	//	}
	//	break;
	//default:
	//	break;
	//}

}

void Pause::Draw(Renderer & renderer) const
{
	//renderer.DrawTexture(Assets::Texture::Fade, Vector2::Zero, Vector2::Zero, Vector2::One, 0.0f, Color(0, 0, 0, 0.7f));
	//renderer.DrawTexture(Assets::Texture::Menu_Select, Vector2(64, 32 + (128 * selectContaint)));

	//for (auto& item : pauseItems) {
	//	renderer.DrawTexture(item.texture, item.position, item.center, Vector2::One,0.0f, item.color);
	//}

	//switch (selectContaint)
	//{
	//case SelectContent::BackToGame_:
	//	renderer.DrawTexture(Assets::Texture::Pause_BackToGame_Comment, Vector2(512 + 256, 360 - 32));
	//	break;
	//case SelectContent::Manual_:
	//	renderer.DrawTexture(Assets::Texture::Menu_Manual_Comment, Vector2(512 + 64, 128));
	//	break;
	//case SelectContent::Continue_:
	//	renderer.DrawTexture(Assets::Texture::Pause_Continue_Comment, Vector2(512 + 256, 360 - 32));
	//	break;
	//case SelectContent::Title_:
	//	renderer.DrawTexture(Assets::Texture::Pause_BackToTitle_Comment, Vector2(512 + 256, 360 - 32));
	//	break;
	//default:
	//	break;
	//}

}

void Pause::Finalize()
{
}

void Pause::HandleMessage(EventMessage message, void * param)
{
}

bool Pause::IsEnd() const
{
	return isEnd;
}


Scene Pause::GetSelectScene() const
{
	return selectScene;
}
