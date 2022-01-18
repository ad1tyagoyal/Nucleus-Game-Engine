#include "NclPch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Nucleus/Log.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Nucleus {
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI()) {
		case RendererAPI::API::None:
			NCL_CORE_ERROR("No API Selected!");
		case RendererAPI::API::OpenGL:
			return new OpenGLVertexArray();
		}
	}

}
