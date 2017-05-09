#include "SpriteShader.h"
namespace Shader {
	SpriteShader::SpriteShader() : ShaderProgram("/sprite/SpriteVertexShader.vs", "/sprite/SpriteFragmentShader.frag")
	{
	}
	void SpriteShader::SetUniformVariables() {
		GLuint shaderID = GetShaderID();
		glUniform1i(glGetUniformLocation(shaderID, "Sprite"), 0);
		glUniform2f(glGetUniformLocation(shaderID, "clip"), 0, 4);
		glUniform2f(glGetUniformLocation(shaderID, "rowCol"), 13, 21);
	}
	
}