#include "VertexBuffer.h"
#include <GL/glew.h>
#include "Renderer.h"


VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
	glGenBuffers(1, &m_RendererID);//creo el buffer
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)); //linkeo el buffer para unos vertices, si pongo 0 este triangulo no se dibujará
	GLCall(glBufferData(GL_ARRAY_BUFFER,size, data, GL_STATIC_DRAW)); //reserva de memoria
}

VertexBuffer::~VertexBuffer() {
	GLCall(glDeleteBuffers(1, &m_RendererID)); 
}

void VertexBuffer::Bind() const {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::Unbind() const {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));

}

void VertexBuffer::UpdateBufferData(const void* data, unsigned int size) const{
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW)); 
}