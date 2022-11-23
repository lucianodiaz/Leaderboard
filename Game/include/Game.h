#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Leaderboard.h"

class Window;

class Game
{
public:
	//Non copyable or assignable
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	Game(int x=800,int y=600);

	virtual ~Game();
	//Run with fixed time steps
	void run(int frame_per_seconds = 30);

	void update(sf::Time deltaTime);

	void draw();

	void processEvents();
private:
	std::unique_ptr<Window> _window;

	sf::Text _txt;

	std::unique_ptr<Leaderboard> leaderboard;
};

