#pragma once

/**
 * @file Color.h
 * @brief FξρΜθ`t@C
 * @author ’]
 * @date Unknown
 */

#include"Math/Math.h"
#include<DxLib.h>

 /*! @class Color
 *   @brief  Fξρ
 */
class Color {
public:
	 /// <summary>
	 /// RXgN^<see cref="Color"/>
	 /// </summary>
	 /// <param name="r">Τ (0.0f`1.0f)</param>
	 /// <param name="g">Ξ (0.0f`1.0f)</param>
	 /// <param name="b">Β (0.0f`1.0f)</param>
	 /// <param name="a">At@l (0.0f`1.0f)</param>
	Color(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f)
		: r(Math::Clamp(r, 0.0f, 1.0f))
		, g(Math::Clamp(g, 0.0f, 1.0f))
		, b(Math::Clamp(b, 0.0f, 1.0f))
		, a(Math::Clamp(a, 0.0f, 1.0f)) {
	}
	 /// <summary>
	 /// FΜβΤ
	 /// </summary>
	 /// <param name="color">βΤ·ιF</param>
	 /// <param name="t">βΤΜδ(0.0f`1.0f)</param>
	 /// <returns>βΤ΅½F</returns>
	Color Lerp(const Color& color, float t) const;
	 /// <summary>
	 /// DXLIBΜFξρΙΟ·
	 /// </summary>
	 /// <returns>DXLIBΜFξρ</returns>
	unsigned int ToCOLOR() const {
		return GetColor((int)(r * 255.0f), (int)(g * 255.0f), (int)(b * 255.0f));
	}

	//!Τ
	static const Color Red;
	//!Ξ
	static const Color Green;
	//!Β
	static const Color Blue;
	//!©
	static const Color Yellow;
	//!
	static const Color Black;
	//!
	static const Color White;

public:
	//!Τ
	float r;
	//!Ξ
	float g;
	//!Β
	float b;
	//!At@l
	float a;
};