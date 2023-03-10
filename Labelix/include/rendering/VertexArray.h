#pragma once
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace LabelixNS {
    namespace RenderNS {
		class VertexArray {
		private:
			unsigned int m_RendererId;
		public:
			VertexArray();
			~VertexArray();

			void AddBuffer(VertexBuffer& vertexBuffer, VertexBufferLayout& layout);

			void Bind() const;
			void Unbind() const;
		};
    }
}