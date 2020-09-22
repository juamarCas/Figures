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
	dx = ((1 - radius) - size) * cos(auxAngle * PI / 180); 
	dy = ((1 - radius) - size) * sin(auxAngle * PI / 180);
	
	auxAngle -= velocity * 100; 

	if (auxAngle < -360) {
		auxAngle = 0; 
	}
	c[0] = dx; 
	c[1] = dy; 
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
		CircularAnimation(figure->GetSize()); 
	}
}

