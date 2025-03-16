#include <SFML/Graphics.hpp>
#include <iostream>
#include "preymanager.h"
#include "foodmanager.h"

int main(){
	const int window_width = 1000;
	const int window_height = 800;

	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Simulation");

	window.setFramerateLimit(30);
	//PREY MANAGER
	PreyManager preymanager;
	preymanager.initialize();

	//FOOD MANAGER
	FoodManager foodmanager;
	foodmanager.initialize();
	
	sf::Clock clock;
	float deltatime = 0.f;

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//gameloop

		//delta time
		deltatime = clock.restart().asSeconds();

		//game logic
		preymanager.update(deltatime, foodmanager);
		preymanager.checkPreyCollision();
		preymanager.checkPreyFoodCollision(foodmanager);

		window.clear(sf::Color::Black);
		preymanager.draw(window);
		foodmanager.draw(window);
		window.display();
	}
	return 0;
}
