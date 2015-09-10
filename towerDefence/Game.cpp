#include "Game.h"
#include <SFML\Window\Event.hpp>


Game::Game() : m_window(sf::VideoMode(1024,768), "Tower Defence 0.1")
{



}

void Game::processEvents()
{
	sf::Event evt;

	while (m_window.pollEvent(evt))
	{
		if (evt.type == sf::Event::Closed ||
		   (evt.type == sf::Event::KeyPressed && evt.key.code == sf::Keyboard::Escape))
				m_window.close();

	}
}

void Game::update(const sf::Time& delta)
{
//later

}

void Game::render()
{
	m_window.clear();
	m_window.display();
}


void Game::run()
{
	sf::Clock clk;
	sf::Time timeElapsed = sf::Time::Zero;
	sf::Time secPerFrame = sf::seconds(1.f/60); //60 FPS
	bool redraw = false;

	while (m_window.isOpen())
	{
		redraw = false;
		processEvents();

		timeElapsed += clk.restart();

		while (timeElapsed >= secPerFrame)
		{
			redraw = true;
			update(secPerFrame); //fixed fps woot
			timeElapsed -= secPerFrame;
		}

		if (redraw)
			render();
	}
}