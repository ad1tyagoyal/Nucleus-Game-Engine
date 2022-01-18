#pragma once

#include "NclPch.h"
#include "Nucleus/Core.h"
#include "Nucleus/Events/Event.h"


namespace Nucleus {

	struct WindowProp {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProp(const std::string& title = "Nucleus Windows",
					unsigned int width = 1920,
					unsigned int height = 1080)
			: Title(title), Width(width), Height(height) {}
	};

	class NCL_API Window {

	public:
		using EventCallbackFn = std::function<void(Event&)>;
		
		virtual ~Window() {};
		virtual void OnUpdate() = 0;
		
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//windows attribute
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProp& prop = WindowProp());

	};


}
