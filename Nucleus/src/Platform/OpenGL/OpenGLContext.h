#pragma once

#include "Nucleus/Renderer/RenderingContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct GLFWwindow;

namespace Nucleus {

	class OpenGLContext : public RenderingContext {

	public:
		OpenGLContext(GLFWwindow* windowHandler);
		~OpenGLContext();

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_WindowHandler;

	};

}



