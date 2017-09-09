#include "Timer.h"
#include"Renderer/Renderer.h"
#include"Application/FPS/FPS.h"

Timer::Timer(float setTime)
	: maxTime(setTime)
	, timer(setTime) {
}

Timer::~Timer() {
}

void Timer::Initialize() {
	//!リセット　もう一回計測するため
	timer = maxTime;
}

void Timer::Update(float deltaTime) {
	//!timer = Max(-1.0f , 0.0f)なら0.0fを返すため、if文を書かなくてすむ。
	//!　		      timer - 1.0f/ 60.0f(設定したFPS)
	timer = Math::Max(timer - (deltaTime / FPS::fps), 0.0f);
}

bool Timer::IsTimeUp() const {
	return timer <= 0.0f;
}

float Timer::GetSecond() const {
	return timer;
}

float Timer::GetMaxTime() const {
	return maxTime;
}
