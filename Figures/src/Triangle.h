#pragma once
#include "Figure.h"
class Triangle: public Figure {
private: 
	
public: 
	Triangle(float size, float centerX, float centerY, float red, float green, float blue);
	void SetPos() override;
	void SetIndex() override;
};