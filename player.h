#pragma once
#include <SFML\Graphics.hpp>

class player {
private:
	float player_dx, player_dy;
	const float player_a = 80.0f;
	sf::Texture playertexture;
	int health;
	float iframe;
	bool hit;
public:
	sf::RectangleShape playerbox;
public:
	player() {
		player_dx = 0.0f;
		player_dy = 0.0f;
		playertexture.loadFromFile("face.jpg");
		playerbox.setSize(sf::Vector2f(100.0f, 100.0f));
		playerbox.setTexture(&playertexture);
		playerbox.setOrigin(100.0f / 2, 100.0f / 2);
		playerbox.setPosition(150.f, 437.0f);
		health = 10; 
		hit = false;
		iframe = 0.0f;
	}
	void player_update(float dt, bool groundcollide);
	/* PSEUDOCODE friend bool enemycollision(){
	if(enemy collides with player)
	{
		playerhealth--
	}*/
	void minushealthPSEUDOCODE(sf::RectangleShape pseudoenemy, float dt);
	


}; 