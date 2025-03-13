#include "foodmanager.h"
#include "gamemath.h"
#include <iostream>	
void FoodManager::initialize(){

for(int i = 0; i < food_limit; i++){
	sf::CircleShape food(4.f);
	int randomx = rand() % 1001;
	int randomy = rand() % 801;
	food.setPosition(sf::Vector2f(randomx, randomy));
	food.setFillColor(sf::Color::Green);
	foods.push_back(food);
}

}

bool FoodManager::checkFoodCollision(sf::CircleShape prey){
	for(int i = 0; i < foods.size(); i++){
		bool collided = GameMath::checkCollision(prey, foods[i]);
		if (collided){
			foods.erase(foods.begin() + i);
			return true;
		}
		
	}
	return false;
}

void FoodManager::draw(sf::RenderWindow& window){
	for(const auto& food:foods){
		window.draw(food);
	}

}



