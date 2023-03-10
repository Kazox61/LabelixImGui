#include "rendering/Renderer.h"

#include <iostream>
#include "rendering/RenderLayer.h"

namespace LabelixNS {
	namespace RenderNS {
		
		Renderer* Renderer::s_Instance;

		Renderer::Renderer()
			: m_ShaderDefault(nullptr), m_ShaderTexture(nullptr)
		{
			std::cout << "Renderer Constructed!" << std::endl;
		}

		Renderer::~Renderer() {

		}

		void Renderer::Init() {
			s_Instance = this;
			EnableBlend();

			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

			m_ShaderDefault = new Shader("assets/shaders/DefaultShader.shader");
			m_ShaderDefault->Bind();
			m_ShaderDefault->SetUniform4f("u_Color", 1.0f, 0.0f, 1.0f, 1.0f);
			m_ShaderTexture = new Shader("assets/shaders/TextureShader.shader");

			std::cout << this << std::endl;

			for (unsigned int x = 0; x < 9; x++) {
				for (unsigned int y = 0; y < 6; y++) {
					MathNS::Color color;
					color.r = x * y * 0.01;
					color.g = x * y * 0.01;
					color.b = x * y * 0.01;
					color.a = 1.0f;
					AddFilledRect(x * 100, y * 100, 100, 100, color);
				}
			}
		}

		void Renderer::Clear() const {
			GLCall(glClear(GL_COLOR_BUFFER_BIT));
		}

		void Renderer::Draw(VertexArray& vertexArray, IndexBuffer& indexBuffer, unsigned int shader) const {
			glm::vec3 scaledPosition = m_MainCamera.m_Position * m_MainCamera.m_Scale;
			glm::mat4 model = glm::translate(glm::mat4(1.0f), scaledPosition) * glm::scale(glm::mat4(1.0f), glm::vec3(m_MainCamera.m_Scale, m_MainCamera.m_Scale, m_MainCamera.m_Scale));
			glm::mat4 mvp = m_MainCamera.m_Projection * m_MainCamera.m_View * model;
			if (shader == 0) {
				m_ShaderDefault->Bind();
			}
			else if (shader == 1) {
				m_ShaderTexture->Bind();
			}
			m_ShaderDefault->SetUniformMat4f("u_MVP", mvp);
			vertexArray.Bind();
			indexBuffer.Bind();
			glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr);
		}

		void Renderer::Draw() {
			for (auto& shape : m_Shapes) {
				m_ShaderDefault->Bind();
				m_ShaderDefault->SetUniform4f("u_Color", shape->m_Color.r, shape->m_Color.g, shape->m_Color.b, shape->m_Color.a);
				Draw(*shape->m_VertexArray, *shape->m_IndexBuffer);
			}
		}

		void Renderer::AddRect(float x, float y, float width, float height, float thickness, MathNS::Color color) {

		}
		void Renderer::AddFilledRect(float x, float y, float width, float height, MathNS::Color color) {
			float vertices[] = {
				x, y,
				x+width, y,
				x+width, y+height,
				x, y+height
			};

			unsigned int indices[] = {
				0,1,2,
				2,3,0
			};

			VertexArray* vertexArray = new VertexArray();
			RenderNS::VertexBuffer vertexBuffer(vertices, 4 * 2 * sizeof(float));

			RenderNS::VertexBufferLayout layout;
			layout.Push<float>(2);
			vertexArray->AddBuffer(vertexBuffer, layout);

			IndexBuffer* indexBuffer = new IndexBuffer(indices, 6);

			vertexArray->Unbind();
			vertexBuffer.Unbind();
			indexBuffer->Unbind();

			Shape* shape = new Shape(MathNS::Vector3(), vertexArray, indexBuffer, color);

			m_Shapes.push_back(shape);

			std::cout << m_Shapes.size() << std::endl;
		}

		void Renderer::AddTexture(Texture2d& texture, float x, float y) {
			float vertices[] = {
			-50.0f, -50.0f, 0.0f, 0.0f,
			 50.0f, -50.0f, 1.0f, 0.0f,
			 50.0f,  50.0f, 1.0f, 1.0f,
			-50.0f,  50.0f, 0.0f, 1.0f
			};

			unsigned int indices[] = {
				0,1,2,
				2,3,0
			};
			

		}

		void Renderer::EnableBlend() const {
			GLCall(glEnable(GL_BLEND));
			GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
		}
	}
}