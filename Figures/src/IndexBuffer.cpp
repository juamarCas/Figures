#include "IndexBuffer.h"
#include <GL/glew.h>
#include "Renderer.h"


IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) 
	:m_Count(count)
{

	ASSERT(sizeof(unsigned int) == sizeof(GLuint))
	glGenBuffers(1, &m_RendererID);//creo el buffer
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID)); //linkeo el buffer para unos vertices, si pongo 0 este triangulo no se dibujará
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER,count * sizeof(unsigned int), data, GL_STATIC_DRAW)); //reserva de memoria
}

IndexBuffer::~IndexBuffer() {
	GLCall(glDeleteBuffers(1, &m_RendererID)); 
}

void IndexBuffer::Bind() const {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}

void IndexBuffer::Unbind() const {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

}