#include "Effect3D.h"
#include"Renderer/Renderer.h"
#include"Effect/EffectManager.h"


namespace {
	//Ä¶’†
	static int PlayNow = 0;
}

Effect3D::Effect3D(IWorld & world, Assets::Effect id, const Matrix4 & matrix, bool isPlayOnce)
	: Actor(world, "Effect", matrix.GetPosition(), nullptr)
	, id(id)
	, isPlayOnce(isPlayOnce)
	, playHandle(-1)
	, isPlay(true)
{
	this->matrix = matrix;
	auto renderer = Renderer::GetInstance();
	playHandle = renderer->DrawEffect3D(id);	
}

Effect3D::~Effect3D()
{
}

bool Effect3D::IsPlay() const
{
	return isPlay;
}

void Effect3D::OnUpdate(float deltaTime)
{

	if (isPlayOnce == true && isPlay == false) {
		status = Status::Dead;
	}

	//¡Ä¶’†‚©æ“¾
	isPlay = EffectManager::GetInstance().IsPlay(playHandle);
	
}

void Effect3D::OnDraw(Renderer & renderer)
{
	renderer.SetEffect3DMatrix(playHandle, GetMatrix());
	if (isPlayOnce == false && isPlay == false) {
		playHandle = renderer.DrawEffect3D(id);
	}
}

void Effect3D::OnCollide(const HitInfo & hitInfo)
{
}

void Effect3D::OnMessage(EventMessage message, void * param)
{
}

