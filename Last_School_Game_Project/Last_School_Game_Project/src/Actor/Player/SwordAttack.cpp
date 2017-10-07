#include "SwordAttack.h"
#include"Actor/Player/Player.h"
#include"Input/Input.h"
#include"SwordCombo.h"

SwordAttack::SwordAttack(Actor& swordPtr, SkinningMesh& meshPtr)
	: isEnd(false)
	, stateManager()
	, index(0)
	, maxComboNum(0)
{
	stateManager.SetChangeFunc([&](int state, int motion) {
		if (state == -2) {
			isEnd = true;
			return;
		}
		meshPtr.ChangeMotion(motion);
	});

	//1ƒRƒ“ƒ{–Ú
	SwordCombo::ComboData comboData = {1, Player::Anime::Slash_01_, 18,22 };
	stateManager.Add(0, std::make_shared<SwordCombo>(comboData, swordPtr, meshPtr));
	comboData = { 0, Player::Anime::Slash_00_, 23,28 };
	stateManager.Add(1, std::make_shared<SwordCombo>(comboData, swordPtr, meshPtr));

}


SwordAttack::~SwordAttack()
{
}

void SwordAttack::Initialize()
{
	isEnd = false;
	stateManager.Reset();
	stateManager.Change(0, Player::Anime::Slash_00_);
}

void SwordAttack::Update(float deltaTime)
{
	stateManager.Update(deltaTime);
}

void SwordAttack::HandleMessage(EventMessage message, void * param)
{
}

bool SwordAttack::IsEnd() const
{
	return isEnd;
}

int SwordAttack::GetNextState() const
{
	return static_cast<int>(Player::State::Idle);
}

int SwordAttack::GetNextAnime() const
{
	return Player::Anime::Idle_;
}
