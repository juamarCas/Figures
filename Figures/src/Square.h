#pragma once
#include "Figure.h"

class Square : public Figure {
private:
	
public: 
	
	Square(float size, float centerX, float centerY, float red, float green, float blue); 
	void SetPos() override;
	void SetIndex() override; 
};