//
// Created by chrustkiran on 6/13/19.
//

#include "StreamProcessor.h"
#include "common.h"
#include "Benchmark.h"

Buffer<Data> *StreamProcessor::buffer = NULL;
Processor *StreamProcessor::processor = NULL;
Window *StreamProcessor::window = NULL;
/*OutputEmitter *StreamProcessor::outputEmitter = NULL;
InputHandler *StreamProcessor::inputHandler = NULL;*/

void StreamProcessor::initialize(int T_NUM) {
    StreamProcessor::buffer = new Buffer<Data>();
    StreamProcessor::processor = new Processor();
    this->threadPool->initializeThreads(T_NUM);
    cout << "Total time "<< std::chrono::duration_cast<std::chrono::nanoseconds>(getCurrentTime() - Benchmark::veryFirstTime).count() << endl;
}