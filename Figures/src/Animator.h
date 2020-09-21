#pragma once
#include <iostream>
#include "Figure.h"
#include <string>
class Animator {

private:
	Figure * figure; 
	float velocity; 

	//center of the figure
	float * c; 

	//changes i x and y coordinates
	float dx; 
	float dy;
public: 
	Animator(Figure* figure, float velocity); 
	void Move(float dx, float dy, float *c); 
	void HVAnimation(bool isHorizontal); 
	void SetAnimation(std::string name); 

};