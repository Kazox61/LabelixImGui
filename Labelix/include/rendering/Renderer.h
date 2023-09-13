#pragma once

#include <GL/glew.h>
#include "maths/Math.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "CameraOrthographic.h"
#include "Shader.h"
#include "Shape.h"
#include "FrameBuffer.h"

#include <vector>


namespace LabelixNS {
	namespace RenderNS {
		class Renderer {
		public:
			Renderer();
			~Renderer();

			static Renderer* GetInstance() { return s_Instance; }
			CameraOrthographic m_MainCamera;

			std::vector<Shape*> m_Shapes;
			FrameBuffer* m_FrameBuffer;

			void Init();
			void Clear() const;

			void Draw();
			void Draw(VertexArray& vertexArray, IndexBuffer& indexBuffer, unsigned int shader = 0) const;
			void AddRect(float x, float y, float width, float height, float thickness, MathNS::Color color);
			void AddFilledRect(float x, float y, float width, float height, MathNS::Color color);
			void DrawLine(MathNS::Vector2 from, MathNS::Vector2 to, MathNS::Vector4 color) const;
		private:
			static Renderer* s_Instance;

			Shader* m_ShaderDefault;
			Shader* m_ShaderTexture;

			void EnableBlend() const;
		};
	}
}