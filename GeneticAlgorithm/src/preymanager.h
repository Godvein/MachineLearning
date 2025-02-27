#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "prey.h"


class PreyManager{

	private:
		std::vector<Prey> preys;

	public:

		void initialize();
		void update(float deltatime);
		void draw(sf::RenderWindow& window);
};

