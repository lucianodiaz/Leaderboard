#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "ScoreManager.h"



using std::vector;
using std::string;

class World;

class Leaderboard : public sf::Drawable
{
public:
	//non copyable
	Leaderboard(const Leaderboard&) = delete;
	Leaderboard& operator=(const Leaderboard&) = delete;

	Leaderboard(World& world);

	virtual ~Leaderboard();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
private:

	void loadScores();

	ScoreManager<unsigned int> HSM;

	vector<sf::Text> _scoresTxt;
	
	World& _world;
};

