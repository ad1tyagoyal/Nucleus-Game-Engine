#include "NclPch.h"
#include "Buffer.h"

#include "Nucleus/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

#include "Nucleus/Log.h"

namespace Nucleus {

    VertexBuffer* VertexBuffer::Create(uint32_t size, float* vertices) {
        switch (Renderer::GetAPI()) {
        case RendererAPI::API::None:
            NCL_CORE_ERROR("No API Selected!");
        case RendererAPI::API::OpenGL:
            return new OpenGLVertexBuffer(size, vertices);
        }
    }

    IndexBuffer* IndexBuffer::Create(uint32_t count, uint32_t* indices) {
        switch (Renderer::GetAPI()) {
        case RendererAPI::API::None:
            NCL_CORE_ERROR("No API Selected!");
        case RendererAPI::API::OpenGL:
            return new OpenGLIndexBuffer(count, indices);
        }
    }

}

