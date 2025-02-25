#include "gamemath.h"
#include <math.h>

sf::Vector2f GameMath::normalizeVector(sf::Vector2f vector){

float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);

sf::Vector2f normalized_vector;
normalized_vector.x = vector.x/magnitude;
normalized_vector.y = vector.y/magnitude;
return normalized_vector;

}

