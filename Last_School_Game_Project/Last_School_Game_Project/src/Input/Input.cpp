#include"Input/Input.h"
#include<DxLib.h>
#include <math.h>


Input::Input() 
	: VelocityValue(1.0f)
	, curXinput()
	, preXinput()
{
	InitializeKeys();
	RegistFunc();
}

Input::~Input() {
}

Input & Input::GetInstance() {
	static Input instance;
	return instance;
}

void Input::RegistFunc() {
	//シャットダウン
	commandFunc[0] = [&](void)->bool {
		return (IsKeyBoardDown(KEY_INPUT_ESCAPE)) || (IsGamePadState(XboxGamePad::Start) && IsGamePadState(XboxGamePad::Back)); 
	}; 
	//剣攻撃																		
	commandFunc[1] = [&](void)->bool {
		return IsKeyBoardDown(KEY_INPUT_SPACE) || IsGamePadDown(XboxGamePad::X);
	};
	//走り																		
	commandFunc[2] = [&](void)->bool {
		return IsKeyBoardState(KEY_INPUT_LSHIFT) || IsGamePadState(XboxGamePad::A);
	};
	//ジャンプ																		
	commandFunc[3] = [&](void)->bool {
		return IsKeyBoardDown(KEY_INPUT_Z) || IsGamePadDown(XboxGamePad::Y);
	};
	//ガード																	
	commandFunc[4] = [&](void)->bool {
		return IsKeyBoardState(KEY_INPUT_Q) || IsGamePadState(XboxGamePad::Left_Shoulder);
	};
	//矢を射る																
	commandFunc[5] = [&](void)->bool {
		return IsKeyBoardState(KEY_INPUT_Z) || IsGamePadState(XboxGamePad::Right_Shoulder);
	};

	axisFunc[0] = [&](void)->float {return (IsConnectGamePad() == true) ? GetGamePadLeftStick().y : GetVertical(); };
	axisFunc[1] = [&](void)->float {return (IsConnectGamePad() == true) ? GetGamePadLeftStick().x : GetHorizontal(); };
	axisFunc[2] = [&](void)->float {return (IsConnectGamePad() == true) ? GetGamePadRightStick().y : GetVertical2(); };
	axisFunc[3] = [&](void)->float {return (IsConnectGamePad() == true) ? GetGamePadRightStick().x : GetHorizontal2(); };
}

bool Input::GetCommand(Command command) {
	return commandFunc[static_cast<int>(command)]();
}

float Input::GetAxis(Axis axis)
{
	return axisFunc[static_cast<int>(axis)]();
}

void Input::InitializeKeys() {
	//キーが押されたかどうかを格納する配列を初期化
	
	//押されていない　ニュートラル
	static const int NotPushed = 0;

	curKeys.fill(NotPushed);
	preKeys.fill(NotPushed);
}

bool Input::IsConnectGamePad() {
	//1台以上接続されていたらtrue
	return (GetJoypadNum() != 0);
}

bool Input::IsGamePadUp(XboxGamePad button)
{
	int index = static_cast<int>(button);
	return (!curXinput.Buttons[index] && preXinput.Buttons[index]);
}

bool Input::IsGamePadDown(XboxGamePad button)
{
	int index = static_cast<int>(button);
	return (curXinput.Buttons[index] && !preXinput.Buttons[index]);
}

bool Input::IsGamePadState(XboxGamePad button)
{
	static const int HoldPushButton = 1;
	int index = static_cast<int>(button);
	return curXinput.Buttons[index] == HoldPushButton;
}

unsigned char Input::GetGamePadLeftTrigger()
{
	return curXinput.LeftTrigger;
}

unsigned char Input::GetGamePadRightTrigger()
{
	return curXinput.RightTrigger;
}

Vector2 Input::GetGamePadLeftStick()
{
	float x = curXinput.ThumbLX / 10000.0f;
	float y = curXinput.ThumbLY / 10000.0f;
	float x_ = x / 3.28f;
	float y_ = y / 3.28f;

	x = (Math::Abs(x_) < 0.3f) ? 0.0f : x_;
	y = (Math::Abs(y_) < 0.3f) ? 0.0f : y_;

	return Vector2(x,y);
}

Vector2 Input::GetGamePadRightStick()
{
	float x = curXinput.ThumbRX / 10000.0f;
	float y = curXinput.ThumbRY / 10000.0f;
	float x_ = x / 3.28f;
	float y_ = y / 3.28f;

	x = (Math::Abs(x_) < 0.3f) ? 0.0f : x_;
	y = (Math::Abs(y_) < 0.3f) ? 0.0f : y_;
	return Vector2(x, y);
}


void Input::VibrationStart(GamePad player, int vibrationPower, int vibrationTime)
{
	StartJoypadVibration(static_cast<int>(player), vibrationPower, vibrationTime);
}

void Input::VibrationStop(GamePad player)
{
	StopJoypadVibration(static_cast<int>(player));
}


void Input::Update() {
	//更新する前に　１フレーム前の状態を保存
	preKeys.swap(curKeys);
	//現在のキー情報を更新
	GetHitKeyStateAll(curKeys.data());

	//更新する前に　１フレーム前の状態を保存
	std::memcpy(preXinput.Buttons, curXinput.Buttons, sizeof(char) * MaxXboxButtonNum);

	//ここ１Pコン固定　対戦ゲームならここ改良すべき
	GetJoypadXInputState(DX_INPUT_PAD1, &curXinput);
}

Vector3 Input::GetVelocity()
{
	return (IsConnectGamePad() == true) ? Vector3(GetGamePadLeftStick().x, 0, GetGamePadLeftStick().y) : Vector3(GetHorizontal(), 0, GetVertical());
}


bool Input::IsKeyBoardUp(int key) {
	return (!curKeys[key] && preKeys[key]);
}

bool Input::IsKeyBoardDown(int key) {
	return (curKeys[key] && !preKeys[key]);
}

bool Input::IsKeyBoardState(int key) {
	static const int HoldPushKey = 1;
	return curKeys[key] == HoldPushKey;
}

float Input::GetVertical()
{
	float value = 0.0f;

	if (IsKeyBoardState(KEY_INPUT_W)) {
		value = VelocityValue;
	}
	if (IsKeyBoardState(KEY_INPUT_S)) {
		value = -VelocityValue;
	}

	return value;
}

float Input::GetHorizontal()
{
	float value = 0.0f;
	if (IsKeyBoardState(KEY_INPUT_A)) {
		value = -VelocityValue;
	}
	if (IsKeyBoardState(KEY_INPUT_D)) {
		value = VelocityValue;
	}
	return value;
}

float Input::GetVertical2()
{
	float value = 0.0f;

	if (IsKeyBoardState(KEY_INPUT_UP)) {
		value = VelocityValue;
	}
	if (IsKeyBoardState(KEY_INPUT_DOWN)) {
		value = -VelocityValue;
	}
	return value;
}

float Input::GetHorizontal2()
{
	float value = 0.0f;

	if (IsKeyBoardState(KEY_INPUT_LEFT)) {
		value = -VelocityValue;
	}
	if (IsKeyBoardState(KEY_INPUT_RIGHT)) {
		value = VelocityValue;
	}
	return value;
}

