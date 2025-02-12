#pragma once

class Perceptron{
private:
float lr = 0.1f; //learning rate of the model
public:
float weights[2];

public:
void initialize();
int guess(float input[]);
int sign(float sum);
void train(float input[], int result);
};
 
