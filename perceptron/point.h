#pragma once
#include <SFML/Graphics.hpp>
class Point{

private:
sf::CircleShape circle;

public:

float x;
float y;
int result;

public:

void initialize(int width, int height);
void draw(sf::RenderWindow& window);

};


