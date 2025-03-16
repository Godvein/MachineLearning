#pragma once
#include <SFML/Graphics.hpp>

class FoodManager;

class Prey{

	private:
		//direction the prey is moving to
		float dir_x = 0.f;
		float dir_y = 0.f;

		float direction_timer = 0.f;
	public:
		float speed;
		float size;


		bool canReproduce = true;
		bool isHungry = false;
		sf::CircleShape body;
	public:
		void initialize();
		void move(float deltatime);
		void setDirection(float deltatime, FoodManager& foodmanager);
		void draw(sf::RenderWindow& window);
		void goToFood(FoodManager& foodmanager);

};
