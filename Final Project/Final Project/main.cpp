#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "player.h"
#include "ground.h"
#include "Health.h"
#include "enemy.h"
#define ENEMYCOUNT 4
#include "menu.h"

int main()
{

	menu menu;
	ground ground;
	player player(25, 25);
	enemy *enemyarray[10];
	for (int i = 0; i < ENEMYCOUNT	; i++)
	{
		float speed = std::rand() % 20;
		enemyarray[i] = new enemy(speed);
	}
	health health;
	sf::RenderWindow window(sf::VideoMode(1024, 512), "Final Project", sf::Style::Titlebar | sf::Style::Default);
	window.setFramerateLimit(50);
	bool groundcollide;
	sf::Clock clock;
	float dt;
	bool pause = true;
	bool start = true;
	float temp = 0;
	


	while (window.isOpen())
	{
		groundcollide = (player.playerbox).getGlobalBounds().intersects((ground.groundbox).getGlobalBounds());
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
			std::cout << "FINAL SCORE: " << player.points << std::endl;
			player.resetpoints();
			player.player_redraw(25, 25, ground);
			player.player_reset(ground);
			temp = 0;
			for (int i = 0; i <	ENEMYCOUNT; i++)
			{
				enemyarray[i]->resetenemypos();
			}
			bool start = true;
			starter_enemy = 0;

		}
		//Clock for timings
		dt = clock.restart().asSeconds();
		if (dt >(1.0f / 20.0f))
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
			//Player move function
			player.player_update(dt, groundcollide, ground);	
			
			//Enemy update functions
			//Most moved to this loop to reduce #for loops
			for (int i = 0; i < ENEMYCOUNT; i++)
			{
				enemyarray[i]->enemymove();
				enemyarray[i]->enemypoint(player);
				enemyarray[i]->enemycheckbounds();
			}
			
			//Player minus health and invincibility w/ break to reduce looping
			for (int i = 0; i < ENEMYCOUNT; i++)
			{
				if (enemyarray[i]->enemyhit(player)) {
					hit = true;
				}
				player.minushealthPSEUDOCODE(hit, dt);
				if (hit) {
					break;
				}
			}
			health.updatehp(player);

			if (((player.points / (ENEMYCOUNT*player.multiplier)) > player.multiplier) && player.points > 0) {
				player.multiplier++;
				if (player.multiplier % 6 == 0) {
					player.player_redraw(25, 25, ground);
					std::cout << "Reset size" << std::endl;
					player.resetcounter = 0;
				}
				else {
					player.player_redraw(25 + (10 * player.resetcounter), 25 + (10 * player.resetcounter), ground);
					player.resetcounter++;
					std::cout << "Growing; multiplier: " << player.multiplier << std::endl;
				}
			}
		}

		//DRAW
		window.clear(sf::Color::White);
		player.drawplayer(window);
		health.drawhealth(window);
		ground.drawground(window);
		menu.drawscore(window, player);
		menu.drawmultiplier(window, player);
		if (pause)
		{
			menu.drawpause(window);
		}
		if (player.is_hit())
		{
			menu.drawiframe(window, player);
		}
		for (int i = 0; i < ENEMYCOUNT; i++)
		{
			enemyarray[i]->drawenemy(window);
		}
		window.display();
	}
	return 0;
}
