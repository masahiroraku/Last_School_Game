#pragma once

/**
 * @file Sound.h
 * @brief 音楽管理クラス定義ファイル
 * @author 大竹
 * @date Unknown
 */

#include"Utility/Assets.h"
#include <unordered_map>


/*! @class Sound
*   @brief 音楽管理クラス
*/
class Sound
{
private:	
	/// <summary>
	/// コンストラクタ<see cref="Sound"/>
	/// </summary>
	Sound();	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Sound();
public:
	 /// <summary>
	 /// 音楽管理クラスを取得
	 /// </summary>
	 /// <returns>音楽管理クラス</returns>
	static Sound& GetInstance();
	/// <summary>
	 /// 音楽リソースを読み込む
	 /// </summary>
	 /// <param name="id">登録した名前</param>
	 /// <param name="fileName">読み込む音楽ファイル名 wav mp3</param>
	void LoadSound(Assets::Sound id, const std::string& fileName);
	/// <summary>
	/// SEを再生
	/// </summary>
	/// <param name="id">登録した名前</param>
	/// <param name="volume">音量</param>
	void PlaySE(Assets::Sound id, float volume = 1.0f);	
	/// <summary>
	/// BGMを再生
	/// </summary>
	/// <param name="id">登録した名前</param>
	/// <param name="volume">音量</param>
	void PlayBGM(Assets::Sound id, float volume = 1.0f);
	/// <summary>
	/// 音楽の設定をしつつ再生
	/// </summary>
	/// <param name="id">登録した名前</param>
	/// <param name="mPlayType">Dxlibが定義した定数　DX_PLAYTYPE_LOOP=ループ再生　DX_PLAYTYPE_BACKBIT=1回再生</param>
	/// <param name="volume">音量</param>
	void PlaySounds(Assets::Sound id, int mPlayType, float volume = 1.0f);
	 /// <summary>
	 /// BGMを止める
	 /// </summary>
	 /// <param name="id">定義した名前</param>
	void StopBGM(Assets::Sound id);
	 /// <summary>
	 /// 音のハンドルを取得
	 /// </summary>
	 /// <param name="id">登録した名前</param>
	 /// <returns>音のハンドル</returns>
	int GetSoundHandle(Assets::Sound id);
	 /// <summary>
	 /// 登録した音リソースを削除
	 /// </summary>
	void SoundClear();


private:
	//!定義した音楽とサウンドハンドルを入れたコンテナ
	std::unordered_map<Assets::Sound, int> mSoundHandle;
};

