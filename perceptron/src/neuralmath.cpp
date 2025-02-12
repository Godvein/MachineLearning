
#include "neuralmath.h"
#include <random>
float NeuralMath::randomFloat(float low, float high) {
std::random_device rd;

std::mt19937 gen(rd());
std::uniform_real_distribution<double> dist(low, high);
double random_number = dist(gen);
 
return random_number;
}

