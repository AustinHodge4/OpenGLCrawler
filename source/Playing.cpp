#include "Playing.h"
#include "Sprite.h"
#include "Texture.h"

namespace State {
	std::vector<GLfloat> vertices{
		-0.1f, -0.1f,
		0.1f, -0.1f,
		0.1f, 0.1f,
		-0.1f, 0.1f,
	};
	std::vector<GLfloat> texCoords{
		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
	};
	std::vector<GLuint> indices{
		0, 1, 3,
		1, 2, 3
	};
	State::Playing::Playing(Application& application) : GameState(application), m_sprite(vertices, texCoords, indices)
	{
		m_spriteTexture.Load("../../media/textures/playerArrow.png");
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
		deltaTime = glfwGetTime() - lastFrame;
		lastFrame = deltaTime;

		m_spriteShader.Bind();
		m_sprite.Bind();
		m_spriteTexture.Bind();
		m_spriteShader.SetUniformVariables();

		glDrawElements(GL_TRIANGLES, m_sprite.GetEboCount(), GL_UNSIGNED_INT, nullptr);

		m_spriteTexture.Unbind();
		m_sprite.Unbind();
		m_spriteShader.UnBind();
		
	}
	
}