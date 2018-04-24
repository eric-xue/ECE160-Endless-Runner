#pragma once
#include <SFML\Graphics.hpp>

class ground {
public:
	sf::RectangleShape groundbox;
public:
	ground() {
		groundbox.setSize(sf::Vector2f(1024.0f, 150.0f));
		groundbox.setOrigin(512.0f, 25.0f);
		groundbox.setFillColor(sf::Color::Black);
		groundbox.setPosition(512.0f, 512.0f);
	}

};