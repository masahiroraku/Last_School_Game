#pragma once

/*Actorでよく使うまたは被る関数をまとめたクラス*/

class Actor;
class Vector3;

class ActorUtility {
public:
	static void CollidePush(Actor& actor, const Vector3& direction, float pushPower = 1.0f);
};