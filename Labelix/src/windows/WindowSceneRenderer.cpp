#include "windows/WindowSceneRenderer.h"
#include "imgui/imgui.h"

#include "rendering/Renderer.h"
#include <iostream>
#include "maths/Math.h"

namespace LabelixNS {
	WindowSceneRenderer::WindowSceneRenderer() 
		: m_ActiveTexture(nullptr)
	{
		m_WindowName = "Scene";
		m_IsOpen = true;
	}
	WindowSceneRenderer::~WindowSceneRenderer() {}
	void WindowSceneRenderer::OnStartup() {
		s_Instance = this;
		m_ActiveTexture = new RenderNS::Texture2d("C:\\temp\\home.png");
		std::cout << "ActiveTextureId: " << m_ActiveTexture << std::endl;
		m_Renderer = RenderNS::Renderer::GetInstance();

		

		MathNS::Color color;
		color.r = 1.0f;
		color.g = 0.0f;
		color.b = 1.0f;
		color.a = 1.0f;
		m_Renderer->AddRect(0.0f, 0.0f, 100.0f, 100.0f, 1, color);
	}
	void WindowSceneRenderer::OnUpdate() {
		
	}

	void WindowSceneRenderer::OnRender() {
		if (m_ActiveTexture != nullptr) {
			std::cout << "Render Texture" << std::endl;
			m_ActiveTexture->Render();
		}
	}

	void WindowSceneRenderer::OnImGuiRender() {
		if (!m_IsOpen) return;
		ImGui::Begin(m_WindowName, &m_IsOpen);
		ImVec2 size = ImGui::GetContentRegionAvail();
		
		if (size.x != m_WidowWidth || size.y != m_WindowHeight) {
			m_WidowWidth = size.x;
			m_WindowHeight = size.y;
			std::cout << "Screensize = " << size.x << " , " << size.y << std::endl;
			m_Renderer->m_FrameBuffer->UpdateSize(size.x, size.y);

			m_Renderer->m_MainCamera.m_Projection = glm::ortho(0.0f, size.x, 0.0f, size.y, -1.0f, 1.0f);
		}
		ImVec2 uv0 = ImVec2(0.0f, 1.0f);
		ImVec2 uv1 = ImVec2(1.0f, 0.0f);
		ImGui::Image((void*)(intptr_t)m_Renderer->m_FrameBuffer->m_TextureId, size, uv0, uv1);

		ImGui::End();
	}

	WindowSceneRenderer* WindowSceneRenderer::s_Instance;
}