#include "NclPch.h"
#include "ImGuiLayer.h"
#include "Nucleus/Application.h"

#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Nucleus {

	ImGuiLayer::ImGuiLayer()
		:Layer("ImGuiLayer") {
	}
	

	ImGuiLayer::~ImGuiLayer() {
	}

	void ImGuiLayer::OnAttach() {

		//set up Dear ImGui
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO();
		
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;			//enable keyboard control
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;				//enable docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;             //enable multi-viewport

		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;


		//SetUp Dear ImGui Style
		ImGui::StyleColorsDark();

		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		Application& app = Application::Get();
		//Give window of API that we are using currently OpenGL
		GLFWwindow* window = static_cast<GLFWwindow*> (app.GetWindow().GetNativeWindow()); 
        
		//SetUp Platform/Renderer Bindings
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		const char* version = "#version 410";
		ImGui_ImplOpenGL3_Init(version);
	}

	void ImGuiLayer::OnDetach() {
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::Begin() {
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::End() {
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		//Rendering
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
			GLFWwindow* back_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(back_current_context);
		}

	}

	void ImGuiLayer::OnImguiRender() {
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}

	
}

