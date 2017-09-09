#include "SimpleMesh.h"
#include"Renderer/Renderer.h"

SimpleMesh::SimpleMesh(Assets::Model id, bool isUseZBuffer)
	: modelHandle(0)
{
	auto renderer = Renderer::GetInstance();
	modelHandle = renderer->GetModelHandle(id);
	MV1SetUseZBuffer(modelHandle, (isUseZBuffer == true) ? TRUE : FALSE);
}

SimpleMesh::~SimpleMesh()
{
}

void SimpleMesh::Update(float dt)
{
}

void SimpleMesh::Draw(Renderer & renderer, const Matrix4 & world) const
{
	renderer.Draw3DModel(modelHandle, world);
}

int SimpleMesh::GetModelHandle()
{
	return modelHandle;
}

void SimpleMesh::ChangeTexture(Assets::Texture textureID, int materialNumber)
{
	Renderer* renderer = Renderer::GetInstance();
	int textureIndex = renderer->GetModelTextureIndex(modelHandle, materialNumber);
	renderer->ChangeModelTexture(modelHandle, textureID, textureIndex);
}
