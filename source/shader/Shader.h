#include <GL\glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
	Shader();
	Shader(const GLchar * vertexPath, const GLchar * fragmentPath);
	void Use();
public:
	GLuint Program;
};