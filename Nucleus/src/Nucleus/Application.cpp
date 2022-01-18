#include "NclPch.h"

#include "Application.h"
#include "Nucleus/Events/ApplicationEvent.h"
#include <Nucleus/Log.h>

#include "Input.h"

#include "Nucleus/Renderer/Renderer.h"


namespace Nucleus {

	Application* Application::s_Instance = nullptr;



	Application::Application() {

		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}
	
	Application::~Application() {

	}

	void Application::OnEvent(Event& e) {
		//NCL_CORE_INFO("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) {
			(*--it)->OnEvent(e);

			if (e.Handled) break;
		}
	}

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer) {
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();

			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate();
			}

			m_ImGuiLayer->Begin();

			for (Layer* layer : m_LayerStack) {
				layer->OnImguiRender();
			}

			m_ImGuiLayer->End();
		}
	}

}
