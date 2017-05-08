#include "Sprite.h"

Sprite::Sprite(const std::vector<GLfloat> &vertices)
{
	glGenVertexArrays(1, &m_vertexVAO);
	glBindVertexArray(m_vertexVAO);
	AddVBO(2, vertices);
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

	glVertexAttribPointer(m_vboCount, diminsion, GL_FLOAT, GL_FALSE, 4 * sizeof(vertices[0]), (GLvoid*)0);
	glEnableVertexAttribArray(m_vboCount++);

	glVertexAttribPointer(m_vboCount, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(vertices[0]), (GLvoid*)(2 * sizeof(vertices[0])));
	glEnableVertexAttribArray(m_vboCount++);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	m_vertexVBO.push_back(vbo);
}
Sprite::~Sprite()
{
	glDeleteVertexArrays(1, &m_vertexVAO);
	glDeleteBuffers(m_vertexVBO.size(), m_vertexVBO.data());
}

