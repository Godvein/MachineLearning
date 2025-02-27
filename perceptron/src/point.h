#pragma once
#include <SFML/Graphics.hpp>
class Point{


	public:

		float x;
		float y;
		int result;

		sf::CircleShape circle;
	public:

		void initialize(int width, int height);
		void draw(sf::RenderWindow& window);

};


