#include "windows/WindowLabelHierarchy.h"

#include "imgui/imgui.h"

namespace LabelixNS {
	WindowLabelHierarchy::WindowLabelHierarchy() {
		m_WindowName = "LabelHierarchy";
		m_IsOpen = true;
	}
	WindowLabelHierarchy::~WindowLabelHierarchy() {}
	void WindowLabelHierarchy::OnStartup() {
		s_Instance = this;
	}
	void WindowLabelHierarchy::OnUpdate() {}
	void WindowLabelHierarchy::OnRender() {}
	void WindowLabelHierarchy::OnImGuiRender() {
		if (!m_IsOpen) return;
		ImGui::Begin(m_WindowName, &m_IsOpen);

		ImGui::End();
	}

	WindowLabelHierarchy* WindowLabelHierarchy::s_Instance;
}