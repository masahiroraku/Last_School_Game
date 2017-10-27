#include "BombCollision.h"
#include "Collision/BoundingSphere/BoundingSphere.h"
#include "Collision/HitInfo.h"
#include "Actor/Weapon/WeaponHitInfo.h"
#include "Math/Math.h"

BombCollision::BombCollision(IWorld& world,const Vector3 & start, const Vector3 & end)
	: Actor(world,"BombCollision",start,std::make_shared<BoundingSphere>(Vector3::Zero, 1.0f))
	, damage(20)
	, t(0.0f)
	, end(end)
	, bezier()
{
	tag = ActorTag::EnemyWeapon;
	InitializeBezier();
}

BombCollision::~BombCollision()
{
}

void BombCollision::OnInitialize()
{
}

void BombCollision::OnUpdate(float deltaTime)
{
	position = bezier.GetPointVec3(t);
	t = Math::Min(1.0f, t + 0.02f * deltaTime);
	if (t >= 1.0f){
		status = Status::Dead;
	}
}

void BombCollision::OnDraw(Renderer & renderer)
{
#if _DEBUG
	body->Transform(GetMatrix())->Draw();
#endif
	bezier.Draw();
}

void BombCollision::OnCollide(const HitInfo & hitInfo)
{
	WeaponHitInfo weaponInfo(tag, damage);
	hitInfo.collideActor->HandleMessage(EventMessage::Damage, &weaponInfo);
}

void BombCollision::OnMessage(EventMessage message, void * param)
{
}

void BombCollision::InitializeBezier()
{
	Vector3 center = (end - position) / 2.0f;
	center.y = 5.0f;
	
	bezier.Set(position, center, end);
}
