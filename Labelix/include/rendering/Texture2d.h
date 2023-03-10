#pragma once
#include <string>
#include "VertexArray.h"
#include "IndexBuffer.h"

namespace LabelixNS {
	namespace RenderNS {
		class Texture2d {
		private:
			unsigned int m_RendererId;
			std::string m_FilePath;
			unsigned char* m_LocalBuffer;
			int m_Width, m_Height, m_BPP;

			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;
			void Create();

		public:
			Texture2d(const std::string& path);
			~Texture2d();

			void Bind(unsigned int slot = 0) const;
			void Unbind() const;
			void Render() const;

			inline int GetWidth() const { return m_Width; }
			inline int GetHeight() const { return m_Height; }
		};
	}
}