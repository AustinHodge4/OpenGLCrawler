#pragma once
#include "GameState.h"
#include "Sprite.h"

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
	};
}

