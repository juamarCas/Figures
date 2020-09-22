#include "Animator.h"

Animator::Animator(Figure * figure, float velocity) {
	this->velocity = velocity; 
	this->figure = figure;
	
}

void Animator::Move(float dx, float dy, float *c) {
	//c is the center of the figure
	for (int i = 0; i < figure->GetVertexCount(); i += 2) {
		c[0] += dx; 
		c[1] += dy; 
		 
	}
	figure->SetCenter(c);
	figure->SetPos(); 
}

void Animator::HVAnimation(bool horizontal) {
	
	c = figure->GetCenter(); 
	if (horizontal) {
		if (c[0] > 1 - figure->GetSize()) {
			dx = -velocity;
			dy = 0;
		}
		else if (c[0] < figure->GetSize() - 1 || dx == 0) {
			dx = velocity;
			dy = 0;
		}
	}
	else {
		if (c[1] > 1 - figure->GetSize()) {
			dx = 0;
			dy = -velocity;
		}
		else if (c[1] < figure->GetSize() - 1 || dy == 0) {
			dx = 0;
			dy = velocity;
		}
	}
	
	

	Move(dx, dy , c); 
	
}

void Animator::SetAnimation(std::string name) {
	if (name.compare("Side") == 0) {
		HVAnimation(true); 
	}
	else if (name.compare("UpDown") == 0) {
		HVAnimation(false); 
	}
}