#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
struct BaseParameters
{
	int baseRotationDegree;
	int baseWidth;
	int baseHeigth;
	Color baseFirstColor;
	Color baseSecondColor;
	Color baseThirdColor;
	Color baseForthColor;

	static BaseParameters Default()
	{
		return BaseParameters
		{ 
			0,
			50,
			50,
			Color::Red,
			Color::Black,
			Color::Red,
			Color::Black
		};
	}
};