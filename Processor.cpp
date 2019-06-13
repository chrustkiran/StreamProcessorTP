//
// Created by chrustkiran on 6/13/19.
//

#include "Processor.h"
#include <iostream>

void Processor::process(Data event) {
    sum.calculateSum(event.getWeight());
}

int Processor::getOutputs() {
    return sum.getOutput();
}

void Processor::reset() {
    sum.reset();
}

Processor::Processor() {
    //this->sum = new Sum();
}