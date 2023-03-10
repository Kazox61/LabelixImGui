#include "rendering/IndexBuffer.h"

#include "rendering/RenderLayer.h"

namespace LabelixNS {
	namespace RenderNS {
        IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
            : m_Count(count)
        {
            GLCall(glGenBuffers(1, &m_RendererId));
            GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId));
            GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
        }

        IndexBuffer::~IndexBuffer() {
            GLCall(glDeleteBuffers(1, &m_RendererId));
        }

        void IndexBuffer::Bind() const {
            GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId));
        }

        void IndexBuffer::Unbind() const {
            GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
        }
	}
}