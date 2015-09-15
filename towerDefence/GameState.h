#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <unordered_map>
#include <functional>
#include <memory>
#include <stack>
#include <vector>

class IState
{
public:
	virtual void processEvents() = 0;
	virtual void update(const sf::Time& delta) = 0;
	virtual void render() = 0;
};


struct Context
{
	Context(sf::RenderWindow& win) : m_window_ptr(&win){};
	sf::RenderWindow* m_window_ptr;

};

class StateManager
{
public:
	explicit StateManager(Context);
	~StateManager();

	using ptrState = std::unique_ptr<IState>;
	using stateCreateFun = std::function<ptrState(void)>;
	enum class ID {TITLE, MAINMENU,GAME, PAUSE};
	
	template <typename T>
	void registerState(ID id);

	void pushState(ID id);
	void popState();
	ptrState& getState();

	bool empty() { return stateStack.empty(); }

private:
	Context context;
	std::unordered_map<ID, stateCreateFun> factorMap;
	std::stack<ptrState> stateStack;
};


class MainMenuState : public IState
{
public:
	MainMenuState(StateManager&, Context);
	virtual void processEvents();
	virtual void update(const sf::Time& delta);
	virtual void render();

private:
	Context m_context;
	StateManager& m_sm;
};


class PauseState : public IState
{
public:
	PauseState(StateManager&, Context);
	virtual void processEvents();
	virtual void update(const sf::Time& delta);
	virtual void render();

private:
	Context m_context;
	StateManager& m_sm;

};


class GameState : public IState
{
public:
	GameState(StateManager&, Context);
	virtual void processEvents();
	virtual void update(const sf::Time& delta);
	virtual void render();

private:
	Context m_context;
	StateManager& m_sm;

};


template <typename T>
void StateManager::registerState(ID id)
{

	factorMap.insert({ id, [this](){ return std::make_unique<T>(*this, context); } });
}