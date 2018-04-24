#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "player.h"
#include "ground.h"

int main()
{
	player player;
	ground ground;
	sf::RenderWindow window(sf::VideoMode(1024, 512), "SFML TUTORIAL", sf::Style::Titlebar | sf::Style::Default);
	window.setFramerateLimit(60);
	bool groundcollide;
	sf::Clock clock;
	float dt;

	//PSEUDOENEMYCODE TEST
	sf::RectangleShape enemy(sf::Vector2f(100.0f, 100.0f));
	enemy.setFillColor(sf::Color::Black);
	enemy.setPosition(512.0f, 512.0f/2);


	while (window.isOpen())
	{
		groundcollide = (player.playerbox).getGlobalBounds().intersects((ground.groundbox).getGlobalBounds());
		dt = clock.restart().asSeconds();
		window.clear(sf::Color::White);
		window.draw(player.playerbox);
		window.draw(ground.groundbox);
		window.draw(enemy);
		window.display();
		//std::cout << "beginning dy: " << player.player_dy << std::endl;
		player.player_update(dt, groundcollide);
		player.minushealthPSEUDOCODE(enemy, dt);
	}
	return 0;
}