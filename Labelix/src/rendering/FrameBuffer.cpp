#include "rendering/FrameBuffer.h"

#include <iostream>

namespace LabelixNS {
	namespace RenderNS {
		FrameBuffer::FrameBuffer() 
			: m_FrameBufferId(0), m_Width(600), m_Height(400)
		{
			GLCall(glGenTextures(1, &m_TextureId));
			GLCall(glBindTexture(GL_TEXTURE_2D, m_TextureId));
			GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr));
			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

			GLCall(glGenFramebuffers(1, &m_FrameBufferId));
			GLCall(glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBufferId));
			GLCall(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_FrameBufferId, 0));
			GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
			if (status != GL_FRAMEBUFFER_COMPLETE) {
				std::cout << "FrameBuffer not complete!" << std::endl;
			}
		}

		FrameBuffer::~FrameBuffer() {
			GLCall(glDeleteFramebuffers(1, &m_FrameBufferId););
		}

		void FrameBuffer::Activate() {
			GLCall(glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBufferId));
			GLCall(glViewport(0, 0, m_Width, m_Height));
			GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
			GLCall(glClear(GL_COLOR_BUFFER_BIT));

		}

		void FrameBuffer::Deactivate() {
			Unbind();
			GLCall(glViewport(0, 0, m_Width, m_Height));
			GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
			GLCall(glClear(GL_COLOR_BUFFER_BIT));
		}

		void FrameBuffer::Unbind() {
			GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));
		}

		void FrameBuffer::UpdateSize(unsigned int width, unsigned int height) {
			m_Width = width;
			m_Height = height;
			glBindTexture(GL_TEXTURE_2D, m_TextureId);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
		}
	}
}