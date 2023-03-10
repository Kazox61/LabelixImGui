#pragma once

#include "core/Window.h"
#include "core/ImGuiLayer.h"
#include "core/ControllerWindows.h"
#include "rendering/Renderer.h"

namespace LabelixNS {
	class LabelApp {
	public:
		Window* m_Window;
		ImGuiLayer* m_ImGuiLayer;
		double m_PreviousTime;

		ControllerWindows m_ControllerWindows;
		RenderNS::Renderer m_Renderer;

		LabelApp();
		~LabelApp();

		void Run();
	};
}