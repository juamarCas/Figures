#pragma once
#include "Figure.h"

class Square : public Figure {
private:
	
public: 
	
	Square(float size, float centerX, float centerY); 
	void SetPos() override;
	void SetIndex() override; 
};