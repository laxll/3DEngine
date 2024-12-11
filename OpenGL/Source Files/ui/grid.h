#pragma once

#include "pch.h"
#include <shader/shader.h>

#include "render/VertexIndexBuffer.h"

namespace ui {

	class Grid {

	public:

		Grid();

		void Init();

		void render(Shader& shader);
		
		void destroy();

	private:

		unsigned int m_size;
		float m_spacing;
		glm::vec3 m_color;

		float m_dMin;
		float m_dMax;

	private:
		std::unique_ptr<render::VertexIndexBuffer> mVertexIndexBuffer = std::make_unique<render::VertexIndexBuffer>();
	};


}