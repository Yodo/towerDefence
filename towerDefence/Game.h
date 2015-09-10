#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
public: //CTORS
	Game();

	Game(const Game&) = delete;
	Game& operator =(const Game&) = delete;

public: //Interface
	void run();

private: //Functions

	void processEvents();
	void update(const sf::Time& delta);
	void render();


private: //Members

	sf::RenderWindow m_window;

};