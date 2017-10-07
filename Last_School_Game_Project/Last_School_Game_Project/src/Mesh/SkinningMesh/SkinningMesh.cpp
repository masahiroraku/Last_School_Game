#include "SkinningMesh.h"
#include"Renderer/Renderer.h"
#include"Math/Convert/Convert.h"

SkinningMesh::SkinningMesh(Assets::Model modelID, Assets::Animation animationID, bool isDeplicate)
	: animation(0)
	, modelInfo()
	, isDeplicate(isDeplicate)
{
	//TODO:‚±‚±C³
	auto renderer = Renderer::GetInstance();
	if (isDeplicate) {
		modelInfo.modelID = renderer->GetDeplicateModelHandle(modelID);
		modelInfo.sourceAnimeModelID = renderer->GetAnimationHandle(animationID);
	}
	else {
		modelInfo.modelID = renderer->GetModelHandle(modelID);
		modelInfo.sourceAnimeModelID = renderer->GetAnimationHandle(animationID);
	}
	modelInfo.nowPlayAnimeIndex = 0;
	modelInfo.animeID = MV1AttachAnim(modelInfo.modelID, 0, modelInfo.sourceAnimeModelID, FALSE);
	animation.SetAnimeID(modelInfo.sourceAnimeModelID);
}

SkinningMesh::~SkinningMesh()
{
}



void SkinningMesh::Update(float dt)
{
	animation.Update(dt);
	Renderer* renderer = Renderer::GetInstance();
	renderer->BindAnimationBlend(modelInfo, animation.GetMotion(), animation.GetMotionTime());
}


void SkinningMesh::Draw(Renderer & renderer, const Matrix4 & world) const
{
	renderer.Draw3DModel(modelInfo.modelID, world);
}

void SkinningMesh::ChangeMotion(int motion)
{
	animation.ChangeMotion(motion);
}

void SkinningMesh::ChangeTexture(Assets::Texture textureID, int materialNumber)
{
	Renderer* renderer = Renderer::GetInstance();
	int textureIndex = renderer->GetModelTextureIndex(modelInfo.modelID, materialNumber);
	renderer->ChangeModelTexture(modelInfo.modelID, textureID, textureIndex);
}

int SkinningMesh::GetModelHandle() const
{
	return modelInfo.modelID;
}

bool SkinningMesh::IsEndMotion() const
{
	return animation.GetEndTime() < animation.GetMotionTime();
}

float SkinningMesh::GetMotionTime() const
{
	return animation.GetMotionTime();
}

float SkinningMesh::GetMotionEndTime() const
{
	return animation.GetEndTime();
}

void SkinningMesh::Clear()
{
	if (isDeplicate == true) {
		auto renderer = Renderer::GetInstance();
		renderer->DeleteModel(modelInfo.modelID);
	}
}

Vector3 SkinningMesh::GetBonePosition(int boneIndex) const
{
	return Convert::ToVector3(MV1GetFramePosition(modelInfo.modelID, boneIndex));
}

Matrix4 SkinningMesh::GetBoneLocalMatrix(int boneIndex) const
{
	return Convert::ToMatrix4(MV1GetFrameLocalMatrix(modelInfo.modelID, boneIndex));
}

Matrix4 SkinningMesh::GetBoneWorldMatrix(int boneIndex) const
{
	return Convert::ToMatrix4(MV1GetFrameLocalWorldMatrix(modelInfo.modelID, boneIndex));
}
