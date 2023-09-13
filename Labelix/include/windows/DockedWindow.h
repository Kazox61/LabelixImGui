#pragma once

namespace LabelixNS {
	class DockedWindow {
	public:
		bool m_IsOpen;
		const char* m_WindowName;
		unsigned int m_WidowWidth;
		unsigned int m_WindowHeight;

		DockedWindow() {}

		virtual ~DockedWindow() {}
		virtual void OnStartup() {}
		virtual void OnUpdate() {}
		virtual void OnRender() {}
		virtual void OnImGuiRender() {}
	};
}