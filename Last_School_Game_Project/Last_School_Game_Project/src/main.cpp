#include<DxLib.h>
#include"Application\GameFrame\GameFrame.h"
#include"Utility\CheckMemoryLeak\CheckMemoryLeak.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//�f�o�b�O�Ȃ烁�������[�N���m���s��
#ifdef _DEBUG
	CheckMemoryLeak checker;
#endif
	//�Q�[�����s
	return 	GameFrame().Run();
}