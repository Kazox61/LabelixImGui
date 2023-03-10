#include "core/Window.h"

#include <iostream>

namespace LabelixNS {
	Window::Window(int width, int height, const char* title)
		: m_Width(width), m_Height(height), m_Title(title)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
		glfwWindowHint(GLFW_SAMPLES, 4);
		//glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

		m_WindowPtr = (void*)glfwCreateWindow(width, height, title, nullptr, nullptr);
		if (m_WindowPtr == nullptr)
		{
			glfwTerminate();
			return;
		}
		glfwSetWindowUserPointer((GLFWwindow*)m_WindowPtr, (void*)this);
		MakeContextCurrent();

		//glfwSetCursorPosCallback((GLFWwindow*)windowPtr, Input::mouseCallback);
		//glfwSetKeyCallback((GLFWwindow*)windowPtr, Input::keyCallback);
		//glfwSetMouseButtonCallback((GLFWwindow*)windowPtr, Input::mouseButtonCallback);
		//glfwSetScrollCallback((GLFWwindow*)windowPtr, Input::scrollCallback);
		//glfwSetFramebufferSizeCallback((GLFWwindow*)windowPtr, resizeCallback);

		glfwGetWindowSize((GLFWwindow*)m_WindowPtr, &width, &height);

	}

	void Window::MakeContextCurrent() {
		glfwMakeContextCurrent((GLFWwindow*)m_WindowPtr);

		if (glewInit() != GLEW_OK) {
			std::cout << "Glew Initialization failed" << std::endl;
		}
		else {
			std::cout << "Glew Initialization succeded" << std::endl;
		}
	}

	void Window::PollInput() {
		glfwPollEvents();
	}

	void Window::SwapBuffers() {
		glfwSwapBuffers((GLFWwindow*)m_WindowPtr);
	}

	void Window::Update(float deltaTime) {

	}

	bool Window::ShouldClose() {
		return glfwWindowShouldClose((GLFWwindow*)m_WindowPtr);
	}

	void Window::SetVSync(bool on) {
		if (on)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}
	}

	void Window::SetTitle(const std::string& newTitle) {
		glfwSetWindowTitle((GLFWwindow*)m_WindowPtr, newTitle.c_str());
	}

	float Window::GetContentScale() const {
		float xScale, yScale;
		glfwGetWindowContentScale((GLFWwindow*)m_WindowPtr, &xScale, &yScale);

		return xScale;
	}

	void Window::Close() {
		glfwSetWindowShouldClose((GLFWwindow*)m_WindowPtr, true);
	}

	void Window::Terminate() {
		glfwTerminate();
	}
}