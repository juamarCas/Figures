#include "Rectangle.h"

Rectangle::Rectangle(float size, float centerX, float centerY, float red, float green, float blue, float width, float height ): Figure(size, centerX, centerY, red, green, blue){

	this->width = width/2/10; 
	this->height = height/2/10;
	
	//Defining the figure, in this case is a Rectangle
	vertexCount = 8;
	indexCount = 6; 
	position = new float[vertexCount];
	index = new unsigned int[indexCount];
	SetPos(); 
	SetIndex(); 
}

void Rectangle::SetPos()  {
	
	//with the center, it obtains the vertex
	position[0] = centerX - width;
	position[1] = centerY - height; //0
	position[2] = centerX + width;
	position[3] = centerY - height; //1
	position[4] = centerX + width;
	position[5] = centerY + height; //2
	position[6] = centerX - width;
	position[7] = centerY + height;//3
	
	
}

void Rectangle::SetIndex() {
	
	index[0] = 0;
	index[1] = 1;
	index[2] = 2;
	index[3] = 0;
	index[4] = 3;
	index[5] = 2;
}

float Rectangle::GetHeight() {
	return height; 
}

float Rectangle::GetWidth() {
	return width; 
}


