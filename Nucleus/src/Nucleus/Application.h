#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "LayerStack.h"
#include "ImGui/ImGuiLayer.h"
#include "Renderer/Shader.h"
#include "Nucleus/Renderer/Buffer.h"
#include "Nucleus/Renderer/VertexArray.h"

#include "Nucleus/Renderer/Camera.h"



namespace Nucleus {

	class NCL_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() const { return *m_Window; }

	private:
		std::unique_ptr<Window> m_Window;
		static Application* s_Instance;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

	};

	//To be defined in client	
	Application* CreateApplication();
}

 