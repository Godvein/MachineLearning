#include <SFML/Graphics.hpp>
#include "perceptron.h"
#include "neuralmath.h"
void Perceptron::initialize(){

	//initialize weight
	for(int i = 0; i < sizeof(weights)/sizeof(weights[0]); i++){
		weights[i] = NeuralMath::randomFloat(-1,1);
	}

}

//activation function sign
int Perceptron::sign(float sum){
	if(sum >= 0){
		return 1;
	}
	else{
		return -1;
	}
}

//initial guess of the model before training
int Perceptron::guess(float input[]){

	float sum = 0;
	for(int i = 0; i < sizeof(weights)/sizeof(weights[0]); i++){
		sum += input[i] * weights[i];
	}

	return sign(sum);
}

void Perceptron::train(float input[], int result){

	//result is the expected data
	int guess_result = guess(input);
	int error = result - guess_result;

	for(int i = 0; i< sizeof(weights)/sizeof(weights[0]); i++){
		weights[i] += error * input[i] * lr;
	}

}
