#pragma once

#include "Nucleus/Window.h"
#include "Nucleus/Renderer/RenderingContext.h"

struct GLFWwindow;


namespace Nucleus {

	class WindowsWindow : public Window {
		
	public:
		WindowsWindow(const WindowProp& prop);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_WindowData.Width; }
		inline unsigned int GetHeight() const override { return m_WindowData.Height; }

		void SetEventCallback(const EventCallbackFn& callback) override { m_WindowData.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		inline bool IsVSync() const override { return m_WindowData.VSync; };
		inline virtual void* GetNativeWindow() const { return m_Window; }

	private:
		virtual void Init(const WindowProp& prop);
		virtual void ShutDown();
		void SetEventsCallback();
		RenderingContext* m_Context;

	private:
		//we can also make a abstraction layer for type of window we are going to use on Windows platform (OpenGL, DirectX 3D, Vulkan etc)
		GLFWwindow* m_Window;

		struct WindowsData {
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool VSync;
			EventCallbackFn EventCallback;
		};

		WindowsData m_WindowData;
	};


}

