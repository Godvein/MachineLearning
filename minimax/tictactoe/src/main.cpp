#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>

int main(){

//variables and objects initialization
const int window_width = 1000;
const int window_height = 800;
bool player_turn = true;

char player = 'X';
char bot = 'O';

//default no winner
std::string winner = "n";
bool game_over = false;

//search depth 
int depth = 9;

sf::Vector2i position;
	
sf::RenderWindow window(sf::VideoMode(window_width, window_height), "TicTacToe");

//winner declaration text
sf::Font font;
if (!font.loadFromFile("Fonts/Arial.ttf")){
std::cout << "font not loaded";
}else{
std::cout << "font loaded";
}
sf::Text winnerText;
winnerText.setFont(font);
winnerText.setPosition(sf::Vector2f(400.f,100.f));
winnerText.setFillColor(sf::Color::White);
winnerText.setCharacterSize(30);

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

//get mouse position on click if player turn
if(player_turn){
if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
position = sf::Mouse::getPosition(window);
game.updatePlayer(player_turn, position, player);

}
}
//else bots turn
else{
game.updateBot(player_turn, bot, depth);
}

//check for winner
winner = game.checkWinner();

//check if game is over
game_over = game.gameOver();

if(winner == "X"){
winnerText.setString("X wins");
}else if(winner == "O"){
winnerText.setString("O wins");
}else{
winnerText.setString("Good Luck");
}

//draw loop
window.clear(sf::Color::Black);
window.draw(winnerText);
game.draw(window);
window.display();
}

return 0;
}
