//
// Created by chrustkiran on 6/12/19.
//

#include "Data.h"

int Data::getWeight() const {
    return weight;
}

void Data::setWeight(int weight) {
    Data::weight = weight;
}

int Data::getTemperature() const {
    return temperature;
}

void Data::setTemperature(int temperature) {
    Data::temperature = temperature;
}
