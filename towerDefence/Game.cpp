#include "Game.h"
#include "Logger.h"
#include <SFML\Window\Event.hpp>
#include <cassert>


Game::Game() : m_window(sf::VideoMode(1024, 768), "Tower Defence 0.1"), m_StateManager(Context(m_window))
{
	init_states();
	m_StateManager.pushState(StateManager::ID::MAINMENU);
}

Game::~Game()
{

}


void Game::init_states()
{
	m_StateManager.registerState<MainMenuState>(StateManager::ID::MAINMENU);
	m_StateManager.registerState<PauseState>(StateManager::ID::PAUSE);
	m_StateManager.registerState<GameState>(StateManager::ID::GAME);
}

void Game::run()
{
	assert(!m_StateManager.empty());

	logger::debug() << "Run main loop";

	sf::Clock clk;
	sf::Time timeElapsed = sf::Time::Zero;
	sf::Time secPerFrame = sf::seconds(1.f/60); //60 FPS
	bool redraw = false;

	while (m_window.isOpen())
	{
		redraw = false;
		m_StateManager.getState()->processEvents();

		timeElapsed += clk.restart();

		while (timeElapsed >= secPerFrame)
		{
			redraw = true;
			m_StateManager.getState()->update(secPerFrame); //fixed fps woot
			timeElapsed -= secPerFrame;
		}

		if (redraw)
			m_StateManager.getState()->render();
	}
}