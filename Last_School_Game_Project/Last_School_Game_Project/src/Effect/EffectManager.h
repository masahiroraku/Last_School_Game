#pragma once

#include<Effekseer.h>
#include<EffekseerRendererDX11.h>
#include<EffekseerSoundXAudio2.h>
#include<unordered_map>
#include<DxLib.h>
#include"Math/MathType.h"

#ifdef NDEBUG
#pragma comment(lib,"Effekseer.ReleaseMT.lib")
#pragma comment(lib,"EffekseerRendererDX11.Release.lib")
#pragma comment(lib,"EffekseerSoundXAudio2.ReleaseMT.lib")
#else
#pragma comment(lib,"Effekseer.DebugMT.lib")
#pragma comment(lib,"EffekseerRendererDX11.Debug.lib")
#pragma comment(lib,"EffekseerSoundXAudio2.DebugMT.lib")
#endif
#pragma comment(lib,"xaudio2.lib")

/**
 * @file EffectManager.h
 * @brief Effekseerをラッピングしたエフェクト管理クラス定義ファイル
 * @author 阿曽
 * @date Unknown
 */

/*! @class EffectManager
 *   @brief Effekseerをラッピングしたエフェクト管理クラス
 */
class EffectManager {
private:	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	EffectManager();	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~EffectManager();
public:	
	/// <summary>
	/// EffectManagerの参照を取得する
	/// </summary>
	/// <returns>EffectManagerの参照</returns>
	static EffectManager& GetInstance();	
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="spriteMaxCount">画面に表示する最大スプライト数</param>
	/// <param name="instanceMaxCount">生成する最大エフェクト数</param>
	/// <param name="voiceMaxCount">再生する最大音声数</param>
	/// <returns>初期化成功したかどうか</returns>
	int Initialize(int spriteMaxCount = 2048, int instanceMaxCount = 2048, int voiceMaxCount = 32);	
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="deltaTime">１秒</param>
	void Update(float deltaTime);	
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();	
	/// <summary>
	/// 終了
	/// </summary>
	void End();	
	/// <summary>
	/// エフェクトを読み込む
	/// </summary>
	/// <param name="fileName">読み込むファイル名</param>
	/// <returns>読み込みに成功したか</returns>
	int Load(const char* fileName);	
	/// <summary>
	/// エフェクトを削除
	/// </summary>
	/// <param name="effectHandle">削除するエフェクトのハンドル</param>
	void Delete(int effectHandle);	
	/// <summary>
	/// エフェクト全削除
	/// </summary>
	void DeleteAll();	
	/// <summary>
	/// エフェクトを再生する
	/// </summary>
	/// <param name="effectHandle">エフェクトハンドル</param>
	/// <param name="x">x座標</param>
	/// <param name="y">y座標</param>
	/// <param name="z">z座標</param>
	/// <returns>再生中のエフェクトハンドル</returns>
	int Play(int effectHandle, float x, float y, float z);	
	/// <summary>
	/// カメラ行列と投影行列を同期させる
	/// </summary>
    void Sync3DSetting();

	Effekseer::Matrix43 ConvertMATRIX_To_Matrix43(const MATRIX& mat);
	Effekseer::Matrix44 ConvertMATRIX_To_Matrix44(const MATRIX& mat);
	Effekseer::Matrix43 ConvertMatrix4_To_Matrix43(const Matrix4& mat);
	Effekseer::Matrix44 ConvertMatrix4_To_Matrix44(const Matrix4& mat);
	MATRIX ConvertMatrix44_To_MATRIX(const Effekseer::Matrix44& mat);
	wchar_t* ConvertSjisToUTF16(const char* sjis);

public:	
	/// <summary>
	/// エフェクトを止める
	/// </summary>
	/// <param name="playingEffectHandle">再生中のエフェクトハンドル</param>
	void Stop(int playingEffectHandle);	
	/// <summary>
	/// エフェクトが再生中かどうか
	/// </summary>
	/// <param name="playingEffectHandle">再生中のエフェクトハンドル</param>
	/// <returns>
	/// [true 再生中: false 再生していない]
	/// </returns>
	bool IsPlay(int playingEffectHandle);	
	/// <summary>
	/// エフェクトの座標を設定する
	/// </summary>
	/// <param name="playingEffectHandle">再生中のエフェクトハンドル</param>
	/// <param name="x">x座標</param>
	/// <param name="y">y座標</param>
	/// <param name="z">z座標</param>
	void SetPosition(int playingEffectHandle, float x, float y, float z);
	/// <summary>
	/// エフェクトの角度を設定する
	/// </summary>
	/// <param name="playingEffectHandle">再生中のエフェクトハンドル</param>
	/// <param name="x">x軸回転量：度数法</param>
	/// <param name="y">y軸回転量：度数法</param>
	/// <param name="z">z軸回転量：度数法</param>
	void SetRotation(int playingEffectHandle, float x, float y, float z);
	/// <summary>
	/// エフェクトの大きさを設定する
	/// </summary>
	/// <param name="playingEffectHandle">再生中のエフェクトハンドル</param>
	/// <param name="x">x軸の大きさ</param>
	/// <param name="y">y軸の大きさ</param>
	/// <param name="z">z軸の大きさ</param>
	void SetScale(int playingEffectHandle, float x, float y, float z);	
	/// <summary>
	/// エフェクトに姿勢行列を設定する
	/// </summary>
	/// <param name="playingEffectHandle">再生中のエフェクトハンドル</param>
	/// <param name="matrix">姿勢行列</param>
	void SetMatrix(int playingEffectHandle, const Matrix4& matrix);	
	/// <summary>
	/// エフェクトのローカル行列を設定する
	/// </summary>
	/// <param name="playingEffectHandle">再生中のエフェクトハンドル</param>
	/// <param name="matrix">ローカル行列</param>
	void SetBaseMatrix(int playingEffectHandle, const Matrix4& matrix);	
	void SetTargetPosition(int playingEffectHandle, float x, float y, float z);	
	/// <summary>
	/// エフェクトを描画するか設定する
	/// </summary>
	/// <param name="playingEffectHandle">再生中のエフェクトハンドル</param>
	/// <param name="isDraw">描画するかどうか</param>
	void SetIsDraw(int playingEffectHandle, bool isDraw);	
	/// <summary>
	/// エフェクトを一時停止する
	/// </summary>
	/// <param name="playingEffectHandle">再生中のエフェクトハンドル</param>
	/// <param name="pause">一時停止にするかどうか</param>
	void SetPause(int playingEffectHandle, bool pause);	
	/// <summary>
	/// カリング計算を行う
	/// </summary>
	void CalcCulling();

public:
	//!エフェクト管理クラス
	Effekseer::Manager* g_manager;
	//!描画管理クラス
	EffekseerRenderer::Renderer* g_renderer;
	//!音管理クラス
	EffekseerSound::Sound* g_sound;
	//!DirectX
	ID3D11Device* g_device;
	//!DirectX
	ID3D11DeviceContext* g_context;
	//!音楽エンジン
	IXAudio2* g_xa2;
	//!音楽エンジン
	IXAudio2MasteringVoice* g_xa2_master;
	//!エフェクトハンドル
	int g_effect_handle;
	//!エフェクトのインスタンスを保持しておく配列
	std::unordered_map<int, Effekseer::Effect*> g_effects;
};