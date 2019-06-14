//
// Created by chrustkiran on 6/13/19.
//

#ifndef STREAMPROCESSORLLVM_TP_PROCESSOR_H
#define STREAMPROCESSORLLVM_TP_PROCESSOR_H


#include "Data.h"
#include "functions/Sum.h"

class Processor {
private:
    Sum sum;
public:
    void process(Data event);
    Data getOutputs(Data data);
    void reset();
    Processor();
};


#endif //STREAMPROCESSORLLVM_TP_PROCESSOR_H
