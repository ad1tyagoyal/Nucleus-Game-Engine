#include <Nucleus.h>

class ExampleLayer : public Nucleus::Layer {

public:
	ExampleLayer()
		:Layer("ExampleLayer"), m_OrthoCam(1.0f, -1.0f, 1.0f, -1.0f), m_CameraPosition({0.0f, 0.0f, 0.0f}), m_CameraRotationZ(0.0) {
	
		//vertex array
		m_VertexArray.reset(Nucleus::VertexArray::Create());

		//vertex buffer
		float vertices[3 * 3] = {
			-0.5f, 0.0f, 0.0f,
			 0.5f, 0.0f, 0.0f,
			 0.0f, 0.5f, 0.0f
		};

		m_VertexBuffer.reset(Nucleus::VertexBuffer::Create(sizeof(vertices), vertices));

		Nucleus::BufferLayout layout = {
			{Nucleus::ShaderDataType::Float3, "a_Position"}
		};

		m_VertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(m_VertexBuffer);

		//buffer layout
		//index buffer
		uint32_t indices[3] = { 0, 1, 2 };

		m_IndexBuffer.reset(Nucleus::IndexBuffer::Create(3, indices));
		m_VertexArray->SetIndexBuffer(m_IndexBuffer);

		std::string vertexShader = R"(

		#version 330 core
		layout (location = 0) in vec3 position;
		out vec3 v_Position;
		uniform mat4 u_ViewProjectionMat;
		
		void main() {
			gl_Position = u_ViewProjectionMat * vec4(position, 1.0f);
			v_Position = position;	
		}
		)";

		std::string fragmentShader = R"(

		#version 330 core
		layout (location = 0) out vec4 color;

		in vec3 v_Position;
		
		void main() {
			color = vec4(v_Position * 0.5f + 0.5f, 1.0f);	
		}
		)";

		m_Shader.reset(new Nucleus::Shader(fragmentShader, vertexShader));
		m_Shader->Bind();
	}

	void OnUpdate() override {
		if (Nucleus::Input::IsKeyPressed(NCL_KEY_A))
			m_CameraPosition.x -= m_CameraMovingSpeed;
		if(Nucleus::Input::IsKeyPressed(NCL_KEY_D))
			m_CameraPosition.x += m_CameraMovingSpeed;
		if(Nucleus::Input::IsKeyPressed(NCL_KEY_W))
			m_CameraPosition.y += m_CameraMovingSpeed;
		if(Nucleus::Input::IsKeyPressed(NCL_KEY_S))
			m_CameraPosition.y -= m_CameraMovingSpeed;
		
		if(Nucleus::Input::IsKeyPressed(NCL_KEY_O))
			m_CameraRotationZ += m_CameraRotationSpeed;
		if(Nucleus::Input::IsKeyPressed(NCL_KEY_P))
			m_CameraRotationZ -= m_CameraRotationSpeed;
		

		Nucleus::Renderer::BeginScene();

		m_OrthoCam.SetPosition(m_CameraPosition);
		m_OrthoCam.SetRotation(m_CameraRotationZ);

		Nucleus::RendererCommands::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		m_Shader->SetUniformMatrix4fv("u_ViewProjectionMat", 1, 0, glm::value_ptr(m_OrthoCam.GetViewProjectionMat()));
		Nucleus::Renderer::Submit(m_VertexArray);

		Nucleus::Renderer::EndScene();
	}
	void OnEvent(Nucleus::Event& e) override {
		//NCL_TRACE("{0}", e);
	}

private:
	std::shared_ptr<Nucleus::Shader> m_Shader;
	std::shared_ptr<Nucleus::VertexArray> m_VertexArray;
	std::shared_ptr<Nucleus::VertexBuffer> m_VertexBuffer;
	std::shared_ptr<Nucleus::IndexBuffer> m_IndexBuffer;
	Nucleus::OrthographicCamera m_OrthoCam;

	glm::vec3 m_CameraPosition;
	float m_CameraRotationZ;

	float m_CameraMovingSpeed = 0.1f;
	float m_CameraRotationSpeed = 1.0f;
};


class SandBoxApplication : public Nucleus::Application {
	 
public:
	SandBoxApplication() {
		PushLayer(new ExampleLayer());
		NCL_ERROR("Error");
		NCL_WARN("Warn");
		NCL_INFO("Info");
		NCL_TRACE("trace");
	}

	~SandBoxApplication () {

	}
};


Nucleus::Application* Nucleus::CreateApplication()
{
	return new SandBoxApplication();
}