#include "Renderer.h"

#include"Utility/FilePass/FilePass.h"

#include<DxLib.h>
#include<cassert>
#include<sstream>
#include<iomanip>
#include"Math/Convert/Convert.h"
#include"Effect/EffectManager.h"
#include"Math/MathType.h"
const float Renderer::LerpTime = 15.0f;

Renderer::Renderer()
	: models()
	, animations()
	, textures()
	, fonts()
	, effects()
{
}

Renderer::~Renderer() {
	Clear();
}

Renderer* Renderer::GetInstance()
{
	static Renderer instance;
	return &instance;
}

void Renderer::LoadTexture(Assets::Texture id, const std::string & fileName)
{
	int handle = LoadGraph((FilePass::TextureFile + fileName).c_str());
	if (handle == -1) {
		assert(!"Failure to read the file.");
		return;
	}
	textures.emplace(id, handle);
}

void Renderer::LoadFont(Assets::Font id, const std::string& fileName, int edgeSize)
{
	int handle = LoadFontDataToHandle((FilePass::FontFile + fileName).c_str(),edgeSize);
	if (handle == -1) {
		assert(!"Failure to read the file.");
		return;
	}
	fonts.emplace(id, handle);
}

void Renderer::Load3DModel(Assets::Model id, const std::string & fileName)
{
	int handle = MV1LoadModel((FilePass::ModelFile + fileName).c_str());
	if (handle == -1) {
		assert(!"Failure to read the file.");
		return;
	}
	//Zソートするか？
	MV1SetUseZBuffer(handle, TRUE);
	//Zバッファーを更新するか？
	MV1SetWriteZBuffer(handle, TRUE);
	models.emplace(id, handle);
}


void Renderer::LoadAnimation(Assets::Animation id, const std::string & fileName)
{
	int handle = MV1LoadModel((FilePass::ModelFile + fileName).c_str());
	if (handle == -1) {
		assert(!"Failure to read the file.");
		return;
	}
	animations.emplace(id, handle);
}

void Renderer::LoadEffect(Assets::Effect id, const std::string & fileName)
{
	int handle = EffectManager::GetInstance().Load((FilePass::EffectFile + fileName).c_str());
	if (handle == -1) {
		assert(!"Failure to read the file.");
		return;
	}
	effects.emplace(id, handle);
}


void Renderer::DrawTexture(Assets::Texture id, const Vector2 & position, const Vector2 & center, const Vector2 & scale, float angle, const Color& color)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(color.a * 255.0f));
	SetDrawBright(color.r * 255.0f, color.g * 255.0f, color.b * 255.0f);
	DrawRotaGraph3(
		position.x, position.y,
		center.x, center.y,
		scale.x, scale.y,
		angle * Math::toRadian,
		textures[id],
		TRUE,
		FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	SetDrawBright(255.0f,255.0f,255.0f);
}

void Renderer::DrawRectangle(Assets::Texture id, const Vector2 & position, const Rect & rect, float alpha)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(alpha * 255.0f));
	DrawRectGraph(
		position.x, position.y,
		rect.left, rect.top,
		rect.right, rect.bottom,
		textures[id],
		TRUE,
		FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void Renderer::DrawFont(Assets::Font id, const std::string & text, const Vector2 & position, const Color & color)
{
	DrawStringToHandle(
		position.x, position.y,
		text.c_str(),
		color.ToCOLOR(),
		fonts[id]);
}

void Renderer::DrawNumber(Assets::Texture id, const Vector2 & position, int number, int width, int height, int digit, char fill)
{
	//参考URL:http://www.geocities.jp/hp_yamakatsu/gakuseiC_01.html

	std::stringstream ss;

	// digitの桁数に fill + numberを収める
	//例　digit = 10桁, fill = '$', number = 1997
	//　　$$$$$$1997
	ss << std::setw(digit) << std::setfill(fill) << number;

	std::string numStr = ss.str();

	//表示する数字分forで回す
	for (unsigned int i = 0; i < numStr.size(); ++i) {
		//スペースならもう一回
		if (numStr[i] == ' ')
			continue;

		int n = numStr[i] - '0';
		Vector2 pos(position.x + i * width, position.y);
		Rect rect(n * width, 0.0f, width, height);
		DrawRectangle(id, pos, rect);
	}
}

void Renderer::DrawBillboard(Assets::Texture id, const Vector3 & position, const Vector2 & center, float scale, float angle, const Color& color)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(color.a * 255.0f));

	SetDrawBright(color.r * 255.0f, color.g * 255.0f, color.b * 255.0f);

	DrawBillboard3D(
		Convert::ToVECTOR(position),
		center.x,
		center.y,
		scale,
		angle * Math::toRadian,
		textures[id],
		TRUE
	);

	SetDrawBright(255,255,255);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void Renderer::DrawNumberBillboard(Assets::Texture id, const Vector3 & position, int number, int width, int height, float alpha)
{
	//後輩記述

	std::string numStr = std::to_string(number);

	for (unsigned int i = 0; i < numStr.size(); ++i) {
		if (numStr[i] == ' ')
			continue;

		int n = numStr[i] - '0';
		Vector2 topLeft(0 + i * 3, 3);
		Vector2 topRight(3 + i * 3, 3);
		Vector2 bottomRight(3 + i * 3, 0);
		Vector2 bottomLeft(0 + i * 3, 0);
		Rect rect(n * width, 0.0f, width, height);
		int numberRect = DerivationGraph( //新しいグラフィックハンドルを作る
			rect.left, rect.top,
			rect.right, rect.bottom,
			textures[id]);


		SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(alpha * 255.0f));
		DrawModiBillboard3D(
			VGet(position.x, position.y, position.z),
			topLeft.x, topLeft.y,
			topRight.x, topRight.y,
			bottomRight.x, bottomRight.y,
			bottomLeft.x, bottomLeft.y,
			numberRect,
			TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

		DeleteGraph(numberRect);
	}
}

int Renderer::DrawEffect3D(Assets::Effect id)
{
	return EffectManager::GetInstance().Play(effects[id], 0, 0, 0);
}

void Renderer::SetEffect3DPosition(int playEffectHandle, const Vector3 & position)
{
	EffectManager::GetInstance().SetPosition(playEffectHandle, position.x, position.y, position.z);
}

void Renderer::SetEffect3DScele(int playEffectHandle, const Vector3 & scale)
{
	EffectManager::GetInstance().SetScale(playEffectHandle, scale.x, scale.y, scale.z);
}

void Renderer::SetEffect3DRotate(int playEffectHandle, float x, float y, float z)
{
	EffectManager::GetInstance().SetRotation(playEffectHandle, x , y, z);
}

void Renderer::SetEffect3DMatrix(int playEffectHandle, const Matrix4 & matrix)
{
	EffectManager::GetInstance().SetMatrix(playEffectHandle, matrix);
}


void Renderer::SetMatrix3DModel(int modelHandle, const Matrix4 & matrix)
{
	MV1SetMatrix(modelHandle, Convert::ToMATRIX(matrix));
}

void Renderer::Draw3DModel(int modelHandle)
{
	MV1DrawModel(modelHandle);
}

void Renderer::Draw3DModel(int modelHandle, const Matrix4 & matrix)
{
	MV1SetMatrix(modelHandle, Convert::ToMATRIX(matrix));
	MV1DrawModel(modelHandle);
}

void Renderer::BindAnimation(ModelInfo& info, int animeIndex, float animeTime)
{
	//今再生中のアニメーションと指定したアニメーションが一緒なら
	//更新して終了
	if (info.nowPlayAnimeIndex == animeIndex) {
		MV1SetAttachAnimTime(info.modelID, info.animeID, animeTime);
		return;
	}

	//再生するアニメーションを代入
	info.nowPlayAnimeIndex = animeIndex;
	//関連を解除する
	MV1DetachAnim(info.modelID, info.animeID);
	//指定したアニメーションのID・ハンドルを設定
	info.animeID = MV1AttachAnim(info.modelID, animeIndex, info.sourceAnimeModelID, FALSE);
	//アニメーション更新
	MV1SetAttachAnimTime(info.modelID, info.animeID, animeTime);
}

void Renderer::BindAnimationBlend(ModelInfo& info, int animeIndex, float animeTime)
{
	//今再生中のアニメーションと指定したアニメーションが違うなら
	if (info.nowPlayAnimeIndex != animeIndex) {
		//以前生成していたアニメーションとの関連を解除
		MV1DetachAnim(info.modelID, info.previousAnimeID);
		//以前再生していたIDを今再生しているIDに設定
		info.previousAnimeID = info.animeID;
		//指定したアニメーションのID・ハンドルを設定
		info.animeID = MV1AttachAnim(info.modelID, animeIndex, info.sourceAnimeModelID, FALSE);
		//以前再生していたアニメーション番号を今再生している番号に設定
		info.previousPlayAnimeIndex = info.nowPlayAnimeIndex;
		//今再生している番号を指定した番号に設定
		info.nowPlayAnimeIndex = animeIndex;
		//補間時間を初期化
		info.lerpTime = 0.0f;
	}

	//補間時間を更新
	info.lerpTime = Math::Min<float>(info.lerpTime + 1.0f, LerpTime);
	//　今の補間時間　/　最大補間時間　＝　(0.0 ～　1.0)
	float rate = info.lerpTime / LerpTime;

	//アニメーションのブレンド値の更新
	MV1SetAttachAnimBlendRate(info.modelID, info.previousAnimeID, 1.0f - rate);
	//アニメーションのブレンド値の更新
	MV1SetAttachAnimBlendRate(info.modelID, info.animeID, rate);

	//アニメーション時間の更新
	MV1SetAttachAnimTime(info.modelID, info.animeID, animeTime);

}

void Renderer::BindAnimationBlendToBone(ModelInfo& info, int animeIndex, float animeTime00, float animeTime01, int boneIndex)
{
	//今再生中のアニメーションと指定したアニメーションが違うなら
	if (info.nowPlayAnimeIndex != animeIndex) {
		//以前生成していたアニメーションとの関連を解除
		MV1DetachAnim(info.modelID, info.previousAnimeID);
		//以前再生していたIDを今再生しているIDに設定
		info.previousAnimeID = info.animeID;
		//指定したアニメーションのID・ハンドルを設定
		info.animeID = MV1AttachAnim(info.modelID, animeIndex, info.sourceAnimeModelID, FALSE);
		//以前再生していたアニメーション番号を今再生している番号に設定
		info.previousPlayAnimeIndex = info.nowPlayAnimeIndex;
		//今再生している番号を指定した番号に設定
		info.nowPlayAnimeIndex = animeIndex;
		//補間時間を初期化
		info.lerpTime = 0.0f;
	}


	//補間時間を更新
	info.lerpTime = Math::Min<float>(info.lerpTime + 1.0f, LerpTime);
	//　今の補間時間　/　最大補間時間　＝　(0.0 ～　1.0)
	float rate = info.lerpTime / LerpTime;

	//指定したボーンから上アニメーションのブレンド値の更新
	MV1SetAttachAnimBlendRateToFrame(info.modelID, info.previousAnimeID, boneIndex, 1.0f - rate, TRUE);
	//指定したボーンから下アニメーションのブレンド値の更新
	MV1SetAttachAnimBlendRateToFrame(info.modelID, info.animeID, boneIndex, rate, TRUE);

	//アニメーション時間の更新
	MV1SetAttachAnimTime(info.modelID, info.animeID, animeTime00);
	//アニメーション時間の更新
	MV1SetAttachAnimTime(info.modelID, info.previousAnimeID, animeTime01);


}



float Renderer::GetAnimationTime(int animationHandle, int animeIndex)
{
	return MV1GetAnimTotalTime(animationHandle, animeIndex);
}

int Renderer::GetAnimationHandle(Assets::Animation id)
{
	return animations[id];
}

int Renderer::GetModelHandle(Assets::Model id)
{
	return models[id];
}

int Renderer::GetDeplicateModelHandle(Assets::Model id)
{
	return MV1DuplicateModel(models[id]);
}

int Renderer::GetEffectHandle(Assets::Effect id)
{
	return effects[id];
}

void Renderer::DeleteModel(int modelHandle)
{
	MV1DeleteModel(modelHandle);
}


Vector3 Renderer::GetBonePosition(int modelHandle, int boneIndex)
{
	return Convert::ToVector3(MV1GetFramePosition(modelHandle, boneIndex));
}

Matrix4 Renderer::GetBoneLocalMatrix(int modelHandle, int boneIndex)
{
	return Convert::ToMatrix4(MV1GetFrameLocalMatrix(modelHandle, boneIndex));
}

Matrix4 Renderer::GetBoneLocalWorldMatrix(int modelHandle, int boneIndex)
{
	return Convert::ToMatrix4(MV1GetFrameLocalWorldMatrix(modelHandle, boneIndex));
}

int Renderer::GetModelTextureIndex(int modelHandle, int index)
{
	return MV1GetMaterialDifMapTexture(modelHandle, index);
}

void Renderer::ChangeModelTexture(int modelHandle, Assets::Texture id, int textureIndex)
{
	MV1SetTextureGraphHandle(modelHandle, textureIndex, textures[id], FALSE);
}

void Renderer::Clear()
{
	for (auto& id : models) {
		MV1DeleteModel(id.second);
	}
	for (auto& id : animations) {
		MV1DeleteModel(id.second);
	}

	for (auto& id : textures) {
		DeleteGraph(id.second);
	}

	for (auto& id : fonts) {
		DeleteFontToHandle(id.second);
	}

	for (auto& id : effects) {
		EffectManager::GetInstance().Delete(id.second);
	}

	models.clear();
	animations.clear();
	textures.clear();
	fonts.clear();
	effects.clear();
}

bool Renderer::IsPlayEffect3D(int effectHandle)
{
	return EffectManager::GetInstance().IsPlay(effectHandle);
}

