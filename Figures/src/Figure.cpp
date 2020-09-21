#include "Figure.h"


Figure::Figure(float size, float centerY, float centerX) {
	this->size = size;
	this->velocity = velocity;
	this->animationOP = animationOP; 	
	this->centerX = centerX;
	this->centerY = centerY; 
}
Figure::~Figure() {

}

void Figure::SetPos() {
	
}


float * Figure::GetPositions() {
	return position;
}

unsigned int * Figure::GetIndex() {
	return index;
}

float Figure::GetSize() {
	return size/2/10;
}

int Figure::GetVertexCount() {
	return vertexCount; 
}

float * Figure::GetCenter() {
	float * c = new float[2]; 
	c[0] = centerX; 
	c[1] = centerY; 

	return c; 
}

void Figure::SetCenter(float *c) {
	centerX = c[0]; 
	centerY = c[1]; 
}

void Figure::SetIndex() {

}
