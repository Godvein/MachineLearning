#include "prey.h"
#include <cstdlib>
#include "gamemath.h"
#include <iostream>
#include "foodmanager.h"
#include "preymanager.h"

void Prey::initialize(){

	speed = 5.f;
	size = 5.f;
	body.setRadius(size);
	body.setFillColor(sf::Color::White);
	dir_x = rand() % 1001;
	dir_y = rand() %  801;
}

void Prey::move(float deltatime){
	sf::Vector2f difference = sf::Vector2f(dir_x, dir_y) - body.getPosition();

	difference = GameMath::normalizeVector(difference);

		body.setPosition(body.getPosition() + difference * speed * deltatime);
}

void Prey::setDirection(float deltatime, FoodManager& foodmanager){

	direction_timer += deltatime;
	//set new direction every 10 seconds
	if(direction_timer > 10.0f && !isHungry ){
		dir_x = rand() % 1001;
		dir_y = rand() %  801;

		direction_timer = 0;
	}
	if(isHungry){
	goToFood(foodmanager);
		
}
}

void Prey::goToFood(FoodManager& foodmanager){
	sf::Vector2f nearestfood = foodmanager.foods[0].getPosition();
	float distance = GameMath::checkDistance(body, foodmanager.foods[0]);	
	for(int i=1; i<foodmanager.foods.size(); i++){
	
	float new_distance = GameMath::checkDistance(body, foodmanager.foods[i]);
	if(distance > new_distance){
	nearestfood = foodmanager.foods[i].getPosition();
	distance = new_distance;
}
}
dir_x = nearestfood.x;
dir_y = nearestfood.y;
}
	
void Prey::draw(sf::RenderWindow& window){
	window.draw(body);
}
