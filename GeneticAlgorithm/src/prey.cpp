#include "prey.h"
#include <cstdlib>
#include "gamemath.h"
#include <iostream>

void Prey::initialize(){

	speed = 0.01f;
	size = 5.f;
	body.setRadius(size);
	body.setFillColor(sf::Color::White);
	dir_x = rand() % 1001;
	dir_y = rand() %  801;
}

void Prey::move(float deltatime){
	sf::Vector2f difference = sf::Vector2f(dir_x, dir_y) - body.getPosition();

	difference = GameMath::normalizeVector(difference);
	float diff_x = body.getPosition().x - dir_x;
	float diff_y = body.getPosition().y - dir_y;

	//logic to avoid flickering and position changing when close to target distance
	if(diff_x < 0)
		diff_x = diff_x * -1;

	if(diff_y < 0)
		diff_y = diff_y * -1;

	//prey move if target distance is greater than 5
	if((diff_x > 5) && (diff_y > 5)){
		body.setPosition(body.getPosition() + difference * (speed * deltatime));
	}
}

void Prey::setDirection(float deltatime){

	direction_timer += deltatime;
	//set new direction every 3 seconds
	if(direction_timer > 10000){
		dir_x = rand() % 1001;
		dir_y = rand() %  801;

		direction_timer = 0;
	}

}

void Prey::draw(sf::RenderWindow& window){
	window.draw(body);
}
