#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <QVector>

class Perceptron
{
    int myLabel;

    float theta;
    QVector<float>weights;

    float theta2;
    QVector<float>weights2;

public:
    Perceptron(int inputSize = 0, int myNumber = 0);
    int calculate(QVector<int>matrix);

    void saveBestValues();
    int getWeightsSize();
    QVector<float> getWeights();

    void saveBest();
};

#endif // PERCEPTRON_H
