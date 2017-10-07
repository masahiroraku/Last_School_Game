#pragma once

/*Actor‚Å‚æ‚­g‚¤‚Ü‚½‚Í”í‚éŠÖ”‚ğ‚Ü‚Æ‚ß‚½ƒNƒ‰ƒX*/

class Actor;
class Vector3;

class ActorUtility {
public:
	static void CollidePush(Actor& actor, const Vector3& direction, float pushPower = 1.0f);
};