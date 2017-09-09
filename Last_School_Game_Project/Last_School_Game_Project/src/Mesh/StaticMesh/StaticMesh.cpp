#include "StaticMesh.h"
#include"Renderer/Renderer.h"

StaticMesh::StaticMesh(Assets::Model id, const Matrix4& world, bool isUseZBuffer)
	: modelHandle(0)
{
	//動かないメッシュなので１回だけ座標更新する。
	auto renderer = Renderer::GetInstance();

	modelHandle = renderer->GetModelHandle(id);

	MV1SetUseZBuffer(modelHandle, (isUseZBuffer == true) ? TRUE : FALSE);

	renderer->SetMatrix3DModel(modelHandle, world);
}

StaticMesh::~StaticMesh()
{
}


void StaticMesh::Update(float dt)
{
}

void StaticMesh::Draw(Renderer & renderer) const
{
	//表示だけする。座標の更新はしない。
	renderer.Draw3DModel(modelHandle);
}

int StaticMesh::GetModelHandle()
{
	return modelHandle;
}
