//
// Created by chrustkiran on 6/13/19.
//

#include "OutputEmitter.h"
#include "StreamProcessor.h"
#include <iostream>

void OutputEmitter::emitData() {
   cout << StreamProcessor::processor->getOutputs() << endl;
}