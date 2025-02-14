#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>

int main(){

//variables and objects initialization
const int window_width = 1000;
const int window_height = 800;
bool player_turn = true;

sf::Vector2i position;
	
sf::RenderWindow window(sf::VideoMode(window_width, window_height), "TicTacToe");
Game game;
game.initialize();

//window code
while (window.isOpen()){
sf::Event event;
while (window.pollEvent(event))
{
if (event.type == sf::Event::Closed)
window.close();
}

//get mouse position on click while player turn
if(player_turn){
if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
position = sf::Mouse::getPosition(window);
game.updatePlayer(player_turn, position);

}
}


//draw loop
window.clear(sf::Color::Black);
game.draw(window);
window.display();
}

return 0;
}
