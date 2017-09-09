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
	//!���Z�b�g�@�������v�����邽��
	timer = maxTime;
}

void Timer::Update(float deltaTime) {
	//!timer = Max(-1.0f , 0.0f)�Ȃ�0.0f��Ԃ����߁Aif���������Ȃ��Ă��ށB
	//!�@		      timer - 1.0f/ 60.0f(�ݒ肵��FPS)
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
