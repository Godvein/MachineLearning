#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Prey;

class FoodManager{

private:
int food_limit = 10;

public:
std::vector<sf::CircleShape> foods;

public:
void initialize();
void draw(sf::RenderWindow& window);
bool checkFoodCollision(Prey& prey);

};
