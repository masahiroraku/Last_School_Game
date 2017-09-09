#pragma once

#include<DxLib.h>
#include<array>
#include<functional>

#include"Math/Math.h"
#include"Math/Vector3/Vector3.h"
#include"Math/Vector2/Vector2.h"

#include"GamePad.h"
#include"Command.h"
#include"Axis.h"

/**
 * @file Input.h
 * @brief 入力管理クラス定義ヘッダー
 * @author 阿曽
 * @date Unknown
 */

 /*! @class Input
 *   @brief  入力管理クラス
 */
class Input {
private:	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Input();	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Input();

private:
	/// <summary>
	/// ゲーム用のボタン定義で押されたら行う処理を登録
	/// </summary>
	void RegistFunc();	
	/// <summary>
	/// キーボード配列の初期化
	/// </summary>
	void InitializeKeys();
public:	
	/// <summary>
	/// Inputクラスの実態を取得
	/// </summary>
	/// <returns>Inputクラスの実態</returns>
	static Input& GetInstance();
	
	/// <summary>
	/// ゲーム用のボタンが押されたか？
	/// </summary>
	/// <param name="command">ゲーム用のボタン</param>
	/// <returns>押されたか？</returns>
	bool GetCommand(Command command);

	/// <summary>
	/// 横軸(Horizontal)・縦軸(Vertical)の入力値を取得できる
	/// </summary>
	/// <param name="axis">横軸(Horizontal)・縦軸(Vertical)</param>
	/// <returns>指定した軸の入力値</returns>
	float GetAxis(Axis axis);	

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// WASDキー LStickの入力された値を返す
	/// </summary>
	/// <returns>移動量(0.0 ～ 1.0)</returns>
	Vector3 GetVelocity();

	//キーボード

	/// <summary>
	/// キーボード のキーが離されたかどうか判定
	/// </summary>
	/// <param name="key">キーボード のキー</param>
	/// <returns>
	/// 離された場合は真
	/// </returns>
	bool IsKeyBoardUp(int key);
	/// <summary>
	/// キーボード のキーが押されたかどうか判定
	/// </summary>
	/// <param name="key">キーボード のキー</param>
	/// <returns>
	/// 押された場合は真
	/// </returns>
	bool IsKeyBoardDown(int key);
	/// <summary>
	/// キーボード のキーが押され続けているどうか判定
	/// </summary>
	/// <param name="key">キーボード のキー</param>
	/// <returns>
	/// 押され続けていた場合は真
	/// </returns>
	bool IsKeyBoardState(int key);

	//ゲームパッド

	/// <summary>
	/// パッドが接続されているか返す
	/// </summary>
	/// <returns>1台以上接続されているか？</returns>
	bool IsConnectGamePad();
	
	/// <summary>
	/// ゲームパッドのボタンが離されたか？
	/// </summary>
	/// <param name="button">ゲームパッドのボタン</param>
	/// <returns>
	/// 離された場合は真
	/// </returns>
	bool IsGamePadUp(XboxGamePad button);	
	/// <summary>
	/// ゲームパッドのボタンが押されたか？
	/// </summary>
	/// <param name="button">ゲームパッドのボタン</param>
	/// <returns>
	/// 押された場合は真
	/// </returns>
	bool IsGamePadDown(XboxGamePad button);	
	/// <summary>
	/// ゲームパッドのボタンが押され続けているか？
	/// </summary>
	/// <param name="button">ゲームパッドのボタン</param>
	/// <returns>
	/// 押され続けている場合は真
	/// </returns>
	bool IsGamePadState(XboxGamePad button);
	
	/// <summary>
	/// 左トリガーの押され具合を取得(0～255)
	/// </summary>
	/// <returns>押され具合</returns>
	unsigned char GetGamePadLeftTrigger();	
	/// <summary>
	/// 右トリガーの押され具合を取得(0～255)
	/// </summary>
	/// <returns>押され具合</returns>
	unsigned char GetGamePadRightTrigger();
	
	/// <summary>
	/// 左スティックの入力値を取得する
	/// </summary>
	/// <returns>左スティックの入力値</returns>
	Vector2 GetGamePadLeftStick();	
	/// <summary>
	/// 右スティックの入力値を取得する
	/// </summary>
	/// <returns>右スティックの入力値</returns>
	Vector2 GetGamePadRightStick();



	/// <summary>
	/// ゲームパッドの振動を開始する
	/// </summary>
	/// <param name="player">振動するゲームパッド</param>
	/// <param name="vibrationPower">振動の強さ(0～1000)</param>
	/// <param name="vibrationTime">振動させる時間(ミリ秒)　-1なら停止するまで振動する</param>
	void VibrationStart(GamePad player, int vibrationPower, int vibrationTime = -1);	
	/// <summary>
	/// ゲームパッドの振動を停止する
	/// </summary>
	/// <param name="player">振動を停止するゲームパッド</param>
	void VibrationStop(GamePad player);

private:
	//----RegistFunc用の関数----
	
	/// <summary>
	/// 縦軸(WSキー, LStickの上下)の入力値を取得する
	/// </summary>
	/// <returns>縦軸(WSキー, LStickの上下)の入力値</returns>
	float GetVertical();
	/// <summary>
	/// 横軸(ADキー, LStickの左右)の入力値を取得する
	/// </summary>
	/// <returns>横軸(ADキー, LStickの左右)の入力値</returns>
	float GetHorizontal();
	/// <summary>
	/// 縦軸(上下キー, RStickの上下)の入力値を取得する
	/// </summary>
	/// <returns>縦軸(上下キー, RStickの上下)の入力値</returns>
	float GetVertical2();
	/// <summary>
	/// 横軸(左右キー, RStickの左右)の入力値を取得する
	/// </summary>
	/// <returns>横軸(左右キー, RStickの左右)の入力値</returns>
	float GetHorizontal2();

private:	
	//!最大キー数
	static const int Max_Key_Num = 256;		
	
	//!キーが押されたかを格納する配列
	using Keys = std::array<char, Max_Key_Num>;

	//!キーの現在の押下状況保存
	Keys curKeys;  
	//!キーの1フレーム前の押下状況保存
	Keys preKeys;

	//!ゲームパッドの現在の入力状況を保存
	XINPUT_STATE curXinput;
	//!ゲームパッドの１フレームの入力状況を保存
	XINPUT_STATE preXinput;

	//!ゲーム用のボタンが押されたかを格納する配列
	using CommandFunc = std::array < std::function<bool(void)>, static_cast<int>(Command::Max_Of_Num)>;
	//!ゲーム用のボタンが押されたかを格納する配列	
	CommandFunc commandFunc;

	//!縦横軸の入力数値を格納する配列
	using AxisFunc = std::array< std::function<float(void)>, static_cast<int>(Axis::Max_Of_Num)>;
	
	//!縦横軸の入力数値を格納する配列
	AxisFunc axisFunc;

	//!入力数値の値
	const float VelocityValue;
};