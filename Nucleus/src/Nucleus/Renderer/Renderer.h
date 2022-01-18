#pragma once

#include "RendererCommands.h"

namespace Nucleus {

	class Renderer {
	public:
		inline static RendererAPI::API GetAPI() { return RendererAPI::GetRenderingAPI(); }

		static void BeginScene();
		static void EndScene();
		static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

	};
}



