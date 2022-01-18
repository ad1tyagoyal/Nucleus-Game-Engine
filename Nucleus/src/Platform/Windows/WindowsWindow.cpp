#include "NclPch.h"
#include "WindowsWindow.h"

#include "Nucleus/Events/ApplicationEvent.h"
#include "Nucleus/Events/KeyEvent.h"
#include "Nucleus/Events/MouseEvent.h"

#include "Nucleus/Log.h"

#include "Platform/OpenGL/OpenGLContext.h"




namespace Nucleus {

	bool s_GlfwInitialised = false;

	Window* Window::Create(const WindowProp& prop) {
		return new WindowsWindow(prop);
	}

	static void GLFWErrorCallBack(int error, const char* description) {
		NCL_CORE_ERROR("GLFW Error ({0} : {1})", error, description);
	}

	WindowsWindow::WindowsWindow(const WindowProp& prop) {
		Init(prop);
	}

	WindowsWindow::~WindowsWindow() {
		ShutDown();
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	void WindowsWindow::SetVSync(bool enabled) {
		if (enabled) glfwSwapInterval(1);
		else glfwSwapInterval(0);

		m_WindowData.VSync = enabled;
	}

	void WindowsWindow::Init(const WindowProp& prop) {
		m_WindowData.Title = prop.Title;
		m_WindowData.Width = prop.Width;
		m_WindowData.Height = prop.Height;

		if (!s_GlfwInitialised) {
			int success = glfwInit();
			s_GlfwInitialised = true;
			glfwSetErrorCallback(GLFWErrorCallBack);
		}
		m_Window = glfwCreateWindow((int)m_WindowData.Width, (int)m_WindowData.Height, m_WindowData.Title.c_str(), nullptr, nullptr);
		
		
		m_Context = new OpenGLContext(m_Window);
		m_Context->Init();

		glfwSetWindowUserPointer(m_Window, &m_WindowData);
		SetVSync(true);

		//set GLFW Callbacks
		SetEventsCallback();

	}

	void WindowsWindow::SetEventsCallback() {

		glfwSetWindowSizeCallback(m_Window, 
			[](GLFWwindow* window, int width, int height) {

				NCL_CORE_INFO("Window resize");
				WindowsData& data = *(WindowsData*) glfwGetWindowUserPointer(window);
				
				data.Height = height;
				data.Width = width;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(m_Window,
			[](GLFWwindow* window) {
				WindowsData& data = *(WindowsData*) glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(m_Window,
			[](GLFWwindow* window, int key, int scancode, int action, int mods) {
				WindowsData& data = *(WindowsData*) glfwGetWindowUserPointer(window);

				switch (action) {
					case GLFW_PRESS: {
						KeyPressedEvent event(key, 0);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE: {
						KeyReleasedEvent event(key);
						data.EventCallback(event);
						break;
					}
					case GLFW_REPEAT: {
						KeyPressedEvent event(key, 1);
						data.EventCallback(event);
						break;
					}
				}
			});

		glfwSetCharCallback(m_Window, 
			[](GLFWwindow* window, unsigned int character) {
				WindowsData& data = *(WindowsData*) glfwGetWindowUserPointer(window);
				KeyTypedEvent event(character);
				data.EventCallback(event);
			});

		glfwSetMouseButtonCallback(m_Window,
			[](GLFWwindow* window, int button, int action, int mods) {
				WindowsData& data = *(WindowsData*) glfwGetWindowUserPointer(window);

				switch (action) {
					case GLFW_PRESS: {
						MouseButtonPressedEvent event(button);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE: {
						MouseButtonReleasedEvent event(button);
						data.EventCallback(event);
						break;
					}
				}
			});

		glfwSetScrollCallback(m_Window, 
			[](GLFWwindow* window, double xoffset, double yoffset) {
				WindowsData& data = *(WindowsData*) glfwGetWindowUserPointer(window);
				MouseScrolledEvent event((float)xoffset, (float)yoffset);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(m_Window, 
			[](GLFWwindow* window, double xpos, double ypos) {
				WindowsData& data = *(WindowsData*) glfwGetWindowUserPointer(window);
				MouseMovedEvent event((float)xpos, (float)ypos);
				data.EventCallback(event);
			});

	}

	void WindowsWindow::ShutDown() {
		glfwDestroyWindow(m_Window);
	}




}


