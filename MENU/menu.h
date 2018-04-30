#pragma once
#include <SFML\Graphics.hpp>
#include "player.h"
#include <string>

class player;

class menu
{
private:
	sf::Text startbutton_text;
	sf::Text playerscore;
	sf::Text playeriframes;
	sf::Font font;
public:
	menu() {
		font.loadFromFile("tnr.ttf");

		startbutton_text.setFont(font);
		startbutton_text.setString("Paused");
		startbutton_text.setCharacterSize(56);
		startbutton_text.setFillColor(sf::Color::Black);
		startbutton_text.setPosition(((1024.0f - 200.0f )/ 2.0f), (412.0f / 2));
		
		playerscore.setFont(font);
		playerscore.setString("Placeholder");
		playerscore.setCharacterSize(30);
		playerscore.setFillColor(sf::Color::Black);
		playerscore.setPosition(((1024.0f - 70.0f) / 2), 0.0f); 

		playeriframes.setFont(font);
		playeriframes.setString("Placeholder");
		playeriframes.setCharacterSize(30);
		playeriframes.setFillColor(sf::Color::Black);
		playeriframes.setPosition(0.0f, 0.0f);
	}
	void drawpause(sf::RenderWindow &window);
	void drawscore(sf::RenderWindow &window, player player);
	void drawiframe(sf::RenderWindow &window, player player);

};