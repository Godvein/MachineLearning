#pragma once

class Perceptron{

public:
float weights[2];

public:
void initialize();
int guess(float input[]);
int sign(float sum);
};
 
