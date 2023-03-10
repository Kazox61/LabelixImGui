#include "core/ControllerWindows.h"

#include <iostream>

namespace LabelixNS {
	ControllerWindows::ControllerWindows() {
		std::cout << "Controller Windows Constructed" << std::endl;
		m_Windows.push_back(new MenuBar);
		m_Windows.push_back(new WindowFileExplorer);
		m_Windows.push_back(new WindowSceneRenderer);
		m_Windows.push_back(new WindowLabelHierarchy);
		m_Windows.push_back(new WindowInspector);

		std::cout << "Windows Constructed" << std::endl;
	}
	ControllerWindows::~ControllerWindows() {
		for (auto& window : m_Windows) {
			delete window;
		}
	}
	void ControllerWindows::OnStartup() {
		for (auto& window : m_Windows) {
			window->OnStartup();
		}
	}
	void ControllerWindows::OnUpdate() {
		for (auto& window : m_Windows) {
			window->OnUpdate();
		}
	}
	void ControllerWindows::OnRender() {
		for (auto& window : m_Windows) {
			window->OnRender();
		}
	}
	void ControllerWindows::OnImGuiRender() {
		for (auto& window : m_Windows) {
			window->OnImGuiRender();
		}
	}
}