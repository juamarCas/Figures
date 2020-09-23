#include "Triangle.h"

Triangle::Triangle(float size, float centerX, float centerY, float red, float green, float blue) : Figure(size, centerX, centerY, red, green, blue) {
	position = new float[6];
	index = new unsigned int[3];
	indexCount = 3; 
	vertexCount = 6; 
	SetPos();
	SetIndex(); 
	
}

void Triangle::SetPos() {
	position[0] = centerX;
	position[1] = centerY + GetSize(); 
	position[2] = centerX + GetSize(); 
	position[3] = centerY - GetSize(); 
	position[4] = centerX - GetSize(); 
	position[5]	= centerY - GetSize(); 
}

void Triangle::SetIndex() {
	for (int i = 0; i < 3; i++) {
		index[i] = i; 
	}
}