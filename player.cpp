#include <SFML\Graphics.hpp>
#include "player.h"
#include <iostream>

void player::player_update(float dt, bool groundcollide /*playerbox.getGlobalBounds().intersects(ground.getGlobalBounds())*/) {
	if (groundcollide)
	{
		std::cout << "colliding" << std::endl;
		player_dy = 0;
		player_dx = 0;
		playerbox.setPosition(playerbox.getPosition().x, 438.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && groundcollide)
	{
		std::cout << "attempting to jump" << std::endl;
		player_dy = -28.0f;
	}

	if (player_dy < 0)
	{
		std::cout << "rising" << std::endl;
	}


	if (!groundcollide)
	{
		std::cout << "gravity" << std::endl;
		std::cout << "CURRENT VELOCITY" << player_dy << std::endl;

		player_dy = player_dy + player_a * dt;
		std::cout << "NOW VELOCITY" << player_dy << std::endl;
	}

	playerbox.move(player_dx, player_dy);
	/*should make sense despite prev code treating dy as velocity b/c dy can
	be interpreted as small diff in y
	"It just works." -T.H.
	*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		if (playerbox.getPosition().x >= 25.0f)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
			{
				if (groundcollide)
					playerbox.move(-15.0f, 0.0f);
				else
					player_dx += -1.5f;
			}
			else
				if (groundcollide)
					playerbox.move(-10.0f, 0.0f);
				else
					player_dx += -1.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		if (playerbox.getPosition().x <= 1024)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
			{
				playerbox.move(15.0f, 0.0f);
				std::cout << "Running" << std::endl;
			}
			else
				playerbox.move(10.0f, 0.0f);
	}

	if (playerbox.getPosition().x > 1024)
	{
		player_dx = 0;
		playerbox.setPosition(1023.0f, playerbox.getPosition().y);
	}
	else if (playerbox.getPosition().x < 0)
	{
		player_dx = 0;
		playerbox.setPosition(1.0f, playerbox.getPosition().y);
	}


} 

//CODE BELOW IS PSEUDOCODE BUT PART CAN BE USED FOR MINUS HEALTH
//MINUSHEALTH FUNC CAN TAKE BOOL OF HIT
void player::minushealthPSEUDOCODE(sf::RectangleShape pseudoenemy, float dt) {
	std::cout << "health: " << health << std::endl;
	if (playerbox.getGlobalBounds().intersects(pseudoenemy.getGlobalBounds()) && !hit)
	//replace if condition with BOOL HIT
	{
		health--;
		std::cout << "minus health" << std::endl << health << "left" << std::endl;
		hit = true;
	}

	if (hit)
	{
		iframe += dt;
		std::cout << "IFRAME: " << iframe << std::endl;
		if (iframe >= (120 * dt))
		{
			std::cout << "cond fulfilled" << std::endl;
			hit = false;
			iframe = 0.0f;
		}
	}
}