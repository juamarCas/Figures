#include "Square.h"

Square::Square(float size, float centerX, float centerY, float red, float green, float blue ): Figure(size, centerX, centerY, red, green, blue){

	//Defining the figure, in this case is a square
	vertexCount = 8;
	SetPos(); 
	SetIndex(); 
}

void Square::SetPos()  {
	
	//with the center, it obtains the vertex
	position = new float[8];
	
	position[0] = centerX - size / 2.0f / 10.0f;
	position[1] = centerY - size / 2.0f / 10.0f; //0
	position[2] = centerX + size / 2.0f / 10.0f;
	position[3] = centerY -size / 2.0f / 10.0f; //1
	position[4] = centerX + size / 2.0f / 10.0f;
	position[5] = centerY + size / 2.0f / 10.0f; //2
	position[6] = centerX -size / 2.0f / 10.0f;
	position[7] = centerY + size / 2.0f / 10.0f;//3
	
	
}

void Square::SetIndex() {
	index = new unsigned int[6];
	index[0] = 0;
	index[1] = 1;
	index[2] = 2;
	index[3] = 0;
	index[4] = 3;
	index[5] = 2;
}


