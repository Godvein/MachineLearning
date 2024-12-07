#include <SFML/Graphics.hpp>
#include <iostream>
#include "perceptron.h"
#include <vector>
#include "point.h"


int main()
{
int window_width = 1000;
int window_height = 1000;
sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Press Space to Train the Model");

sf::Vertex line[] =
{
    sf::Vertex(sf::Vector2f(0, 0)),
    sf::Vertex(sf::Vector2f(window_width, window_height))
};

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

//model training
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
for(Point point : dataset){
float input[2] = {point.x, point.y};
perceptron.train(input, point.result);
}
}


}
//gameloop

window.clear(sf::Color::Black);
window.draw(line, 2, sf::Lines);

for(Point point : dataset){
float input[2] = {point.x , point.y};
int guess = perceptron.guess(input);
//plot data in red if model predicts wrong
if(guess != point.result){
point.circle.setFillColor(sf::Color::Red);
}
//plot data in green if right prediction
else{
point.circle.setFillColor(sf::Color::Green);
}
point.draw(window);
}
window.display();
}

return 0;
}
