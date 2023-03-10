#pragma once

#include "windows/WindowFileExplorer.h"
#include "windows/MenuBar.h"
#include "windows/WindowSceneRenderer.h"
#include "windows/WindowLabelHierarchy.h"
#include "windows/WindowInspector.h"

#include <vector>


namespace LabelixNS {
	class ControllerWindows {
	private:

	public:
		std::vector<DockedWindow*> m_Windows;

		ControllerWindows();
		~ControllerWindows();

		void OnStartup();
		void OnUpdate();
		void OnRender();
		void OnImGuiRender();
	};
}
