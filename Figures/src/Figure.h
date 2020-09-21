#pragma once
#include <GL/glew.h>
#include "Renderer.h"

class Figure {
protected: 
	float *position;
	unsigned int *index;
	float size; 
	float velocity; 
	int animationOP;
	int indexCount; 
	int posCount; 
	float centerY; 
	float centerX; 
	int vertexCount; //number of data of the vertex
	

public:  

	Figure(float size, float centerX, float centerY); 
	~Figure(); 

	virtual void SetPos();
	virtual void SetIndex();
	virtual int GetVertexCount();

	
	unsigned int* GetIndex(); 

	//size is the side of a square, radius of a circule etc.
	float GetSize();

	void SetCenter(float *); 

	//position of the vertex 
	float * GetPositions();
	//center of the figure
	float * GetCenter(); 

	

};


