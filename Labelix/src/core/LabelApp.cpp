#include "core/LabelApp.h"

namespace LabelixNS {
	LabelApp::LabelApp()
		: m_Window(nullptr), m_PreviousTime(0)
	{
		m_Window = new Window(960, 540, "Labelix");
		m_Window->SetVSync(true);
		m_ImGuiLayer->Init(*m_Window);
		m_Renderer.Init();
		m_ControllerWindows.OnStartup();
	}

	LabelApp::~LabelApp() {
		m_ImGuiLayer->Free();
		m_Window->Terminate();
	}

	void LabelApp::Run() {
		double previousTime = glfwGetTime() - 0.16f;
		float deltaTime = 0.0f;

		while (!m_Window->ShouldClose()) {
			deltaTime = (float)(glfwGetTime() - previousTime);
			previousTime = glfwGetTime();
			m_Renderer.m_FrameBuffer->Activate();
			m_Window->PollInput();
			m_ImGuiLayer->BeginFrame();

			m_ControllerWindows.OnUpdate();
			m_ControllerWindows.OnRender();
			m_Renderer.Draw();
			m_Renderer.m_FrameBuffer->Deactivate();
			m_ControllerWindows.OnImGuiRender();

			
			m_ImGuiLayer->EndFrame();
			m_Window->SwapBuffers();
		}
	}
}