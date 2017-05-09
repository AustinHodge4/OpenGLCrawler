#pragma once
#include <GL/glew.h>
#include "stb\stb_image.h"
namespace Textures {
	class Texture
	{
	public:
		Texture();
		void Load(const GLchar* paht);
		void Bind();
		void Unbind();
		~Texture();
	private:
		GLuint m_Texture;

	};
}

