#include "preymanager.h"

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

void PreyManager::draw(sf::RenderWindow& window){

for(int i =0 ; i<preys.size(); i++){
preys[i].draw(window);
}
}
