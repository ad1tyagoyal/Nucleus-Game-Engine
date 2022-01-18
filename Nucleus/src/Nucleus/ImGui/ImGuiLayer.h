#pragma once

#include "Nucleus/Layer.h"
#include "Nucleus/Events/ApplicationEvent.h"
#include "Nucleus/Events/MouseEvent.h"
#include "Nucleus/Events/KeyEvent.h"

namespace Nucleus {

	class NCL_API ImGuiLayer : public Layer {

	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImguiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	

	};

}

