#include "NclPch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Nucleus {

	OpenGLVertexArray::OpenGLVertexArray() {
		glCreateVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const {
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::UnBind() const {
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) {
		glBindVertexArray(m_RendererID);

		vertexBuffer->Bind();
		uint32_t index = 0;
		const BufferLayout& layout = vertexBuffer->GetLayout();
		for (const BufferElement& element : layout) {
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, 
								  element.GetElementCount(), 
								  GL_FLOAT, GL_FALSE,
								  layout.GetStride(), 
				                  (const void*)element.Offset);
			index++;
		}
		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) {
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();
		m_IndexBuffer = indexBuffer;
	}

}

