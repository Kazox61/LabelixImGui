#pragma once
#include "DockedWindow.h"

namespace LabelixNS {
	class WindowInspector : public DockedWindow {
	public:
		static WindowInspector* s_Instance;

		WindowInspector();
		~WindowInspector();

		void OnStartup() override;
		void OnUpdate() override;
		void OnRender() override;
		void OnImGuiRender() override;
	};
}