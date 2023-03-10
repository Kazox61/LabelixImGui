#include "rendering/VertexArray.h"

#include "rendering/RenderLayer.h"


namespace LabelixNS {
    namespace RenderNS {
		VertexArray::VertexArray() {
			GLCall(glGenVertexArrays(1, &m_RendererId));
		}

		VertexArray::~VertexArray() {
			GLCall(glDeleteVertexArrays(1, &m_RendererId));
		}

		void VertexArray::AddBuffer(VertexBuffer& vertexBuffer, VertexBufferLayout& layout) {
			Bind();
			vertexBuffer.Bind();
			const auto& elements = layout.GetElements();
			unsigned int offset = 0;
			for (unsigned int i = 0; i < elements.size(); i++) {
				const auto& element = elements[i];
				GLCall(glEnableVertexAttribArray(i));
				GLCall(glVertexAttribPointer(i, element.count, element.type,
					element.normalized, layout.GetStride(), (const void*)offset));
				offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
			}
		}

		void VertexArray::Bind() const {
			GLCall(glBindVertexArray(m_RendererId));
		}

		void VertexArray::Unbind() const {
			GLCall(glBindVertexArray(0));
		}
    }
}