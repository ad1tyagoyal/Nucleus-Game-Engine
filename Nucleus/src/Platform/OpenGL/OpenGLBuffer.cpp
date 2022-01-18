#include "NclPch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace Nucleus {

	//Vertex Buffer
	OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size, float* vertices) {
		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer() {
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLVertexBuffer::Bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLVertexBuffer::UnBind() const {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	
	//Index Buffer
	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t count, uint32_t* indices) 
		:m_Count(count) {
		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer() {
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLIndexBuffer::Bind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLIndexBuffer::UnBind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}
