#pragma once
#include <iostream>
#include <math.h>

#include "Figure.h"

class Polygon: public Figure {
private:
	int numberOfSides; 
	float angles;
	float auxAngles; 

public:
	Polygon(float size, float centerX, float centerY, float red, float green, float blue, int numberOfSides);
	void SetPos() override;
	void SetIndex() override;
	
	int GetNumberOfSides(); 
};