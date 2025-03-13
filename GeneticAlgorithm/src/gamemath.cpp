#include "gamemath.h"
#include <math.h>

sf::Vector2f GameMath::normalizeVector(sf::Vector2f vector){

	float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);

	sf::Vector2f normalized_vector;
	normalized_vector.x = vector.x/magnitude;
	normalized_vector.y = vector.y/magnitude;
	return normalized_vector;
}

	bool GameMath::checkCollision(sf::CircleShape a, sf::CircleShape b){ 
		sf::Vector2f pos1 = a.getPosition() + (sf::Vector2f(a.getRadius(), a.getRadius()));
		sf::Vector2f pos2 = b.getPosition() + (sf::Vector2f(b.getRadius(), b.getRadius()));

		float distance = std::sqrt(std::pow(pos2.x - pos1.x, 2) + std::pow(pos2.y - pos1.y, 2));
		float radiusSum = a.getRadius() + b.getRadius();

		return distance <= radiusSum;

	}

