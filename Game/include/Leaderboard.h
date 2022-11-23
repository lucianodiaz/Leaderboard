#pragma once
#include<SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "ScoreManager.h"
#include <iostream>

using std::vector;
using std::string;
class Leaderboard : public sf::Drawable
{
public:
	//non copyable
	Leaderboard(const Leaderboard&) = delete;
	Leaderboard& operator=(const Leaderboard&) = delete;

	Leaderboard();

	virtual ~Leaderboard();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
private:

	void loadScores();

	ScoreManager<unsigned int> HSM;

	vector<sf::Text> _scoresTxt;
};

