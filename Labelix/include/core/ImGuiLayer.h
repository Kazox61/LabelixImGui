#pragma once
#include "core/Window.h"

namespace LabelixNS {
	class ImGuiLayer {
	public:
		void Init(const Window& window);
		void BeginFrame();
		void EndFrame();
		void Free();
	};
}