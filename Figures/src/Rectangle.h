#pragma once
#include "Figure.h"

class Rectangle : public Figure {
private:
	float width;
	float height; 
public: 
	
	Rectangle(float size, float centerX, float centerY, float red, float green, float blue, float width, float height); 

	void SetPos() override;
	void SetIndex() override; 

	float GetWidth() override; 
	float GetHeight() override; 
};