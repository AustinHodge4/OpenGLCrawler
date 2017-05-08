#include "Playing.h"
#include "Sprite.h"
#include "Texture.h"
#include "ShaderManager.h"

namespace State {
	
	ShaderManager shaderManager;
	State::Playing::Playing(Application& application) : GameState(application),
					m_sprite({ -0.1f, -0.1f, 0.0f, 1.0f,
								0.1f, -0.1f, 1.0f, 1.0f,
								0.1f,  0.1f, 1.0f, 0.0f,
								-0.1f,  -0.1f, 0.0f, 1.0f, 
								-0.1f,  0.1f, 0.0f, 0.0f,
								0.1f,  0.1f, 1.0f, 0.0f })
	{

		shaderManager.InitializeShaders();
	}

	State::Playing::~Playing()
	{
		
	}

	void State::Playing::input()
	{
	}

	void State::Playing::update()
	{

	}

	void State::Playing::draw()
	{
		static Texture texture("../../media/textures/playerArrow.png");

		glActiveTexture(GL_TEXTURE0);
		texture.Bind();
		glUniform1i(glGetUniformLocation(shaderManager.m_pSprite.Program, "Sprite"), 0);
		glUniform2f(glGetUniformLocation(shaderManager.m_pSprite.Program, "clip"), 0, 4);
		glUniform2f(glGetUniformLocation(shaderManager.m_pSprite.Program, "rowCol"), 13, 21);

		shaderManager.m_pSprite.Use();
		m_sprite.Bind();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		m_sprite.Unbind();
		texture.Unbind();

	}
	
}