#pragma once
#include "maths/Math.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Texture2d.h"

namespace LabelixNS {
	namespace RenderNS {
		class Shape {
		public:
			MathNS::Vector3 m_Position;
			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;
			MathNS::Color m_Color;

			Shape(MathNS::Vector3 position, VertexArray* vertexArray, IndexBuffer* indexBuffer, MathNS::Color color, Texture2d* texture = nullptr);
			~Shape();

			void Draw();
		};
	}
}