#include "Sound.h"

#include<DxLib.h>
#include <cassert>

#include"Utility/FilePass/FilePass.h"
#include"Math/Math.h"

Sound::Sound() {
	mSoundHandle.clear();
}

Sound::~Sound() {
	SoundClear();
	mSoundHandle.clear();
}

Sound & Sound::GetInstance() {
	static Sound instance;
	return instance;
}

void Sound::LoadSound(Assets::Sound id, const std::string & fileName) {
	int handle = LoadSoundMem((FilePass::SoundFile + fileName).c_str());
	if (handle == -1) {
		assert(!"Failure to read the file.");
		return;
	}
	mSoundHandle.emplace(id, handle);
}



void Sound::PlaySE(Assets::Sound id, float volume) {
	ChangeVolumeSoundMem(volume * 255, mSoundHandle[id]);
	PlaySoundMem(mSoundHandle[id], DX_PLAYTYPE_BACKBIT, TRUE);
}

void Sound::PlayBGM(Assets::Sound id, float volume) {
	ChangeVolumeSoundMem(volume * 255, mSoundHandle[id]);
	PlaySoundMem(mSoundHandle[id], DX_PLAYTYPE_LOOP, TRUE);
}

void Sound::PlaySounds(Assets::Sound id, int mPlayType, float volume) {
	ChangeVolumeSoundMem(volume * 255, mSoundHandle[id]);
	PlaySoundMem(mSoundHandle[id], mPlayType, TRUE);
}

void Sound::StopBGM(Assets::Sound id) {
	StopSoundMem(mSoundHandle[id]);
}

int Sound::GetSoundHandle(Assets::Sound id) {
	return mSoundHandle[id];
}

void Sound::SoundClear() {
	for (auto& id : mSoundHandle) {
		DeleteSoundMem(id.second);
	}
	mSoundHandle.clear();
}

