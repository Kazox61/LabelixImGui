#include "rendering/CameraOrthographic.h"

#include <iostream>

namespace LabelixNS {
	namespace RenderNS {
		CameraOrthographic::CameraOrthographic() 
			: m_Scale(1),
			m_Projection(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
			m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
			m_Position(0,0,0)
		{
			std::cout << "Camera instantiated!" << std::endl;
		}
	}
}