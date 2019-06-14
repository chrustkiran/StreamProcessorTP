//
// Created by chrustkiran on 6/12/19.
//

#include "ThreadPool.h"
#include "StreamProcessor.h"
#include "Benchmark.h"
#include "common.h"


void ThreadPool::processEvent() {
    while(true){ // it should be a flag but definitely should not check for buffer is empty or not!!!!
        StreamProcessor::processor->process(StreamProcessor::buffer->pop());
    }
}

void ThreadPool::inputFeed() {
    Benchmark::veryFirstTime = getCurrentTime();
    InputHandler::feedData(StreamProcessor::buffer);
}


void ThreadPool::initializeThreads(int T_NUM) {
    thread inputThread;

    inputThread = thread(&ThreadPool::inputFeed, this);

    thread pthreads[T_NUM];
    for (int i = 0; i < T_NUM; i++) {
        pthreads[i] = thread(&ThreadPool::processEvent,this);
    }
    for (int i = 0; i < T_NUM; ++i) {
        pthreads[i].join();
    }

    inputThread.join();
}