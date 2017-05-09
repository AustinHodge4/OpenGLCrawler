#include "ShaderProgram.h"
namespace Shader {
	class SpriteShader : public ShaderProgram {
	public:
		SpriteShader();
		void SetUniformVariables() override;
	};
}