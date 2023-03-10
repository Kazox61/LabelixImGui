#include "windows/WindowInspector.h"
#include "rendering/Renderer.h"
#include "imgui/imgui.h"

#include <iostream>

namespace LabelixNS {
	WindowInspector::WindowInspector() {
		m_WindowName = "Inspector";
		m_IsOpen = true;
	}
	WindowInspector::~WindowInspector() {}
	void WindowInspector::OnStartup() {
		s_Instance = this;
		RenderNS::Renderer* renderer = RenderNS::Renderer::GetInstance();
		std::cout << renderer << std::endl;
	}
	void WindowInspector::OnUpdate() {}
	void WindowInspector::OnRender() {}
	void WindowInspector::OnImGuiRender() {
		RenderNS::Renderer* renderer = RenderNS::Renderer::GetInstance();

		if (!m_IsOpen) return;
		ImGui::Begin(m_WindowName, &m_IsOpen);
		ImGui::SliderFloat3("Camera Position", &renderer->m_MainCamera.m_Position.x, 0.0f, 960.0f);
		ImGui::SliderFloat("Camera Scale", &renderer->m_MainCamera.m_Scale, .1f, 10.0f);
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();
	}

	WindowInspector* WindowInspector::s_Instance;
}