#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Nucleus {

	class OrthographicCamera {
	public:
		OrthographicCamera(float right, float left, float top, float bottom);
		~OrthographicCamera();

		void SetPosition(glm::vec3 position);
		inline glm::vec3& GetPosition() { return m_Position; }
		
		void SetRotation(float rotation);
		inline float GetRotation() { return m_RotationZ; }

		inline glm::mat4& GetViewMat() { return m_ViewMat; }
		inline glm::mat4& GetProjectionMat() { return m_ProjectionMat; }
		inline glm::mat4& GetViewProjectionMat() { return m_ViewProjectionMat; }

	private:
		void RecalculateViewMat();

	private:
		glm::vec3 m_Position = {0.0f, 0.0f, 0.0f};
		float m_RotationZ = 0.0f;

		glm::mat4 m_ViewMat;
		glm::mat4 m_ProjectionMat;
		glm::mat4 m_ViewProjectionMat;
	};

}



