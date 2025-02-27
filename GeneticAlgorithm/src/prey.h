#pragma once
#include <SFML/Graphics.hpp>

class Prey{

	private:
		float speed;
		float size;
		sf::CircleShape body;

		//direction the prey is moving to
		float dir_x = 0.f;
		float dir_y = 0.f;

		float direction_timer = 0.f;

	public:
		void initialize();
		void move(float deltatime);
		void setDirection(float deltatime);
		void draw(sf::RenderWindow& window);

};
