#include "windows/WindowFileExplorer.h"
#include "imgui/imgui.h"
#include "windows/WindowSceneRenderer.h"

namespace LabelixNS {
	WindowFileExplorer::WindowFileExplorer() {
		m_WindowName = "FileExplorer";
		m_IsOpen = true;
	}
	WindowFileExplorer::~WindowFileExplorer() {}
	void WindowFileExplorer::OnStartup() {
		s_Instance = this;
	}
	void WindowFileExplorer::OnUpdate() {}
	void WindowFileExplorer::OnRender() {}
	void WindowFileExplorer::OnImGuiRender() {
		if (!m_IsOpen) return;
		ImGui::Begin(m_WindowName, &m_IsOpen);

		std::filesystem::path path("C:\\");
		DisplayDirectories(path);

		ImGui::End();
	}

	void WindowFileExplorer::DisplayDirectories(std::filesystem::path path) {
		for (auto& element : std::filesystem::directory_iterator(path)) {
			if (element.is_directory()) {
				if (ImGui::TreeNode(element.path().filename().string().c_str())) {
					DisplayDirectories(element.path());
					ImGui::TreePop();
				}
				continue;
			}

			bool isSelected = element.path() == m_ActiveFilePath;
			if (ImGui::Selectable(element.path().filename().string().c_str(), isSelected)) {
				if (m_ActiveFilePath != element.path()) {
					// TODO: SetTexture in Renderer
					WindowSceneRenderer::s_Instance->m_ActiveTexture = new RenderNS::Texture2d(element.path().string().c_str());
				}
				
				m_ActiveFilePath = element.path();
			}
		}
	}

	WindowFileExplorer* WindowFileExplorer::s_Instance;
}