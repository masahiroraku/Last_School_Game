#include "Damage.h"
#include "Actor/Weapon/WeaponHitInfo.h"

Damage::Damage(SkinningMesh & meshPtr, HitPoint & hp)
	: meshPtr(meshPtr)
	, hp(hp)
	, state(Player::State::Idle)
	, anime(Player::Anime::Idle_)
	, isEnd(false)
	, isDamage(false)
{
}

Damage::~Damage()
{
}

void Damage::Initialize()
{
	isEnd = false;
	state = Player::State::Idle;
	anime = Player::Anime::Idle_;
	isDamage = false;
}

void Damage::Update(float deltaTime)
{
	isEnd = meshPtr.IsEndMotion();
}

void Damage::HandleMessage(EventMessage message, void * param)
{
	if (message != EventMessage::Damage || isDamage == true)
		return;
	WeaponHitInfo weaponInfo = *(WeaponHitInfo*)param;

	if (weaponInfo.tag == ActorTag::EnemyWeapon) {
		hp.AddValue(-weaponInfo.damage);
		bool isDead = hp.IsDead();
		state = (isDead == true) ? Player::State::Dead : Player::State::Idle;
		anime = (isDead == true) ? Player::Anime::Dead_ : Player::Anime::Idle_;
		isDamage = true;
	}
}

bool Damage::IsEnd() const
{
	return isEnd;
}

int Damage::GetNextState() const
{
	return static_cast<int>(state);
}

int Damage::GetNextAnime() const
{
	return anime;
}
