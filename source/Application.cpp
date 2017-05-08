#include "Application.h"
#include "Display.h"
#include "Playing.h"

// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

Application::Application()
{
	pushState(std::make_unique<State::Playing>(*this));
}


Application::~Application()
{
}

void Application::runMainGameLoop()
{
	while (!Display::shouldClose())
	{
		// Set frame time
		//GLdouble currentFrame = glfwGetTime();
		//deltaTime = currentFrame - lastFrame;
		//lastFrame = currentFrame;
		Display::clear();

		m_states.top()->input();
		m_states.top()->update();
		m_states.top()->draw();

		Display::update();
	}
}

void Application::pushState(std::unique_ptr<State::GameState> state)
{
	m_states.push(std::move(state));
}

void Application::popState()
{
	m_states.pop();
}
