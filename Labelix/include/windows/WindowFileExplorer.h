#pragma once

#include "DockedWindow.h"

#include <filesystem>
#include <vector>

namespace LabelixNS {
	class WindowFileExplorer : public DockedWindow {
	public:
		static WindowFileExplorer* s_Instance;

		WindowFileExplorer();
		~WindowFileExplorer();

		void OnStartup() override;
		void OnUpdate() override;
		void OnRender() override;
		void OnImGuiRender() override;

	private:
		std::filesystem::path m_ActiveFilePath;

		void DisplayDirectories(std::filesystem::path path);
	};
}
