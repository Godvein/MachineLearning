#include <SFML/Graphics.hpp>
#include <iostream>
#include "perceptron.h"
#include <vector>
#include "point.h"


int main()
{
int window_width = 1000;
int window_height = 1000;
sf::RenderWindow window(sf::VideoMode(window_width, window_height), "My window");

//perceptron model
Perceptron perceptron;
perceptron.initialize();

//dataset to train the model
int data = 200;
std::vector<Point> dataset;

for(int i = 0; i<=data; i++){
Point point;
point.initialize(window_width, window_height);
dataset.push_back(point);
}
while (window.isOpen())
{
sf::Event event;
while (window.pollEvent(event))
{
if (event.type == sf::Event::Closed)
window.close();
}
//gameloop

window.clear(sf::Color::Black);
for(Point point : dataset){
point.draw(window);
}
window.display();
}

return 0;
}
