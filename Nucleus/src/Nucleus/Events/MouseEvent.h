#pragma once

#include "Nucleus/Events/Event.h"

namespace Nucleus {

	class NCL_API MouseMovedEvent : public Event {

	public:
		MouseMovedEvent(float x, float y)
			: m_X(x), m_Y(y) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Mouse Moved Event " << m_X << ", " << m_Y << std::endl;
			return ss.str();
		}
		
		inline float GetMouseX() const { return m_X; }
		inline float GetMouseY() const { return m_Y; }

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

	private:
		float m_X, m_Y;

	};


	class NCL_API MouseScrolledEvent : public Event {

	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Mouse Scrolled Event " << m_XOffset << ", " << m_YOffset << std::endl;
			return ss.str();
		}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

	private:
		float m_XOffset, m_YOffset;

	};

	class NCL_API MouseButtonEvent : public Event {

	public:
		inline int GetMouseButton() const { return m_KeyCode; }

	protected:
		MouseButtonEvent(int keyCode)
			: m_KeyCode(keyCode) {}
		
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
	
		int m_KeyCode;
	
	};

	class NCL_API MouseButtonPressedEvent : public MouseButtonEvent {

	public:
		MouseButtonPressedEvent(int keyCode)
			: MouseButtonEvent(keyCode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Mouse Button Pressed " << m_KeyCode << std::endl;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)

	};

	class NCL_API MouseButtonReleasedEvent : public MouseButtonEvent {

	public:
		MouseButtonReleasedEvent(int keyCode)
			: MouseButtonEvent(keyCode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Mouse Button Released " << m_KeyCode << std::endl;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)

	};




}

