#include "BoarDragon_Damage.h"
#include "Actor/Weapon/WeaponHitInfo.h"

BoarDragon_Damage::BoarDragon_Damage(SkinningMesh& meshPtr, HitPoint & hp)
	: meshPtr(meshPtr)
	, isEnd(false)
	, isDamage(false)
	, hp(hp)
	, state(BoarDragon::State::Idle)
	, anime(BoarDragon::Anime::Idle_)
{
}

BoarDragon_Damage::~BoarDragon_Damage()
{
}

void BoarDragon_Damage::Initialize()
{
	isEnd = false;
	isDamage = false;
	state = BoarDragon::State::Idle;
	anime = BoarDragon::Anime::Idle_;
}

void BoarDragon_Damage::Update(float deltaTime)
{
	isEnd = meshPtr.IsEndMotion();
}

void BoarDragon_Damage::HandleMessage(EventMessage message, void * param)
{
	if (message != EventMessage::Damage || isDamage == true)
		return;
	WeaponHitInfo weaponInfo = *(WeaponHitInfo*)param;

	if (weaponInfo.tag == ActorTag::PlayerWeapon) {
		hp.AddValue(-weaponInfo.damage);
		bool isDead = hp.IsDead();
		state = (isDead == true) ? BoarDragon::State::Dead : BoarDragon::State::Idle;
		anime = (isDead == true) ? BoarDragon::Anime::Dead_ : BoarDragon::Anime::Idle_;
		isDamage = true;
	}
}

bool BoarDragon_Damage::IsEnd() const
{
	return isEnd;
}

int BoarDragon_Damage::GetNextState() const
{
	return static_cast<int>(state);
}

int BoarDragon_Damage::GetNextAnime() const
{
	return anime;
}
