#include "game.h"
#include <iostream>	
	
void Game::initialize(){
if(!font.loadFromFile("Fonts/Arial.ttf")){
std::cout << "error loading font";
}
else{
std::cout << "font loaded";
}
}


void Game::draw(sf::RenderWindow& window){
for(int i=0; i<3; i++){
for(int j=0; j<3; j++){

//draw the board sections in White
sf::RectangleShape section(sf::Vector2f(section_width, section_width));
section.setPosition(section_width * j + gap , section_width * i + gap);

section.setOutlineThickness(2);
section.setOutlineColor(sf::Color::Black);
section.setFillColor(sf::Color::White); 

window.draw(section);

//draw the texts on the sections in black
if(board[i][j] != ""){
sf::Text text;
text.setFont(font);
text.setString(board[i][j]);
text.setCharacterSize(40);   
text.setFillColor(sf::Color::Black);
                
  
sf::FloatRect textBounds = text.getLocalBounds();
text.setOrigin(textBounds.width / 2, textBounds.height / 2);
text.setPosition(section.getPosition().x + section_width / 2, section.getPosition().y + section_width / 2);
window.draw(text);

}
}
}

}
