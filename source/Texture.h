#pragma once
#include <GL/glew.h>
#include <SOIL.h>

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

