#include<DxLib.h>
#include"Application\GameFrame\GameFrame.h"
#include"Utility\CheckMemoryLeak\CheckMemoryLeak.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//デバッグならメモリリーク検知を行う
#ifdef _DEBUG
	CheckMemoryLeak checker;
#endif
	//ゲーム実行
	return 	GameFrame().Run();
}