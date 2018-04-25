#include "enemy.h"


void enemy::enemymove()
{
	enemybox.move(enemy_dx, 0.0f);
}

void enemy::enemycheckbounds()
{
	if (enemybox.getPosition().x < -10)
	{
		std::cout << "OOB" << std::endl;
		float temp = (std::rand() % 50) * (512.0f / 51.0f);
		enemybox.setPosition(1020.0f, temp);
		pointcounted = false;
	}
}

void enemy::resetenemypos()
{
		float temp = std::rand() % 6 * (1024.0f / 7.0f);
		enemybox.setPosition(sf::Vector2f(1050.0f, temp));
		pointcounted = false;
}

bool enemy::enemyhit(player player)
{
	if (enemybox.getGlobalBounds().intersects(player.playerbox.getGlobalBounds()))
		return true;
	return false;
}

void enemy::drawenemy(sf::RenderWindow & window)
{
	window.draw(enemybox);
}

void enemy::enemypoint(player &player)
{
	if (enemybox.getPosition().y > player.playerbox.getPosition().y &&
		enemybox.getPosition().x < player.playerbox.getPosition().x && !pointcounted)
	{
		player.points++;
		std::cout << "Points: " << player.points << std::endl;
		pointcounted = true;
	}
}

