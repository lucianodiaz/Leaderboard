#pragma once
#include <SFML/Graphics.hpp>
#include "include/ResourceManager.h"
class Configuration
{
public:
	Configuration() = delete;
	Configuration(const Configuration&) = delete;
	Configuration& operator=(const Configuration&) = delete;
	
	enum Fonts : int {Leaderboard,Desc};
	static ResourceManager<sf::Font> fonts;

	static void initialize();

private:
	static void initTextures();
	static void initFonts();
};

