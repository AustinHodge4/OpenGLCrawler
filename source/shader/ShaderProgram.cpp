#include "ShaderProgram.h"
#include "ShaderLoader.h"

namespace Shader {
	ShaderProgram::ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath)
	: m_shaderProgram(LoadShader(vertexPath, fragmentPath))
	{
		
	}

	void ShaderProgram::Bind()
	{
		glUseProgram(m_shaderProgram);
	}
	void ShaderProgram::UnBind() {
		glUseProgram(0);
	}
	ShaderProgram::~ShaderProgram() {
		glDeleteProgram(m_shaderProgram);
	}
	GLuint ShaderProgram::GetShaderID() const {
		return m_shaderProgram;
	}
}