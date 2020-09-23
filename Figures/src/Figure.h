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
	float red; 
	float green; 
	float blue; 
	

public:  

	Figure(float size, float centerX, float centerY, float red, float green, float blue); 
	~Figure(); 

	virtual void SetPos();
	virtual void SetIndex();

	virtual int GetVertexCount();

	virtual float GetWidth(); 
	virtual float GetHeight(); 

	int GetIndexCount(); 
	
	unsigned int* GetIndex(); 

	//size is the side of a square, radius of a circule etc.
	float GetSize();
	float * GetColors(); 

	void SetCenter(float *);
	

	//position of the vertex 
	float * GetPositions();
	//center of the figure
	float * GetCenter(); 


	

};


