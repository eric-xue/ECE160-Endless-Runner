#pragma once
#include <SFML\Graphics.hpp>
#include "Health.h"
#include "ground.h"
#include "menu.h"
#include "iostream"

class player {
private:
	float playerwidth, playerheight;
	float player_dx, player_dy;
	float max_dx, max_dy;
	const float player_a = 80.0f;
	sf::Texture playertexture;
	float maxhealth;
	float iframe;
	bool hit;
	int maxjump, jumpdone;
	float jumpairtime, minjumpairtime;
	int points;
public:
	sf::RectangleShape playerbox;
	float health;
public:
	player() {
		points = 0;
		playerwidth = 50.0f;
		playerheight = 50.0f;
		player_dx = 0.0f;
		player_dy = 0.0f;
		max_dx = 0.0f;//unused
		max_dy = -29.5f;
		playertexture.loadFromFile("face.jpg");
		playerbox.setSize(sf::Vector2f(playerwidth, playerheight));
		playerbox.setTexture(&playertexture);
		playerbox.setOrigin(playerwidth/2 , playerheight/2);
		playerbox.setPosition(150.0f, 437.0f);
		health = 10.0f;
		maxhealth = health;
		hit = false;
		iframe = 0.0f;
		maxjump = 4;
		jumpdone = 0;
		jumpairtime = 0.0f;
		minjumpairtime = 0.17f;
	}
	void player_update(float dt, bool groundcollide, ground ground);
	void minushealthPSEUDOCODE(bool enemyhit, float dt);
	void drawplayer(sf::RenderWindow& window);
	void player_reset(ground ground);
	void resetpoints();
	//=============================
	bool is_hit();
	//=============================
	//friend void health::updatehp(player player1);
	friend class health;
	friend class enemy;
	friend class menu;

}; 