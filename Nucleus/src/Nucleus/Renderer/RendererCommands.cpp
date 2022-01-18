#include "NclPch.h"
#include "RendererCommands.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Nucleus {

	RendererAPI* RendererCommands::s_RendererAPI = new OpenGLRendererAPI;

}
