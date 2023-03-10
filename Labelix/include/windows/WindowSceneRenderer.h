#pragma once

#include "DockedWindow.h"

#include "rendering/Renderer.h"
#include "rendering/Texture2d.h"

namespace LabelixNS {
	class WindowSceneRenderer : public DockedWindow {
	public:
		static WindowSceneRenderer* s_Instance;

		RenderNS::Texture2d* m_ActiveTexture;

		WindowSceneRenderer();
		~WindowSceneRenderer();

		void OnStartup() override;
		void OnUpdate() override;
		void OnRender() override;
		void OnImGuiRender() override;
	private:

		RenderNS::VertexArray* m_VertexArray;
		RenderNS::IndexBuffer* m_IndexBuffer;
	};
}