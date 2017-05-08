#pragma once
#include "shader\Shader.h"
#include <vector>

class ShaderManager {
public:
	ShaderManager();
	~ShaderManager();

	void InitializeShaders();
public:
	Shader m_pDefault;
	Shader m_pLighting;
	Shader m_pLamp;
	Shader m_pToon;
	Shader m_pHatch;
	Shader m_pSprite;
};