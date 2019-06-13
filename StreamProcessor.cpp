//
// Created by chrustkiran on 6/13/19.
//

#include "StreamProcessor.h"

 Buffer<Data> *StreamProcessor::buffer = NULL;
 Processor *StreamProcessor::processor = NULL;
 Window *StreamProcessor::window = NULL;
 OutputEmitter *StreamProcessor::outputEmitter = NULL;

void StreamProcessor::initialize(int T_NUM) {
     StreamProcessor::buffer = new Buffer<Data>();
     StreamProcessor::processor = new Processor();
     StreamProcessor::window = new Window();
     StreamProcessor::outputEmitter = new OutputEmitter;
     window->setCondVariable(5);
     inputHandler->feedData(buffer);

    this->threadPool->initializeThreads(T_NUM);
}