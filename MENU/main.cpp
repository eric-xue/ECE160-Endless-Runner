#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "player.h"
#include "ground.h"
#include "Health.h"
#include "enemy.h"
//=============================
#include "menu.h"
//=============================

int main()
{
	//=============================
	menu menu;
	//=============================
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
	bool start = true;
	float temp = 0;
	int starter_enemy = 1;
	

	while (window.isOpen())
	{
		groundcollide = (player.playerbox).getGlobalBounds().intersects((ground.groundbox).getGlobalBounds());
		enemycollide = (player.playerbox).getGlobalBounds().intersects((enemy).getGlobalBounds());
		sf::Event event;
		window.pollEvent(event);
		bool hit = false;
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
		float enemyspawned = 0.0f;
		if (player.health == 0)
		{
			pause = true;
			player.resetpoints();
			player.player_reset(ground);
			temp = 0;
			for (int i = 0; i < 8; i++)
			{
					enemyarray[i]->resetenemypos();	
			}
			bool start = true;
			starter_enemy = 0;
			
		}

		dt = clock.restart().asSeconds();
		if (dt > (1.0f / 20.0f))
		{
			dt = 1.0f / 20.0f;
		}

		//UPDATE
		if (!pause)
		{
			if (start)
			{
				enemyarray[starter_enemy];

			}
			for (int i = 0; i < 8; i++)
			{
				enemyarray[i]->enemymove();
			}

			player.player_update(dt, groundcollide, ground);
			for (int i = 0; i < 8; i++)
			{
				enemyarray[i]->enemypoint(player);
			}

			//bool hit = false;
			for (int i = 0; i < 8; i++)
			{
				if (enemyarray[i]->enemyhit(player))
				{
					hit = true;
					//fix this so that hit does not stay true
				}
				player.minushealthPSEUDOCODE(hit, dt);
				if(hit)
					break;
			}
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
		//=============================
		menu.drawscore(window, player);
		if (pause)
		{
			menu.drawpause(window);
		}
		if (player.is_hit())
		{
			menu.drawiframe(window, player);
		}
		//=============================
		for (int i = 0; i < 8; i++)
		{
			enemyarray[i]->drawenemy(window);
		}
		enemyarray[1]->drawenemy(window);
		window.display();
	}
	return 0;
}