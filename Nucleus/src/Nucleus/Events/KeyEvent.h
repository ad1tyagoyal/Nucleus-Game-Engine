#pragma once

#include "Nucleus/Events/Event.h"


namespace Nucleus {

	class NCL_API KeyEvent : public Event {

	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyBoard)

	protected:
		KeyEvent(int keycode) 
			:m_KeyCode(keycode) {}

		int m_KeyCode;

	};

	class NCL_API KeyPressedEvent : public KeyEvent {			   

	public:														   
		KeyPressedEvent(int keyCode, int repeatCount) 			   
		: KeyEvent(keyCode), m_RepeatCount(repeatCount) {}	

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Key Pressed Event: " << m_KeyCode << ", Repeat Count: " << m_RepeatCount << std::endl;
			return ss.str();
		}

		inline int GetRepeatCount() const { return m_RepeatCount; }
		
		EVENT_CLASS_TYPE(KeyPressed)

	private:													   										   
		int m_RepeatCount;										   
	
	};	

	class NCL_API KeyReleasedEvent : public KeyEvent {

	public:
		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Key Released Event: " << m_KeyCode << std::endl;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)

	};

	class NCL_API KeyTypedEvent : public KeyEvent {

	public:
		KeyTypedEvent(int keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Key Typed Event: " << m_KeyCode << std::endl;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)

	};
} 