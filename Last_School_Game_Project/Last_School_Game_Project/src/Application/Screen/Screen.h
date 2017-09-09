#pragma once

/**
 * @file Screen.h
 * @brief スクリーン(ウィンドウ)の定義ファイル
 * @author 阿曽
 * @date Unknown
 */


 /*! @class Screen
 *   @brief スクリーン(ウィンドウ)の設定
 */
class Screen {
public:
	//!ウィンドウの横幅
	static const float Width;
	//!ウィンドウの縦幅
	static const float Height;
	//!ウィンドウのアスペクト比
	static const float Aspect;
	//!ウィンドウをフルスクリーンにするか？
	static const bool IsWindowMode;
	//!ウィンドウの名前
	static const char* Name;
};