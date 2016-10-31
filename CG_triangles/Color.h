#pragma once
class Color
{
public:
	Color(float, float, float);
	~Color();
	float Red();
	float Green();
	float Blue();

private:
	float red;
	float green;
	float blue;
};

