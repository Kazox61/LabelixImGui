#pragma once

#include "DockedWindow.h"

namespace LabelixNS {
	class WindowLabelHierarchy : public DockedWindow {
	public:
		static WindowLabelHierarchy* s_Instance;

		WindowLabelHierarchy();
		~WindowLabelHierarchy();

		void OnStartup() override;
		void OnUpdate() override;
		void OnRender() override;
		void OnImGuiRender() override;
	};
}