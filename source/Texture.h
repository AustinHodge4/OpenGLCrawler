#pragma once
#include <GL/glew.h>
#include "stb\stb_image.h"

class Texture
{
public:
	Texture();
	Texture(const GLchar* path);
	void Bind();
	void Unbind();
	~Texture();
private:
	GLuint m_Texture;

};

