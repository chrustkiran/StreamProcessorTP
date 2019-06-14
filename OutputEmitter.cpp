//
// Created by chrustkiran on 6/13/19.
//

#include "OutputEmitter.h"
#include "StreamProcessor.h"
#include "Benchmark.h"
#include "common.h"
#include <iostream>

 void OutputEmitter::emitData(Data output) {
   Benchmark::calcLatency((std::chrono::high_resolution_clock::now() - output.getIijTime()).count());

}