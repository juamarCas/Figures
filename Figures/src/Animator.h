#pragma once
#include <iostream>
#include "Figure.h"
#include <string>
#include <math.h>
class Animator {

private:
	Figure * figure; 
	float velocity; 
	float size; //in case like the cirular animation or box, how it will cover the screen

	//center of the figure
	float * c; 

	//changes i x and y coordinates
	float dx; 
	float dy;

	float auxAngle; 
public: 
	Animator(Figure* figure, float velocity, float size); 
	void Move(float *c); 
	void HVAnimation(bool isHorizontal); 
	void SetAnimation(std::string name); 
	void CircularAnimation(float radius); 

};