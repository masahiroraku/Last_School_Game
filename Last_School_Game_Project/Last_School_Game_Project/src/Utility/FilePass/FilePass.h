#pragma once

/**
 * @file FilePass.h
 * @brief アセットフォルダ定義ファイル
 * @author 阿曽
 * @date Unknown
 */

#include<string>

 //! FilePassの名前空間
namespace FilePass {
	//!アセットフォルダの階層
	static const std::string RootPass = "Assets/";
	//!アセットフォルダ　+　モデルフォルダの階層
	static const std::string ModelFile = RootPass + "Models/";
	//!アセットフォルダ　+　ゲームデータフォルダの階層
	static const std::string DataFile = RootPass + "Datas/";
	//!アセットフォルダ　+　テクスチャフォルダの階層
	static const std::string TextureFile = RootPass + "Textures/";
	//!アセットフォルダ　+　フォントフォルダの階層
	static const std::string FontFile = RootPass + "Fonts/";
	//!アセットフォルダ　+　サウンドフォルダの階層
	static const std::string SoundFile = RootPass + "Sounds/";
	//!アセットフォルダ　+　エフェクトフォルダの階層
	static const std::string EffectFile = RootPass + "Effects/";
}