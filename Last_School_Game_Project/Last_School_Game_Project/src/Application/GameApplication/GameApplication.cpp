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
	//�E�B���h�E���[�h�ɕύX
	ChangeWindowMode(isWindowMode);
	//�E�B���h�E�̑傫����ݒ�
	SetGraphMode(width, height, 32);
	//�E�B���h�E�̖��O��ݒ�
	SetMainWindowText(name.c_str());
	//�t���V�[���A���`�G�C���A�X��ݒ�
	SetFullSceneAntiAliasingMode(4, 2);
#if NDEBUG
	//���O���o���Ȃ�
	SetOutApplicationLogValidFlag(FALSE);
#endif

}

GameApplication::~GameApplication()
{
}

int GameApplication::Run()
{
	//DXLIB������
	if (DxLibInit() == false) {
		return -1;
	}


	//�����l�f�[�^�ǂݍ���
	LoadData::GetInstance().Load();

	Initialize();

	//�Q�[�����[�v
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
	//DXLIB�I��
	DxLibEnd();

	return 0;
}

void GameApplication::ShutDown()
{
	isShutDown = true;
}

bool GameApplication::DxLibInit() {


	//DxLib�̏�����
	if (DxLib_Init() == -1) {
		return false;
	}



	//����ʂɕ`��ݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	//Effekseer�̏�����
	EffectManager::GetInstance().Initialize();

	//Z�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(TRUE);
	//Z�o�b�t�@�ւ̏������݂�L���ɂ���B
	SetWriteZBuffer3D(TRUE);

	return true;
}


void GameApplication::DxLibEnd() {
	//Effekseer�̏I��
	EffectManager::GetInstance().End();
	//DxLib�̏I��
	DxLib_End();
}


bool GameApplication::IsShutDown() {
	//����ʕ`��@�����@�E�B���h�E�Y�̃��b�Z�[�W�����@�����@��ʂ������@�����@�V���b�g�_�E���L�[�������ꂽ�����
	return ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && Input::GetInstance().GetCommand(Command::ShutDown) == false && isShutDown == false;
}