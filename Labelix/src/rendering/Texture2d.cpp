#include "rendering/Texture2d.h"

#include "stb/stb_image.h"
#include "rendering/RenderLayer.h"
#include "rendering/Renderer.h"

#include <iostream>

namespace LabelixNS {
	namespace RenderNS {
		Texture2d::Texture2d(const std::string& path)
			: m_RendererId(0), m_FilePath(path), m_LocalBuffer(nullptr), m_Width(0), m_Height(0), m_BPP(0)
		{
			stbi_set_flip_vertically_on_load(1);
			m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

			GLCall(glGenTextures(1, &m_RendererId));
			GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererId));

			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

			GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));
			GLCall(glBindTexture(GL_TEXTURE_2D, 0));

			if (m_LocalBuffer) {
				stbi_image_free(m_LocalBuffer);
			}
			std::cout << m_Width << " | " << m_Height << std::endl;
			Create();
		}

		Texture2d::~Texture2d() {
			GLCall(glDeleteTextures(1, &m_RendererId));
		}


		void Texture2d::Create() {
			float vertices[] = {
				0.0f, 0.0f, 0.0f, 0.0f,
				m_Width, 0.0f, 1.0f, 0.0f,
				m_Width, m_Height, 1.0f, 1.0f,
				0.0f, m_Height, 0.0f, 1.0f
			};

			unsigned int indices[] = {
				0,1,2,
				2,3,0
			};

			m_VertexArray = new VertexArray();
			RenderNS::VertexBuffer vertexBuffer(vertices, 4 * 4 * sizeof(float));

			RenderNS::VertexBufferLayout layout;
			layout.Push<float>(2);
			layout.Push<float>(2);
			m_VertexArray->AddBuffer(vertexBuffer, layout);

			m_IndexBuffer = new IndexBuffer(indices, 6);

			m_VertexArray->Unbind();
			vertexBuffer.Unbind();
			m_IndexBuffer->Unbind();
		}

		void Texture2d::Render() const {
			Renderer* renderer = Renderer::GetInstance();
			Bind();
			renderer->Draw(*m_VertexArray, *m_IndexBuffer, 1);
			Unbind();
		}

		void Texture2d::Bind(unsigned int slot) const {
			GLCall(glActiveTexture(GL_TEXTURE0 + slot))
			GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererId));

		}

		void Texture2d::Unbind() const {
			GLCall(glBindTexture(GL_TEXTURE_2D, 0));
		}

	}
}