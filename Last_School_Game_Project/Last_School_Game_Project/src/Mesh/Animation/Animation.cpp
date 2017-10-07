#include "Animation.h"
#include<DxLib.h>
Animation::Animation(int motion)
	: animeID(-1)
	, motion(motion)
	, motionTimer(0.0f)
{
}

Animation::~Animation()
{
}

void Animation::Update(float dt)
{
	//I—¹ŽžŠÔ‚ð’´‚¦‚½‚ç‚Ü‚½Ä¶‚µ‚È‚¨‚·
	if (motionTimer > GetEndTime()) {
		motionTimer = 0.0f;
	}
	motionTimer += dt;
}

void Animation::ChangeMotion(int motion)
{
	if (this->motion == motion)
		return;

	this->motion = motion;
	motionTimer = 0.0f;

}

float Animation::GetMotionTime() const
{
	return motionTimer;
}


int Animation::GetMotion() const
{
	return motion;
}


float Animation::GetEndTime() const
{
	return MV1GetAnimTotalTime(animeID, motion);
}

void Animation::SetAnimeID(int animeID)
{
	this->animeID = animeID;
}

int Animation::GetAnimeID() const
{
	return animeID;
}
