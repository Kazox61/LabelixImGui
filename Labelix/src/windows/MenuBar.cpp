#include "windows/MenuBar.h"

#include "windows/WindowFileExplorer.h"
#include "windows/WindowSceneRenderer.h"
#include "windows/WindowLabelHierarchy.h"
#include "windows/WindowInspector.h"

#include "imgui/imgui.h"

namespace LabelixNS {
	MenuBar::MenuBar() {}
	MenuBar::~MenuBar() {}
	void MenuBar::OnStartup() {}
	void MenuBar::OnUpdate() {}
	void MenuBar::OnRender() {}

	void MenuBar::OnImGuiRender() {
        if (ImGui::BeginMainMenuBar()) {
			if (ImGui::BeginMenu("File")) {
				if (ImGui::MenuItem("Save Project", "Ctrl+S")) {

				}

				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("Layouts")) {
				ImGui::MenuItem("default", "", nullptr);

				ImGui::EndMenu();
			}

            if (ImGui::BeginMenu("Windows")) {
				ImGui::MenuItem(WindowFileExplorer::s_Instance->m_WindowName, "", &WindowFileExplorer::s_Instance->m_IsOpen);
				ImGui::MenuItem(WindowSceneRenderer::s_Instance->m_WindowName, "", &WindowSceneRenderer::s_Instance->m_IsOpen);
				ImGui::MenuItem(WindowLabelHierarchy::s_Instance->m_WindowName, "", &WindowLabelHierarchy::s_Instance->m_IsOpen);
				ImGui::MenuItem(WindowInspector::s_Instance->m_WindowName, "", &WindowInspector::s_Instance->m_IsOpen);

                ImGui::EndMenu();
            }


            ImGui::EndMainMenuBar();
        }
	}

	MenuBar* MenuBar::s_Instance;
}