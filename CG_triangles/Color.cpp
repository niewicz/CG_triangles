#include "Color.h"

Color::Color(float r = 1.0f, float g = 1.0f, float b = 1.0f)
{
	this->red = r;
	this->green = g;
	this->blue = b;
}

Color::~Color()
{
}

float Color::Red()
{
	return this->red;
}

float Color::Green()
{
	return this->green;
}

float Color::Blue()
{
	return this->blue;
}