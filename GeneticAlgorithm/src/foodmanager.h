#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class FoodManager{

private:
int food_limit = 10;
std::vector<sf::CircleShape> foods;

public:
void initialize();
void draw(sf::RenderWindow& window);
bool checkFoodCollision(sf::CircleShape prey);

};
