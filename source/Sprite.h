#pragma once
// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

#include <vector>
#include "VertexData.h"

class Sprite
{
public:
	Sprite();
	Sprite(const std::vector<GLfloat> &vertices,
		   const std::vector<GLfloat> &texCoords,
		   const std::vector<GLuint> &indicies);
	void Bind();
	void Unbind();
	void AddVBO(int dimension, const std::vector<GLfloat> &vertices);
	void AddEBO(const std::vector<GLuint> &indices);

	GLuint GetEboCount() const;
	~Sprite();
private:
	std::vector<GLuint> m_vboBuffers;
	GLuint m_vertexVAO;
	GLuint m_vboCount;
	GLuint m_eboCount;

};

