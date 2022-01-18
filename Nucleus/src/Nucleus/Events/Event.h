#pragma once

#include <functional>

#include "Nucleus/Core.h"


namespace Nucleus {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, WindowMinimized,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0, 
		EventCategoryApplication = BIT(0),
		EventCategoryInput       = BIT(1),
		EventCategoryKeyBoard    = BIT(2),
		EventCategoryMouse       = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticEventType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticEventType(); }\
								virtual const char* GetEventName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlag() const override { return category; }


	class NCL_API Event {

		friend class EventDispatcher;
	
	public:
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetEventName() const = 0;
		virtual int GetCategoryFlag() const = 0;
		virtual std::string ToString() const { return GetEventName(); }

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlag() & (int) category;
		} 

	};

	class EventDispatcher {

		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event) 
			: m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_Event.GetEventType() == T::GetStaticEventType()) {
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<< (std::ostream& os, const Event& e) {
		os << e.ToString();
		return os;
	}
}
