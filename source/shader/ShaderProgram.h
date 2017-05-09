#include <GL\glew.h>
#include <string>
namespace Shader {
	class ShaderProgram {
	public:
		ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);
		void Bind();
		void UnBind();
		~ShaderProgram();
	protected:
		virtual void SetUniformVariables() = 0;
		GLuint GetShaderID() const;
	private:
		GLuint m_shaderProgram;
	};
}