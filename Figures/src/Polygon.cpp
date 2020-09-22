#include "Polygon.h"
#define PI 3.14159265

Polygon::Polygon(float size, float centerX, float centerY, float red, float green, float blue, int numberOfSides) : Figure(size, centerX, centerY, red, green, blue) {
	this->numberOfSides = numberOfSides;
	vertexCount = (numberOfSides + 1) * 2;
	indexCount = numberOfSides * 3; 
	angles = 360 / numberOfSides; 
	auxAngles = 0; 
	position = new float[vertexCount];
	index = new unsigned int[indexCount];
	SetPos(); 
	SetIndex(); 
}

void Polygon::SetPos() {
	auxAngles = 0; 
	
	//stablish the center of the polygon as the last vertex
    position[(numberOfSides + 1) * 2 - 2] = centerX;
	position[(numberOfSides + 1) * 2 - 1] = centerY;
		
	for (int i = 0; i < (numberOfSides + 1) * 2 - 2; i += 2) {	
			
		//polar ecuation for a point in the circunsference
		position[i] = centerX + GetSize() * cos(auxAngles * PI/180); 
		position[i + 1] = centerY + GetSize() * sin(auxAngles * PI / 180);
		auxAngles += angles;
		
	}
}

void Polygon::SetIndex() {
	
	int counter = 0; 
	int aux = 0; 
	int indexAux = 0; 
	bool hasPassedCounter = false; 
	for (int i = 0; i < numberOfSides * 3; i ++) {
		counter++; 
		if (hasPassedCounter) {
			hasPassedCounter = false;
			aux = indexAux; 
			aux--; 
		}
		if (counter >= 3) {
			indexAux = aux; 
			aux = 6; 
			counter = 0; 
			hasPassedCounter = true; 
		}

		
		if (i == numberOfSides * 3 - 2) {
			aux = 0; 
		 }
		index[i] = aux; 
		aux++; 
	}
	
	for (int i = 0; i < numberOfSides * 3; i++) {
		std::cout << index[i] << std::endl; 
	}

	for (int i = 0; i < (numberOfSides + 1) * 2; i+= 2) {
		std::cout << "Pos X: " << position[i] << " pos Y: " << position[i + 1] << std::endl;
	}
	
}