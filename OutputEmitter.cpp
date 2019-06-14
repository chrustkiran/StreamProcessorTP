//
// Created by chrustkiran on 6/13/19.
//

#include "OutputEmitter.h"
#include "StreamProcessor.h"
#include "Benchmark.h"
#include "common.h"
#include <iostream>

 void OutputEmitter::emitData(Data output) {
   //cout << output.getWeight()<< endl;
   Benchmark::calcTotalTime(getCurrentTime(),output);

}