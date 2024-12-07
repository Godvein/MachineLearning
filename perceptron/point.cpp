#include "point.h"
#include "neuralmath.h"
#include <iostream>

//initialize dataset
void Point::initialize(int width, int height){
circle.setRadius(10.f);
x = NeuralMath::randomFloat(0, width);
y = NeuralMath::randomFloat(0, height);
circle.setPosition(sf::Vector2f(x,y));

if(x > y){
result = 1;
}
else{
result = -1;
}

if(result == 1){
circle.setFillColor(sf::Color::Blue);
}else{
circle.setFillColor(sf::Color::White);
}

}

void Point::draw(sf::RenderWindow& window){
window.draw(circle);
}

