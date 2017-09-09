#include "EffectManager.h"

EffectManager::EffectManager()
	: g_manager(nullptr)
	, g_renderer(nullptr)
	, g_sound(nullptr)
	, g_device(nullptr)
	, g_context(nullptr)
	, g_xa2(nullptr)
	, g_xa2_master(nullptr)
	, g_effect_handle(0)
	, g_effects()
{
}

EffectManager::~EffectManager()
{
}

EffectManager & EffectManager::GetInstance()
{
	static EffectManager instance;
	return instance;
}

int EffectManager::Initialize(int spriteMaxCount, int instanceMaxCount, int voiceMaxCount)
{
	End();

	g_device = (ID3D11Device*)GetUseDirect3D11Device();
	g_context = (ID3D11DeviceContext*)GetUseDirect3D11DeviceContext();

	g_renderer = EffekseerRendererDX11::Renderer::Create(g_device, g_context, spriteMaxCount);

	g_manager = Effekseer::Manager::Create(instanceMaxCount);

	g_manager->SetSpriteRenderer(g_renderer->CreateSpriteRenderer());
	g_manager->SetRibbonRenderer(g_renderer->CreateRibbonRenderer());
	g_manager->SetRingRenderer(g_renderer->CreateRingRenderer());
	g_manager->SetTrackRenderer(g_renderer->CreateTrackRenderer());
	g_manager->SetModelRenderer(g_renderer->CreateModelRenderer());

	g_manager->SetTextureLoader(g_renderer->CreateTextureLoader());
	g_manager->SetModelLoader(g_renderer->CreateModelLoader());

	g_manager->SetCoordinateSystem(Effekseer::CoordinateSystem::LH);

	XAudio2Create(&g_xa2);
	g_xa2->CreateMasteringVoice(&g_xa2_master);

	g_sound = EffekseerSound::Sound::Create(g_xa2, voiceMaxCount, voiceMaxCount);
	g_manager->SetSoundPlayer(g_sound->CreateSoundPlayer());
	g_manager->SetSoundLoader(g_sound->CreateSoundLoader());

	return 0;
}

void EffectManager::Update(float deltaTime)
{
	g_manager->Update(deltaTime);
}

void EffectManager::Draw()
{
	g_renderer->BeginRendering();
	g_manager->Draw();
	g_renderer->EndRendering();
}

void EffectManager::End()
{

	for (auto effect : g_effects) {
		effect.second->Release();
	}
	g_effects.clear();
	g_effect_handle = 0;

	if (g_manager != nullptr) {
		g_manager->Destroy();
		g_manager = nullptr;
	}

	if (g_sound != nullptr) {
		g_sound->Destory();
		g_sound = nullptr;
	}

	if (g_renderer != nullptr) {
		g_renderer->Destory();
		g_renderer = nullptr;
	}

	if (g_xa2_master != nullptr) {
		g_xa2_master->DestroyVoice();
		g_xa2_master = nullptr;
	}

	if (g_xa2 != nullptr) {
		g_xa2->Release();
		g_xa2 = nullptr;
	}

}

int EffectManager::Load(const char * fileName)
{
	
	const auto utf16_file_name = ConvertSjisToUTF16(fileName);

	const auto effect = Effekseer::Effect::Create(g_manager, (const EFK_CHAR*)utf16_file_name);

	delete[] utf16_file_name;

	if (effect == nullptr) {
		return -1;
	}

	g_effects[g_effect_handle] = effect;
	return g_effect_handle++;
}

void EffectManager::Delete(int effectHandle)
{
	if (g_effects.count(effectHandle) > 0) {
		g_effects[effectHandle]->Release();
		g_effects.erase(effectHandle);
	}
}

void EffectManager::DeleteAll()
{
	for (auto effect : g_effects) {
		effect.second->Release();
	}
	g_effects.clear();
	g_effect_handle = 0;
}

int EffectManager::Play(int effectHandle, float x, float y, float z)
{
	if (g_effects.count(effectHandle) > 0) {
		return g_manager->Play(g_effects[effectHandle], x, y, z);
	}
	return -1;
}

void EffectManager::Sync3DSetting()
{
	g_renderer->SetCameraMatrix(ConvertMATRIX_To_Matrix44(GetCameraViewMatrix()));
	g_renderer->SetProjectionMatrix(ConvertMATRIX_To_Matrix44(GetCameraProjectionMatrix()));
}

Effekseer::Matrix43 EffectManager::ConvertMATRIX_To_Matrix43(const MATRIX & mat)
{
	Effekseer::Matrix43 m;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			m.Value[i][j] = mat.m[i][j];
		}
	}
	return m;
}

Effekseer::Matrix44 EffectManager::ConvertMATRIX_To_Matrix44(const MATRIX & mat)
{
	Effekseer::Matrix44 m;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m.Values[i][j] = mat.m[i][j];
		}
	}
	return m;
}

Effekseer::Matrix43 EffectManager::ConvertMatrix4_To_Matrix43(const Matrix4 & mat)
{
	Effekseer::Matrix43 m;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			m.Value[i][j] = mat.m[i][j];
		}
	}
	return m;
}

Effekseer::Matrix44 EffectManager::ConvertMatrix4_To_Matrix44(const Matrix4 & mat)
{
	Effekseer::Matrix44 m;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m.Values[i][j] = mat.m[i][j];
		}
	}
	return m;
}

MATRIX EffectManager::ConvertMatrix44_To_MATRIX(const Effekseer::Matrix44 & mat)
{
	MATRIX m;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m.m[i][j] = mat.Values[i][j];
		}
	}
	return m;
}

wchar_t * EffectManager::ConvertSjisToUTF16(const char * sjis)
{
	//Shift-JIS•¶Žš—ñ‚©‚çUTF-16‚É•ÏŠ·‚µ‚½‚Æ‚«‚Ì•¶Žš—ñ’·‚ð‹‚ß‚é
	const int length = MultiByteToWideChar(CP_ACP, 0, sjis, strlen(sjis), NULL, 0);

	//UTF-16•¶Žš—ñ‚Ì—Ìˆæ‚ðŠm•Û‚·‚é
	wchar_t* result = new wchar_t[length * 2 + 2];

	if (result != NULL) {
		//\0‚ð‘ã“ü
		result[length] = '\0';
		//Shift-JIS•¶Žš—ñ‚©‚çUTF-16‚É•ÏŠ·‚·‚éB
		MultiByteToWideChar(CP_ACP, 0, sjis, strlen(sjis), result, length);
	}

	return result;
}

void EffectManager::Stop(int playingEffectHandle)
{
	g_manager->StopEffect(playingEffectHandle);
}

bool EffectManager::IsPlay(int playingEffectHandle)
{
	return g_manager->Exists(playingEffectHandle);
}

void EffectManager::SetPosition(int playingEffectHandle, float x, float y, float z)
{
	g_manager->SetLocation(playingEffectHandle, x, y, z);
}

void EffectManager::SetRotation(int playingEffectHandle, float x, float y, float z)
{
	g_manager->SetRotation(playingEffectHandle, x, y, z);
}

void EffectManager::SetScale(int playingEffectHandle, float x, float y, float z)
{
	g_manager->SetScale(playingEffectHandle, x, y, z);
}

void EffectManager::SetMatrix(int playingEffectHandle, const Matrix4 & matrix)
{
	g_manager->SetMatrix(playingEffectHandle, ConvertMatrix4_To_Matrix43(matrix));
}

void EffectManager::SetBaseMatrix(int playingEffectHandle, const Matrix4 & matrix)
{
	g_manager->SetBaseMatrix(playingEffectHandle, ConvertMatrix4_To_Matrix43(matrix));
}

void EffectManager::SetTargetPosition(int playingEffectHandle, float x, float y, float z)
{
	g_manager->SetTargetLocation(playingEffectHandle, x, y, z);
}

void EffectManager::SetIsDraw(int playingEffectHandle, bool isDraw)
{
	g_manager->SetShown(playingEffectHandle, isDraw);
}

void EffectManager::SetPause(int playingEffectHandle, bool pause)
{
	g_manager->SetPaused(playingEffectHandle, pause);
}

void EffectManager::CalcCulling()
{
	g_manager->CalcCulling(g_renderer->GetCameraProjectionMatrix(), false);
}
