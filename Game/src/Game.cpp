#include "include/Configuration.h"
#include "include/Game.h"
#include "include/Window.h"

Game::Game(int x, int y) : _window(std::make_unique<Window>(x,y,"Leaderboard")),
							_world(x,y)
{
	_txt.setFont(Configuration::fonts.get(Configuration::Fonts::Leaderboard));
	_txt.setCharacterSize(80);
	_txt.setString("LEADERBOARD");
	_txt.setFillColor((sf::Color::Color(sf::Color(173, 216, 230, 255))));
	sf::FloatRect size = _txt.getGlobalBounds();
	_txt.setOrigin(size.width / 2, size.height / 2);
	_txt.setPosition(x / 2,50);


	leaderboard = std::make_unique<Leaderboard>(_world);
}

Game::~Game()
{
	std::cout << "OnDestroy Game" << std::endl;
}

void Game::run(int frame_per_seconds)
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	sf::Time TimerPerFrame = sf::seconds(1.f / frame_per_seconds);

	while (_window->isOpen())
	{
		processEvents();
		bool repaint = false;
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimerPerFrame)
		{
			timeSinceLastUpdate -= TimerPerFrame;
			repaint = true;
			update(TimerPerFrame);
		}

		if (repaint)draw();
	}
}

void Game::update(sf::Time deltaTime)
{
	
}

void Game::draw()
{
	_window->clear();
	_window->draw(_txt);
	_window->draw(*leaderboard);
	_window->display();
}

void Game::processEvents()
{
	sf::Event evt;
	while (_window->pollEvent(evt))
	{
		if (evt.type == sf::Event::Closed)
			_window->close();
		else if (evt.type == sf::Event::KeyPressed)
		{
			if (evt.key.code == sf::Keyboard::Escape)
			{
				_window->close();
			}
		}
	}
}
