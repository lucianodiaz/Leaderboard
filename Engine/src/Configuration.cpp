#include "include/Configuration.h"

ResourceManager<sf::Font, int> Configuration::fonts;

void Configuration::initialize()
{
	initFonts();
	//initTextures();
}

void Configuration::initTextures()
{
}

void Configuration::initFonts()
{
	fonts.load(Fonts::Leaderboard, "assets/fonts/Arcade.ttf");
	fonts.load(Fonts::Desc, "assets/fonts/league.ttf");
}
