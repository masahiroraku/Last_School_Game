#include "StaticMesh.h"
#include"Renderer/Renderer.h"

StaticMesh::StaticMesh(Assets::Model id, const Matrix4& world, bool isUseZBuffer)
	: modelHandle(0)
{
	//�����Ȃ����b�V���Ȃ̂łP�񂾂����W�X�V����B
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
	//�\����������B���W�̍X�V�͂��Ȃ��B
	renderer.Draw3DModel(modelHandle);
}

int StaticMesh::GetModelHandle()
{
	return modelHandle;
}
