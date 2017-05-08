#include "ShaderManager.h"
ShaderManager::ShaderManager(){}
void ShaderManager::InitializeShaders()
{
	m_pDefault = Shader("../../media/shaders/default/DefaultVertexShader.vs", "../../media/shaders/default/DefaultFragmentShader.frag");
	m_pLighting = Shader("../../media/shaders/lighting/LightVertexShader.vs", "../../media/shaders/lighting/LightFragmentShader.frag");
	m_pLamp = Shader("../../media/shaders/lighting/LightVertexShader.vs", "../../media/shaders/lighting/LampFragmentShader.frag");
	m_pToon = Shader("../../media/shaders/toon/ToonVertexShader.vs", "../../media/shaders/toon/ToonFragmentShader.frag");
	m_pHatch = Shader("../../media/shaders/hatch/HatchVertexShader.vs", "../../media/shaders/hatch/HatchFragmentShader.frag");
	m_pSprite = Shader("../../media/shaders/sprite/SpriteVertexShader.vs", "../../media/shaders/sprite/SpriteFragmentShader.frag");
}

ShaderManager::~ShaderManager()
{
}
