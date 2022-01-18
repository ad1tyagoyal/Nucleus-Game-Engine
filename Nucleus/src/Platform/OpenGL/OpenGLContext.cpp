#include "NclPch.h"
#include "OpenGLContext.h"

namespace Nucleus {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandler)
		:m_WindowHandler(windowHandler) {}

	OpenGLContext::~OpenGLContext() {
	
	}

	void OpenGLContext::Init() {
		glfwMakeContextCurrent(m_WindowHandler);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	}

	void OpenGLContext::SwapBuffers() {
		glfwSwapBuffers(m_WindowHandler);	
	}

}



