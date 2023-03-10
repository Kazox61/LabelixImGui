#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace LabelixNS {
	class Window {
	public:
		int m_Width, m_Height;
		const char* m_Title;
		void* m_WindowPtr;

		Window(int width, int height, const char* title);

		void MakeContextCurrent();
		void PollInput();
		void SwapBuffers();
		void Update(float deltaTime);
		bool ShouldClose();
		void SetVSync(bool on);
		void SetTitle(const std::string& newTitle);
		float GetContentScale() const;
		void Close();
		void Terminate();
	};
}