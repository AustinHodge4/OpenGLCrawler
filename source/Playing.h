#pragma once
#include "GameState.h"
#include "Sprite.h"
#include "Texture.h"
#include "shader\SpriteShader.h"

namespace State {
	class Playing : public GameState
	{
	public:
		Playing(Application& application);
		~Playing();

		void input() override;
		void update() override;
		void draw() override;
	private:
		Sprite m_sprite;
		Shader::SpriteShader m_spriteShader;
		Textures::Texture m_spriteTexture;
		// Engine Time
		GLdouble deltaTime = 0.0;
		GLdouble lastFrame = 0.0;
	};
}

