#pragma once
#include "windows/DockedWindow.h"

namespace LabelixNS {
	class MenuBar : public DockedWindow {
	public:
		static MenuBar* s_Instance;

		MenuBar();
		~MenuBar();

		void OnStartup() override;
		void OnUpdate() override;
		void OnRender() override;
		void OnImGuiRender() override;
	};
}