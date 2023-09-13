#pragma once

#include "RenderLayer.h"

namespace LabelixNS {
	namespace RenderNS {
		class FrameBuffer {
		public:
			unsigned int m_Width, m_Height;
			unsigned int m_FrameBufferId;
			unsigned int m_TextureId;

			FrameBuffer();
			~FrameBuffer();

			void Activate();
			void Deactivate();
			void Unbind();
			void UpdateSize(unsigned int width, unsigned int height);
		};
	}
}
