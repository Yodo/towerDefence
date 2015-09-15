#include "GameState.h"
#include "Logger.h"
#include <SFML\Window\Event.hpp>


StateManager::StateManager(Context c) : context(c)
{

}

StateManager::~StateManager()
{
	while (!stateStack.empty())
		stateStack.pop();
}


void StateManager::pushState(ID id)
{
	try{
		stateStack.push(std::move(factorMap.at(id)()));
	}
	catch (std::out_of_range& ex)
	{
		//No state with ID = id in map
	}
}

void StateManager::popState(){
	if (!stateStack.empty())
		stateStack.pop();

}

StateManager::ptrState& StateManager::getState(){
		return stateStack.top();
}

///////////////////
MainMenuState::MainMenuState(StateManager& sm, Context c) : m_context(c), m_sm(sm)
{
	logger::debug() << "Main menu loaded, window = " << m_context.m_window_ptr->getSize().x << ", " << m_context.m_window_ptr->getSize().y;
}

void MainMenuState::update(const sf::Time& delta)
{

}

void MainMenuState::processEvents()
{
	sf::Event evt;

	while (m_context.m_window_ptr->pollEvent(evt))
	{
		if (evt.type == sf::Event::Closed ||
			(evt.type == sf::Event::KeyPressed && evt.key.code == sf::Keyboard::Escape))
			m_context.m_window_ptr->close();

	}
}

void MainMenuState::render()
{
	m_context.m_window_ptr->clear();
	m_context.m_window_ptr->display();
}

//////////////////
PauseState::PauseState(StateManager& sm, Context c) : m_context(c), m_sm(sm)
{

}

void PauseState::update(const sf::Time& delta)
{

}

void PauseState::processEvents()
{

}

void PauseState::render()
{

}
/////////////////
GameState::GameState(StateManager& sm, Context c) : m_context(c), m_sm(sm)
{

}

void GameState::update(const sf::Time& delta)
{

}

void GameState::processEvents()
{

}

void GameState::render()
{

}