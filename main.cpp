#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#define playerwidth 100.0f
#define playerheight 100.0f
int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 512), "SFML TUTORIAL", sf::Style::Titlebar | sf::Style::Close);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	sf::Texture playertexture;
	playertexture.loadFromFile("face.jpg");
	player.setTexture(&playertexture);
	player.setOrigin(50.0f, 50.0f);
	player.setPosition(150.0f, 437.0f);
	window.setFramerateLimit(30);
	bool isjumped = false;
	bool groundcollide;
	sf::RectangleShape ground(sf::Vector2f(1024.0f, 150.0f));
	ground.setOrigin(512.0f, 25.0f);
	ground.setFillColor(sf::Color::Black);
	ground.setPosition(512.0f, 512.0f);
	sf::Clock clock;
	float Player_dx = 0.0f;
	float Player_dy = 0.0f;
	float player_a = 80.0f;
	window.setFramerateLimit(60);
	
	float dt;

	while (window.isOpen())
	{
		sf::Event evnt;
		groundcollide = player.getGlobalBounds().intersects(ground.getGlobalBounds());
		dt = clock.restart().asSeconds(); 

		window.clear(sf::Color::White);
		window.draw(player);
		window.draw(ground);
		window.display();


		std::cout << "beginning dy: " << Player_dy << std::endl;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && groundcollide)
		{
			std::cout << "attempting to jump" << std::endl;
			Player_dy = -28.0f;
		}

		if (Player_dy < 0)
		{
			std::cout << "rising" << std::endl;
		}


		if (!groundcollide)
		{
			std::cout << "falling" << std::endl;
			std::cout << "CURRENT VELOCITY" << Player_dy << std::endl;

			Player_dy = Player_dy + player_a * dt;
			std::cout << "NOW VELOCITY" << Player_dy << std::endl;
		}
		
		player.move(Player_dx, Player_dy);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			if (player.getPosition().x >= 25.0f)
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
				{
					if(groundcollide)
						player.move(-15.0f, 0.0f);
					else
						Player_dx += -1.5f;
				}
				else
					if(groundcollide)
						player.move(-10.0f, 0.0f);
					else
						Player_dx += -1.0f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			if (player.getPosition().x <= 1024)
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
				{
					player.move(15.0f, 0.0f);
					std::cout << "Running" << std::endl;
				}
				else
					player.move(10.0f, 0.0f);
		}

		if (player.getPosition().x > 1024)
		{
			Player_dx = 0;
			player.setPosition(1023.0f, player.getPosition().y);
		}
		else if (player.getPosition().x < 0)
		{
			Player_dx = 0;
			player.setPosition(1.0f, player.getPosition().y);
		}

		if (player.getGlobalBounds().intersects(ground.getGlobalBounds()))
		{
			std::cout << "colliding" << std::endl;
			Player_dy = Player_dy;
			Player_dx = 0;
			player.setPosition(player.getPosition().x, 438.0f);
		}

	}


	return 0;
}