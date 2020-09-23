#include "Animator.h"
#define PI 3.14159265
Animator::Animator(Figure * figure, float velocity, float size) {
	this->size = size; 
	if (1 - this->size < 0.5) {
		this->size = 0.5;
	}
	this->velocity = velocity/100; 
	this->figure = figure;
	auxAngle = 0; 

	destinyPoint = new float[2]; 

	destinyPoint[0] = 1 - figure->GetSize(); 
	destinyPoint[1] = -(1 - figure->GetSize()); 
	

	currentTarget = 1;
	
	
}

void Animator::Move(float *c) {
	//c is the center of the figure		
	figure->SetCenter(c);
	figure->SetPos(); 
}

void Animator::HVAnimation(bool horizontal) {
	c = figure->GetCenter();
	
	if (horizontal) {
		if (c[0] > 1 - figure->GetWidth() - size) {
			dx = -velocity;
			dy = 0;
		}
		else if (c[0] < figure->GetWidth() - 1 + size || dx == 0) {
			dx = velocity;
			dy = 0;
		}
	}
	else {
		if (c[1] > 1 - figure->GetHeight() - size) {
			dx = 0;
			dy = -velocity;
		}
		else if (c[1] < figure->GetHeight() - 1 + size|| dy == 0) {
			dx = 0;
			dy = velocity;
		}

	
	}

	c[0] += dx;
	c[1] += dy;

	Move(c); 
	
}

void Animator::CircularAnimation(float radius) {
	c = figure->GetCenter();
	dx = ((1 - radius)) * cos(auxAngle * PI / 180); 
	dy = ((1 - radius)) * sin(auxAngle * PI / 180);
	
	auxAngle -= velocity * 100; 

	if (auxAngle < -360) {
		auxAngle = 0; 
	}
	c[0] = dx; 
	c[1] = dy; 
	Move(c); 
}

void Animator::BoxAnimation() {
	c = figure->GetCenter();

	if (c[1] >= destinyPoint[0] && c[0] < 0) {
		currentTarget = 2;
	}
	else if (c[1] <= destinyPoint[1] && c[0] > 0) {
		currentTarget = 4;
	}
	else if (c[0] >= destinyPoint[0] && c[1] > 0) {
		currentTarget = 3;
	}
	else if (c[0] <= destinyPoint[1] && c[1] < 0) {
		currentTarget = 1;
	}

	switch (currentTarget)
	{
		case 1: 
			dx = 0; 
			dy = velocity; 
			break; 
		case 2: 
			dx = velocity; 
			dy = 0; 
			break; 
		case 3: 
			dx = 0; 
			dy = -velocity; 
			break; 
		case 4: 
			dx = -velocity; 
			dy = 0; 
			break; 
	default:
		break;
	}
	
	
	
	c[0] += dx;
	c[1] += dy;
	Move(c);
}

void Animator::SetAnimation(std::string name) {
	if (name.compare("Side") == 0) {
		
		HVAnimation(true); 
	}
	else if (name.compare("UpDown") == 0) {
		HVAnimation(false); 
	}
	else if (name.compare("Circular") == 0) {
		CircularAnimation(figure->GetSize() - size); 
	}
	else if (name.compare("Box") == 0) {
		BoxAnimation(); 
	}
}

