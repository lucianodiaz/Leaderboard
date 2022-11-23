#include "include/Leaderboard.h"
#include "include/Configuration.h"

Leaderboard::Leaderboard()
{
	HSM.loadScore();
	loadScores();
}

Leaderboard::~Leaderboard()
{
	HSM.saveScore();
}

void Leaderboard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto t : _scoresTxt)
	{
		target.draw(t);
	}
}

void Leaderboard::loadScores()
{
	for (auto&& s : HSM.getScores())
	{
		sf::Text txt;
		txt.setFont(Configuration::fonts.get(Configuration::Fonts::Desc));
		txt.setFillColor(sf::Color::White);
		txt.setCharacterSize(32);
		txt.setString(string(std::to_string(_scoresTxt.size()+1)+". " + s._name + "    " + std::to_string(s._score)));
		
		sf::FloatRect size = txt.getGlobalBounds();
		txt.setOrigin(size.width / 2, size.height / 2);

		txt.setPosition(400,50*_scoresTxt.size()+150);
		_scoresTxt.emplace_back(txt);
	}
}
