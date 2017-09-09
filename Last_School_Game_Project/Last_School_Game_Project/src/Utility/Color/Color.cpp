#include"Color.h"

const Color Color::Red = Color(1, 0, 0, 1);
const Color Color::Green = Color(0, 1, 0, 1);
const Color Color::Blue = Color(0, 0, 1, 1);
const Color Color::Yellow = Color(1, 1, 0, 1);
const Color Color::Black = Color(0, 0, 0, 1);
const Color Color::White = Color(1, 1, 1, 1);

Color Color::Lerp(const Color & color, float lerpTime)const
{
	if (lerpTime < 0.0f)
		return *this;
	if (lerpTime > 1.0f)
		return color;

	float r_ = Math::Lerp<float>(r, color.r, lerpTime);
	float g_ = Math::Lerp<float>(g, color.g, lerpTime);
	float b_ = Math::Lerp<float>(b, color.b, lerpTime);
	float a_ = Math::Lerp<float>(a, color.a, lerpTime);
	return Color(r_, g_, b_, a_);
}
