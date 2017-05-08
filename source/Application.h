#pragma once
#include <memory>
#include<stack>

#include "GameState.h"

class Application
{
public:
	Application();
	~Application();

	void runMainGameLoop();

	void pushState(std::unique_ptr<State::GameState> state);
	void popState();
	bool *keys[1024];

private:
	std::stack<std::unique_ptr<State::GameState>> m_states;
};

