#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "player.h"
#include "ground.h"
#define playerwidth 100.0f
#define playerheight 100.0f

int main()
{
	//player wowzer;
	player player;
	ground ground;
	sf::RenderWindow window(sf::VideoMode(1024, 512), "SFML TUTORIAL", sf::Style::Titlebar | sf::Style::Default);
	window.setFramerateLimit(45);
	bool groundcollide;
	sf::Clock clock;
	window.setFramerateLimit(60);
	
	float dt;

	while (window.isOpen())
	{
		sf::Event evnt;
		groundcollide = (player.playerbox).getGlobalBounds().intersects((ground.groundbox).getGlobalBounds());
		dt = clock.restart().asSeconds();

		window.clear(sf::Color::White);
		window.draw(player.playerbox);
		window.draw(ground.groundbox);
		window.display();


		//std::cout << "beginning dy: " << player.player_dy << std::endl;
		player.player_update(dt, groundcollide);
	}
	return 0;
}