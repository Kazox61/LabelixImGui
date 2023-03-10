#include "rendering/Shape.h"

#include <iostream>

namespace LabelixNS {
	namespace RenderNS {
		Shape::Shape(MathNS::Vector3 position, VertexArray* vertexArray, IndexBuffer* indexBuffer, MathNS::Color color, Texture2d* texture)
			: m_Position(position), m_VertexArray(vertexArray), m_IndexBuffer(indexBuffer), m_Color(color)
		{

			std::cout << "Shape Created!" << std::endl;
		}

		Shape::~Shape() {
			std::cout << "Shape Destructed!" << std::endl;
		}

		void Shape::Draw() {

		}
	}
}