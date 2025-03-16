#pragma once
#include <SFML/Graphics.hpp>

class GameMath{

	public:
		static sf::Vector2f normalizeVector(sf::Vector2f vector);
		static bool checkCollision(sf::CircleShape a, sf::CircleShape b);
		static float checkDistance(const sf::CircleShape& c1, const sf::CircleShape& c2);
};
