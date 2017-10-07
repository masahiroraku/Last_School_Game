#include "ActorUtility.h"

#include"Actor/Base/Actor.h"

void ActorUtility::CollidePush(Actor & actor, const Vector3 & direction, float pushPower)
{
	actor.SetPosition(actor.GetPosition() + direction * pushPower);
}
