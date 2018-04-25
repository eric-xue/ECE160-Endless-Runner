#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "player.h"
#include "ground.h"
#include "Health.h"
#include "enemy.h"

int main()
{
	ground ground;
	player player;
	enemy enemy1, enemy2, enemy3, enemy4, enemy5, enemy6;
	enemy *enemyarray[10];
	for (int i = 0; i < 8; i++)
	{
		enemyarray[i] = new enemy;
	}
	//ground ground;
	health health;
	sf::RenderWindow window(sf::VideoMode(1024, 512), "Final Project", sf::Style::Titlebar | sf::Style::Default);
	window.setFramerateLimit(50);
	bool groundcollide;
	sf::Clock clock;
	float dt;
	//PSEUDOENEMYCODE TEST
	sf::RectangleShape enemy(sf::Vector2f(100.0f, 100.0f));
	bool enemycollide = false;
	enemy.setFillColor(sf::Color::Black);
	enemy.setPosition(512.0f, 512.0f/2);
	bool pause = true;
	float temp = 0;
	

	while (window.isOpen())
	{
		groundcollide = (player.playerbox).getGlobalBounds().intersects((ground.groundbox).getGlobalBounds());
		enemycollide = (player.playerbox).getGlobalBounds().intersects((enemy).getGlobalBounds());
		sf::Event event;
		window.pollEvent(event);
		//GAMESTATE PAUSE
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
		{
			pause = !pause;
			switch (pause)
			{
			case true:
				std::cout << "Paused" << std::endl;
				break;
			case false:
				std::cout << "Unpaused" << std::endl;
				break;
			}	
		}
		//GAMESTATE RESET
		if (player.health == 0)
		{
			pause = true;
			player.player_reset(ground);
			temp = 0;
			for (int i = 0; i < 8; i++)
			{
				enemyarray[i]->resetenemypos();
			}
			enemy1.resetenemypos();
			enemy2.resetenemypos();
			enemy3.resetenemypos();
		}

		dt = clock.restart().asSeconds();
		if (dt > (1.0f / 20.0f))
		{
			dt = 1.0f / 20.0f;
		}

		//UPDATE
		if (!pause)
		{
			temp += dt;
			for (int i = 0; i < 8; i++)
			{
				enemyarray[i]->enemymove();

			}
			if(temp > 120*dt)
				enemy2.enemymove();
			if(temp > 240*dt)
				enemy3.enemymove();
			player.player_update(dt, groundcollide, ground);
			for (int i = 0; i < 8; i++)
			{
				enemyarray[i]->enemypoint(player);
			}
			/*enemy1.enemypoint(player);
			enemy2.enemypoint(player);
			enemy3.enemypoint(player);*/
			//bool hit = enemy1.enemyhit(player) || enemy2.enemyhit(player) || enemy3.enemyhit(player);
			bool hit;
			for (int i = 0; i < 8; i++)
			{
				if (enemyarray[i]->enemyhit(player))
				{
					hit = true;
					//fix this so that hit does not stay true
				}
				break;
			}
			player.minushealthPSEUDOCODE(hit, dt);
			health.updatehp(player);
			for (int i = 0; i < 8; i++)
			{
				enemyarray[i]->enemycheckbounds();
			}
			/*enemy1.enemycheckbounds();
			enemy2.enemycheckbounds();
			enemy3.enemycheckbounds();*/
		}

		//DRAW
		window.clear(sf::Color::White);
		player.drawplayer(window);
		health.drawhealth(window);
		ground.drawground(window);
		for (int i = 0; i < 8; i++)
		{
			enemyarray[i]->drawenemy(window);
		}
		enemyarray[1]->drawenemy(window);
		window.display();
	}
	return 0;
}