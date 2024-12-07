#include <SFML/Graphics.hpp>
#include <iostream>
#include "perceptron.h"


int main()
{
sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
Perceptron perceptron;
perceptron.initialize();
float input[2] = {500.f, 400.f};
std::cout << perceptron.guess(input);
while (window.isOpen())
{
sf::Event event;
while (window.pollEvent(event))
{
if (event.type == sf::Event::Closed)
window.close();
}
window.clear(sf::Color::Black);
window.display();
}

return 0;
}
