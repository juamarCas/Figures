#include "Polygon.h"
#define PI 3.14159265

Polygon::Polygon(float size, float centerX, float centerY, float red, float green, float blue, int numberOfSides) : Figure(size, centerX, centerY, red, green, blue) {
	this->numberOfSides = numberOfSides; 
	angles = 360 / numberOfSides; 
	auxAngles = 0; 
	SetPos(); 

}

void Polygon::SetPos() {
	position = new float[(numberOfSides + 1) * 2]; 
	for (int i = 0; i < (numberOfSides + 1) * 2; i += 2) {
		if (i == (numberOfSides + 1) * 2) {
			position[i] = centerX; //this is the center vertex of the polygon 
			position[i] = centerY; 
			break; 
		}
		position[i] = centerX + size * cos(auxAngles * PI/180); //polar ecuation for a point in the circunsference
		position[i + 1] = centerY + size * sin(auxAngles * PI / 180);
		auxAngles += angles;
	}
}

void Polygon::SetIndex() {
	index = new unsigned int[numberOfSides * 3]; 
	for (int i = 0; i < numberOfSides * 3; i++) {

	}
}