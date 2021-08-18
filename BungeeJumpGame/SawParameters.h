#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
struct SawParameters
{
	int sawRotationDegree;
	int sawRadius;
	Color sawFirstColor;
	Color sawSecondColor;
	Color sawThirdColor;
	


	static SawParameters Default()
	{
		return SawParameters
		{
			10,
			40,
			Color::Red,
			Color::Blue,
			Color::Green,
		};
	}
};