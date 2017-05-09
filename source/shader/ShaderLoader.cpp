#include "ShaderLoader.h"

namespace Shader {
	std::string GetSource(const std::string path) {
		// 1. Retrieve the vertex/fragment source code from filePath
		std::string shaderCode;
		std::ifstream shaderFile;
		// ensures ifstream objects can throw exceptions:
		shaderFile.exceptions(std::ifstream::badbit);
		try
		{
			// Open files
			shaderFile.open("../../media/shaders" + path);
			std::stringstream shaderStream;
			// Read file's buffer contents into streams
			shaderStream << shaderFile.rdbuf();
			// close file handlers
			shaderFile.close();
			// Convert stream into string
			shaderCode = shaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}
		return shaderCode;
	}
	GLuint CompileShader(const GLchar* shaderCode, GLenum type) {
		// 2. Compile shaders
		GLuint shader;
		GLint success;
		GLchar infoLog[512];
		// Vertex Shader
		shader = glCreateShader(type);
		glShaderSource(shader, 1, &shaderCode, nullptr);
		glCompileShader(shader);
		// Print compile errors if any
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::" << type << "::COMPILATION_FAILED\n";
			std::cout << infoLog << std::endl;
		}
		return shader;
	}
	GLuint CreateProgram(GLuint vertexShaderID, GLuint fragmentShaderID) {
		// Shader Program
		GLint success;
		GLchar infoLog[512];

		GLuint shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShaderID);
		glAttachShader(shaderProgram, fragmentShaderID);
		glLinkProgram(shaderProgram);
		// Print linking errors if any
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
		return shaderProgram;
	}
	GLuint LoadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile) {
		auto vertexCode = GetSource(vertexShaderFile);
		auto fragmentCode = GetSource(fragmentShaderFile);

		auto vertexShaderID = CompileShader(vertexCode.c_str(), GL_VERTEX_SHADER);
		auto fragmentShaderID = CompileShader(fragmentCode.c_str(), GL_FRAGMENT_SHADER);

		auto shaderProgramID = CreateProgram(vertexShaderID, fragmentShaderID);
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);

		return shaderProgramID;
	}

}