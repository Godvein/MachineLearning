#include "preymanager.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include "gamemath.h"

void PreyManager::initialize(){

	for(int i = 0; i<2; i++){
		Prey prey;
		prey.initialize();
		preys.push_back(prey);
	}
}

void PreyManager::update(float deltatime, FoodManager& foodmanager){
	for(int i =0 ; i<preys.size(); i++){
		preys[i].setDirection(deltatime, foodmanager);
		preys[i].move(deltatime);
	}
}

void PreyManager::checkPreyCollision(){

	for(int i = 0; i<preys.size(); i++){
		for(int j = 0; j<preys.size(); j++){
			bool collided = GameMath::checkCollision(preys[i].body, preys[j].body);
			
			//check if parents can reproduce 
			if((collided && preys[i].canReproduce && preys[j].canReproduce) && (i != j)){
				Reproduce(i, j);
			}

		}
	}
}

void PreyManager::checkPreyFoodCollision(FoodManager& foodmanager){
	for(int i =0; i<preys.size(); i++){
		bool collided = foodmanager.checkFoodCollision(preys[i]);
		if(collided && preys[i].isHungry){
			preys[i].canReproduce = true;
			preys[i].isHungry = false;
		}
	}

}

void PreyManager::Reproduce(float i, float j){
	//set reproduction ability of parents to false
	preys[i].canReproduce = false;
	preys[j].canReproduce = false;

	preys[i].isHungry = true;
	preys[j].isHungry = true;

	float mutationRate = 0.5f; //mutation rate	
		
	Prey prey;
	prey.initialize();
	prey.body.setPosition(preys[i].body.getPosition());

	prey.speed = ((preys[i].speed+preys[j].speed)/2) * (1+((rand()%201-100)/100.f) * mutationRate);
	prey.size = ((preys[i].size+preys[j].size)/2) * (1+((rand()%201-100)/100.f) * mutationRate);

	std::cout << std::fixed << std::setprecision(6) << prey.speed << std::endl;
	std::cout << std::fixed << std::setprecision(6) << prey.size <<std::endl;

	//set reproduction ability of child to false
	prey.canReproduce = false;
	prey.isHungry = true;
	preys.push_back(prey);
	
}

void PreyManager::draw(sf::RenderWindow& window){

	for(int i =0 ; i<preys.size(); i++){
		preys[i].draw(window);
	}
}
