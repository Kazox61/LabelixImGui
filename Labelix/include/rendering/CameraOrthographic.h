#pragma once
#include "maths/Math.h"

namespace LabelixNS {
	namespace RenderNS {
		class CameraOrthographic{
		public:
			glm::mat4 m_Projection;
			glm::mat4 m_View;
			float m_Scale;
			glm::vec3 m_Position;

			CameraOrthographic();
		};
	}
}