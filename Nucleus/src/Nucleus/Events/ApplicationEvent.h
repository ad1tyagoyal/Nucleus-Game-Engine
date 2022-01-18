#pragma once

#include "Nucleus/Events/Event.h"

namespace Nucleus {

	class NCL_API WindowResizeEvent :public Event {
		
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Window Resize Event: " << m_Width << ", " << m_Height << std::endl;
			return ss.str();
		}
		
		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowResize)

	private:
		unsigned int m_Width;
		unsigned int m_Height;

	};

	class NCL_API WindowCloseEvent : public Event {

	public:
		WindowCloseEvent() {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Window Close Event" << std::endl;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowClose)

	};

	class NCL_API AppTickEvent : public Event {

	public: 
		AppTickEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppTick)

	};

	class NCL_API AppUpdateEvent : public Event {

	public:
		AppUpdateEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppUpdate)

	};

	class NCL_API AppRenderEvent : public Event {

	public:
		AppRenderEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppRender)

	};

}

