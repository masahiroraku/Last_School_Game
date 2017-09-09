#include "HitPoint.h"

#include"Math/Math.h"
#include"Renderer/Renderer.h"


HitPoint::HitPoint(int maxHitPoint)
	: maxHitPoint(maxHitPoint)
	, hitPoint(maxHitPoint)
{
}

HitPoint::~HitPoint()
{
}

void HitPoint::Initialize()
{
	hitPoint = maxHitPoint;
}

void HitPoint::AddValue(int value)
{
	hitPoint += value;
	hitPoint = Math::Clamp<int>(hitPoint, 0, maxHitPoint);
}

void HitPoint::SetMaxHP(int maxValue)
{
	this->maxHitPoint = maxValue;
}


int HitPoint::GetHP()const
{
	return hitPoint;
}

int HitPoint::GetMaxHP() const
{
	return maxHitPoint;
}

bool HitPoint::IsDead()const
{
	return hitPoint <= 0;
}
