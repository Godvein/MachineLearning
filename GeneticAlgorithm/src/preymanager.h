#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "prey.h"
#include "foodmanager.h"

class PreyManager{

	private:
		std::vector<Prey> preys;

	public:

		void initialize();
		void update(float deltatime);
		void checkPreyCollision();
		void Reproduce(float i, float j);
		void draw(sf::RenderWindow& window);
		void checkPreyFoodCollision(FoodManager& foodmanager);
};

