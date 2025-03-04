#pragma once
#include <SFML/Graphics.hpp>

class Prey{

	private:
		float speed;
		float size;

		//direction the prey is moving to
		float dir_x = 0.f;
		float dir_y = 0.f;

		float direction_timer = 0.f;
	public:
		bool canReproduce = true;
		sf::CircleShape body;
	public:
		void initialize();
		void move(float deltatime);
		void setDirection(float deltatime);
		void draw(sf::RenderWindow& window);

};
