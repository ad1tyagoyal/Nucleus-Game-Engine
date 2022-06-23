#include "NclPch.h"
#include "Renderer.h"

namespace Nucleus {

	void Renderer::BeginScene() {
		RendererCommands::Clear();
	}
	
	void Renderer::EndScene() {
	
	}
	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray) {
		vertexArray->Bind();
		RendererCommands::DrawIndexed(vertexArray);
	}

}
