#pragma once

/*Actor�ł悭�g���܂��͔��֐����܂Ƃ߂��N���X*/

class Actor;
class Vector3;

class ActorUtility {
public:
	static void CollidePush(Actor& actor, const Vector3& direction, float pushPower = 1.0f);
};