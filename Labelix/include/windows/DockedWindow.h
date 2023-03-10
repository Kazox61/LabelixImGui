#pragma once

namespace LabelixNS {
	class DockedWindow {
	public:
		bool m_IsOpen;
		const char* m_WindowName;

		DockedWindow() {}

		virtual ~DockedWindow() {}
		virtual void OnStartup() {}
		virtual void OnUpdate() {}
		virtual void OnRender() {}
		virtual void OnImGuiRender() {}
	};
}