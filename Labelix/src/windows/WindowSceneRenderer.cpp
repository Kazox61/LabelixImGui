#include "windows/WindowSceneRenderer.h"
#include "imgui/imgui.h"

#include "rendering/Renderer.h"
#include <iostream>

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
		
		/*
		float vertices[] = {
			-50.0f, -50.0f,
			 50.0f, -50.0f,
			 50.0f,  50.0f,
			-50.0f,  50.0f
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		m_VertexArray = new RenderNS::VertexArray();
		RenderNS::VertexBuffer vertexBuffer(vertices, 4 * 2 * sizeof(float));

		RenderNS::VertexBufferLayout layout;
		layout.Push<float>(2);
		m_VertexArray->AddBuffer(vertexBuffer, layout);

		m_IndexBuffer = new RenderNS::IndexBuffer(indices, 6);

		m_VertexArray->Unbind();
		vertexBuffer.Unbind();
		m_IndexBuffer->Unbind();
		*/


		RenderNS::Renderer renderer = *RenderNS::Renderer::GetInstance();

		for (unsigned int x = 0; x < 9; x++) {
			for (unsigned int y = 0; y < 6; y++) {
				MathNS::Color color;
				color.r = x * y * 0.01;
				color.g = x * y * 0.01;
				color.b = x * y * 0.01;
				color.a = 1.0f;
				renderer.AddFilledRect(x * 100, y * 100, 100, 100, color);
			}
		}


	}
	void WindowSceneRenderer::OnUpdate() {}
	void WindowSceneRenderer::OnRender() {
		if (m_ActiveTexture != nullptr) {
			m_ActiveTexture->Render();
		}
	}
	void WindowSceneRenderer::OnImGuiRender() {
		if (!m_IsOpen) return;
		ImGui::Begin(m_WindowName, &m_IsOpen);

		ImGui::End();
	}

	WindowSceneRenderer* WindowSceneRenderer::s_Instance;
}