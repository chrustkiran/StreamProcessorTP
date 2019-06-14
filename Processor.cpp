//
// Created by chrustkiran on 6/13/19.
//

#include "Processor.h"
#include "StreamProcessor.h"
#include <iostream>

void Processor::process(Data event) {
    //sum.calculateSum(event.getWeight());
    //this->getOutputs(event);
    OutputEmitter::emitData(event);
}

Data Processor::getOutputs(Data data) {
    //return sum.getOutput();

    return data;
}

void Processor::reset() {
    sum.reset();
}

Processor::Processor() {
    //this->sum = new Sum();
}