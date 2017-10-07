#include "SwordCombo.h"

#include"Input/Input.h"

SwordCombo::SwordCombo(const ComboData& comboData, Actor& swordPtr, SkinningMesh& meshPtr)
	: isEnd(false)
	, comboData(comboData)
	, swordPtr(swordPtr)
	, meshPtr(meshPtr)
	, isNext(false)
{
}


SwordCombo::~SwordCombo()
{
}

void SwordCombo::Initialize()
{
	isEnd = false;
	isNext = false;
	swordPtr.SetBodyActive(false);
}

void SwordCombo::Update(float deltaTime)
{
	if (meshPtr.IsEndMotion()) {
		isEnd = true;
		return;
	}

	swordPtr.SetBodyActive(GetCollisionTime());
	if (Input::GetInstance().GetCommand(Command::SwordAttack)) {
		isNext = true;
	}
}

void SwordCombo::HandleMessage(EventMessage message, void * param)
{
}

bool SwordCombo::IsEnd() const
{
	return isEnd;
}

int SwordCombo::GetNextState() const
{
	return (isNext == true) ? comboData.nextIndex : -2;
}

int SwordCombo::GetNextAnime() const
{
	return (isNext == true) ? comboData.nextAnime : Player::Anime::Idle_;
}

bool SwordCombo::GetCollisionTime() const
{
	float motionTime = meshPtr.GetMotionTime();
	return motionTime >= comboData.beginCollideTime && comboData.endCollideTime >= motionTime;
}
