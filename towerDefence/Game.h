#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "GameState.h"

class Game
{
public: //CTORS
	Game();
	~Game();

	Game(const Game&) = delete;
	Game& operator =(const Game&) = delete;

public: //Interface
	void run();

private: //Functions

	// Init functions
	void init_states();


private: //Members

	sf::RenderWindow m_window;
	StateManager m_StateManager;

};