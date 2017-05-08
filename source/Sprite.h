#pragma once
// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

#include <vector>

class Sprite
{
public:
	Sprite(const std::vector<GLfloat> &vertices);
	void Bind();
	void Unbind();
	void AddVBO(int dimension, const std::vector<GLfloat> &vertices);
	~Sprite();
private:
	std::vector<GLuint> m_vertexVBO;
	GLuint m_vertexVAO;
	GLuint m_vboCount;

};

