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
 * @brief Effekseer�����b�s���O�����G�t�F�N�g�Ǘ��N���X��`�t�@�C��
 * @author ���]
 * @date Unknown
 */

/*! @class EffectManager
 *   @brief Effekseer�����b�s���O�����G�t�F�N�g�Ǘ��N���X
 */
class EffectManager {
private:	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	EffectManager();	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~EffectManager();
public:	
	/// <summary>
	/// EffectManager�̎Q�Ƃ��擾����
	/// </summary>
	/// <returns>EffectManager�̎Q��</returns>
	static EffectManager& GetInstance();	
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="spriteMaxCount">��ʂɕ\������ő�X�v���C�g��</param>
	/// <param name="instanceMaxCount">��������ő�G�t�F�N�g��</param>
	/// <param name="voiceMaxCount">�Đ�����ő剹����</param>
	/// <returns>�����������������ǂ���</returns>
	int Initialize(int spriteMaxCount = 2048, int instanceMaxCount = 2048, int voiceMaxCount = 32);	
	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name="deltaTime">�P�b</param>
	void Update(float deltaTime);	
	/// <summary>
	/// �`��
	/// </summary>
	void Draw();	
	/// <summary>
	/// �I��
	/// </summary>
	void End();	
	/// <summary>
	/// �G�t�F�N�g��ǂݍ���
	/// </summary>
	/// <param name="fileName">�ǂݍ��ރt�@�C����</param>
	/// <returns>�ǂݍ��݂ɐ���������</returns>
	int Load(const char* fileName);	
	/// <summary>
	/// �G�t�F�N�g���폜
	/// </summary>
	/// <param name="effectHandle">�폜����G�t�F�N�g�̃n���h��</param>
	void Delete(int effectHandle);	
	/// <summary>
	/// �G�t�F�N�g�S�폜
	/// </summary>
	void DeleteAll();	
	/// <summary>
	/// �G�t�F�N�g���Đ�����
	/// </summary>
	/// <param name="effectHandle">�G�t�F�N�g�n���h��</param>
	/// <param name="x">x���W</param>
	/// <param name="y">y���W</param>
	/// <param name="z">z���W</param>
	/// <returns>�Đ����̃G�t�F�N�g�n���h��</returns>
	int Play(int effectHandle, float x, float y, float z);	
	/// <summary>
	/// �J�����s��Ɠ��e�s��𓯊�������
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
	/// �G�t�F�N�g���~�߂�
	/// </summary>
	/// <param name="playingEffectHandle">�Đ����̃G�t�F�N�g�n���h��</param>
	void Stop(int playingEffectHandle);	
	/// <summary>
	/// �G�t�F�N�g���Đ������ǂ���
	/// </summary>
	/// <param name="playingEffectHandle">�Đ����̃G�t�F�N�g�n���h��</param>
	/// <returns>
	/// [true �Đ���: false �Đ����Ă��Ȃ�]
	/// </returns>
	bool IsPlay(int playingEffectHandle);	
	/// <summary>
	/// �G�t�F�N�g�̍��W��ݒ肷��
	/// </summary>
	/// <param name="playingEffectHandle">�Đ����̃G�t�F�N�g�n���h��</param>
	/// <param name="x">x���W</param>
	/// <param name="y">y���W</param>
	/// <param name="z">z���W</param>
	void SetPosition(int playingEffectHandle, float x, float y, float z);
	/// <summary>
	/// �G�t�F�N�g�̊p�x��ݒ肷��
	/// </summary>
	/// <param name="playingEffectHandle">�Đ����̃G�t�F�N�g�n���h��</param>
	/// <param name="x">x����]�ʁF�x���@</param>
	/// <param name="y">y����]�ʁF�x���@</param>
	/// <param name="z">z����]�ʁF�x���@</param>
	void SetRotation(int playingEffectHandle, float x, float y, float z);
	/// <summary>
	/// �G�t�F�N�g�̑傫����ݒ肷��
	/// </summary>
	/// <param name="playingEffectHandle">�Đ����̃G�t�F�N�g�n���h��</param>
	/// <param name="x">x���̑傫��</param>
	/// <param name="y">y���̑傫��</param>
	/// <param name="z">z���̑傫��</param>
	void SetScale(int playingEffectHandle, float x, float y, float z);	
	/// <summary>
	/// �G�t�F�N�g�Ɏp���s���ݒ肷��
	/// </summary>
	/// <param name="playingEffectHandle">�Đ����̃G�t�F�N�g�n���h��</param>
	/// <param name="matrix">�p���s��</param>
	void SetMatrix(int playingEffectHandle, const Matrix4& matrix);	
	/// <summary>
	/// �G�t�F�N�g�̃��[�J���s���ݒ肷��
	/// </summary>
	/// <param name="playingEffectHandle">�Đ����̃G�t�F�N�g�n���h��</param>
	/// <param name="matrix">���[�J���s��</param>
	void SetBaseMatrix(int playingEffectHandle, const Matrix4& matrix);	
	void SetTargetPosition(int playingEffectHandle, float x, float y, float z);	
	/// <summary>
	/// �G�t�F�N�g��`�悷�邩�ݒ肷��
	/// </summary>
	/// <param name="playingEffectHandle">�Đ����̃G�t�F�N�g�n���h��</param>
	/// <param name="isDraw">�`�悷�邩�ǂ���</param>
	void SetIsDraw(int playingEffectHandle, bool isDraw);	
	/// <summary>
	/// �G�t�F�N�g���ꎞ��~����
	/// </summary>
	/// <param name="playingEffectHandle">�Đ����̃G�t�F�N�g�n���h��</param>
	/// <param name="pause">�ꎞ��~�ɂ��邩�ǂ���</param>
	void SetPause(int playingEffectHandle, bool pause);	
	/// <summary>
	/// �J�����O�v�Z���s��
	/// </summary>
	void CalcCulling();

public:
	//!�G�t�F�N�g�Ǘ��N���X
	Effekseer::Manager* g_manager;
	//!�`��Ǘ��N���X
	EffekseerRenderer::Renderer* g_renderer;
	//!���Ǘ��N���X
	EffekseerSound::Sound* g_sound;
	//!DirectX
	ID3D11Device* g_device;
	//!DirectX
	ID3D11DeviceContext* g_context;
	//!���y�G���W��
	IXAudio2* g_xa2;
	//!���y�G���W��
	IXAudio2MasteringVoice* g_xa2_master;
	//!�G�t�F�N�g�n���h��
	int g_effect_handle;
	//!�G�t�F�N�g�̃C���X�^���X��ێ����Ă����z��
	std::unordered_map<int, Effekseer::Effect*> g_effects;
};