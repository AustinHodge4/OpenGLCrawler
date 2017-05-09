#include "Sprite.h"
#include <iostream>
Sprite::Sprite(){}
Sprite::Sprite(const std::vector<GLfloat> &vertices,
			   const std::vector<GLfloat> &texCoords,
			   const std::vector<GLuint> &indicies) : m_eboCount(indicies.size())
{
	glGenVertexArrays(1, &m_vertexVAO);
	glBindVertexArray(m_vertexVAO);
	AddVBO(2, vertices);
	AddVBO(2, texCoords);
	AddEBO(indicies);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}
void Sprite::Bind() {
	glBindVertexArray(m_vertexVAO);
}
void Sprite::Unbind() {
	glBindVertexArray(0);
}
void Sprite::AddVBO(int diminsion, const std::vector<GLfloat> &vertices) {
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(m_vboCount, 2, GL_FLOAT, GL_FALSE, diminsion * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(m_vboCount++);
	/*glVertexAttribPointer(m_vboCount, 2, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(VertexData), (GLvoid*)offsetof(VertexData, texCoords));
	glEnableVertexAttribArray(m_vboCount++);*/
	m_vboBuffers.push_back(vbo);
}
void Sprite::AddEBO(const std::vector<GLuint> &indices) {
	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), indices.data(), GL_STATIC_DRAW);

	m_vboBuffers.push_back(ebo);
}

GLuint Sprite::GetEboCount() const
{
	return m_eboCount;
}

Sprite::~Sprite()
{
	glDeleteVertexArrays(1, &m_vertexVAO);
	glDeleteBuffers(m_vboBuffers.size(), m_vboBuffers.data());
}

