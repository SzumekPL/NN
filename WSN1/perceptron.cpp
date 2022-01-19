#include "perceptron.h"

Perceptron::Perceptron(int inputSize, int myNumber) : myLabel(myNumber)
{
    theta = (rand() % 100 - 50) / 50.0; // -0.5 do 0.5

    weights = QVector<float>(inputSize);

    for(int i = 0; i < inputSize; ++i)
    {
        float randW = (rand() % 100 - 50) / 50.0;
        weights[i] = randW;
    }

    saveBestValues();
}

int Perceptron::calculate(QVector<int> matrix)
{
    if(matrix.size() == weights.size())
    {
        float sum = 0;
        for(int i = 0; i < matrix.size(); ++i)
        {
            sum += weights[i] * matrix[i];
        }

        if(sum > theta)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    return 0;
}

void Perceptron::saveBestValues()
{
    theta2 = theta;
    weights2 = weights;
}

int Perceptron::getWeightsSize()
{
    return weights.size();
}

QVector<float> Perceptron::getWeights()
{
    return weights;
}

void Perceptron::saveBest()
{
    weights2 = weights;
    theta2 = theta;
}
