#include <GL\glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Shader {
	GLuint LoadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
}