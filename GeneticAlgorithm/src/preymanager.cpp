#include "preymanager.h"
#include <iostream>
#include <cmath>
void PreyManager::initialize(){

	for(int i = 0; i<2; i++){
		Prey prey;
		prey.initialize();
		preys.push_back(prey);
	}
}

void PreyManager::update(float deltatime){
	for(int i =0 ; i<preys.size(); i++){
		preys[i].setDirection(deltatime);
		preys[i].move(deltatime);
	}
}

void PreyManager::checkPreyCollision(){

	for(int i = 0; i<preys.size(); i++){
		for(int j = 0; j<preys.size(); j++){

			sf::Vector2f pos1 = preys[i].body.getPosition() + (sf::Vector2f(preys[i].body.getRadius(), preys[i].body.getRadius()));
			sf::Vector2f pos2 = preys[j].body.getPosition() + (sf::Vector2f(preys[j].body.getRadius(), preys[j].body.getRadius()));

			float distance = std::sqrt(std::pow(pos2.x - pos1.x, 2) + std::pow(pos2.y - pos1.y, 2));
			float radiusSum = preys[i].body.getRadius() + preys[j].body.getRadius(); 
			bool collided;

			collided = distance <= radiusSum;
			if((collided && preys[i].canReproduce && preys[j].canReproduce) && (i != j)){
				Reproduce(i, j);
			}

		}
	}
}

void PreyManager::Reproduce(float i, float j){
	preys[i].canReproduce = false;
	preys[j].canReproduce = false;
	Prey prey;
	prey.initialize();
	prey.canReproduce = false;
	preys.push_back(prey);
	
}

void PreyManager::draw(sf::RenderWindow& window){

	for(int i =0 ; i<preys.size(); i++){
		preys[i].draw(window);
	}
}
