#include "NclPch.h"
#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Nucleus {
	
	OrthographicCamera::OrthographicCamera(float right, float left, float top, float bottom) {
		m_ProjectionMat = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
		RecalculateViewMat();
	}

	OrthographicCamera::~OrthographicCamera() {
	}
	
	void OrthographicCamera::SetPosition(glm::vec3 position) {
		m_Position = position;
		RecalculateViewMat();
	}

	void OrthographicCamera::SetRotation(float rotation) {
		m_RotationZ = rotation;
		RecalculateViewMat();
	}

	void OrthographicCamera::RecalculateViewMat() {
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position) *
			glm::rotate(glm::mat4(1.0f), glm::radians(m_RotationZ), glm::vec3(0.0f, 0.0f, 1.0f));

		m_ViewMat = glm::inverse(transform);
		m_ViewProjectionMat = m_ProjectionMat * m_ViewMat;
	}
}
