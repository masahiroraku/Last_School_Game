#include "GameApplication.h"

#include<DxLib.h>
#include"Input\Input.h"
#include"Application/LoadData/LoadData.h"
#include"Effect/EffectManager.h"

bool GameApplication::isShutDown = false;

GameApplication::GameApplication()
	: fps()
{
}

GameApplication::GameApplication(int width, int height, const std::string & name, bool isWindowMode)
	: fps()
{
	//ウィンドウモードに変更
	ChangeWindowMode(isWindowMode);
	//ウィンドウの大きさを設定
	SetGraphMode(width, height, 32);
	//ウィンドウの名前を設定
	SetMainWindowText(name.c_str());
	//フルシーンアンチエイリアスを設定
	SetFullSceneAntiAliasingMode(4, 2);
#if NDEBUG
	//ログを出さない
	SetOutApplicationLogValidFlag(FALSE);
#endif

}

GameApplication::~GameApplication()
{
}

int GameApplication::Run()
{
	//DXLIB初期化
	if (DxLibInit() == false) {
		return -1;
	}


	//初期値データ読み込み
	LoadData::GetInstance().Load();

	Initialize();

	//ゲームループ
	while (IsShutDown())
	{

		Input::GetInstance().Update();
		fps.Update();
		Update(fps.GetdeltaTime());

		Draw();
#ifdef _DEBUG
		fps.Draw();
#endif

		fps.Wait();
	}


	Finalize();
	//DXLIB終了
	DxLibEnd();

	return 0;
}

void GameApplication::ShutDown()
{
	isShutDown = true;
}

bool GameApplication::DxLibInit() {


	//DxLibの初期化
	if (DxLib_Init() == -1) {
		return false;
	}



	//裏画面に描画設定
	SetDrawScreen(DX_SCREEN_BACK);

	//Effekseerの初期化
	EffectManager::GetInstance().Initialize();

	//Zバッファを有効にする
	SetUseZBuffer3D(TRUE);
	//Zバッファへの書き込みを有効にする。
	SetWriteZBuffer3D(TRUE);

	return true;
}


void GameApplication::DxLibEnd() {
	//Effekseerの終了
	EffectManager::GetInstance().End();
	//DxLibの終了
	DxLib_End();
}


bool GameApplication::IsShutDown() {
	//裏画面描画　＆＆　ウィンドウズのメッセージ処理　＆＆　画面を消す　＆＆　シャットダウンキーが押されたら閉じる
	return ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && Input::GetInstance().GetCommand(Command::ShutDown) == false && isShutDown == false;
}