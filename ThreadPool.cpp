//
// Created by chrustkiran on 6/12/19.
//

#include "ThreadPool.h"
#include "StreamProcessor.h"
#include "TimeWindow.h"
#include "common.h"

void ThreadPool::processEvent() {
    while(true) {
        StreamProcessor::window->checkInputEvent();
        StreamProcessor::processor->process(StreamProcessor::buffer->pop());
        StreamProcessor::window->checkOutputEvent();
    }
}

void ThreadPool::inputFeed() {
    InputHandler::feedData(StreamProcessor::buffer);
}



void ThreadPool::initializeThreads(int T_NUM) {
    thread pthreads[T_NUM];

    thread inputThread;

    inputThread = thread(&ThreadPool::inputFeed, this);

    for (int i = 0; i < T_NUM; i++) {
        pthreads[i] = thread(&ThreadPool::processEvent,this);
    }
    for (int i = 0; i < T_NUM; ++i) {
        pthreads[i].join();
    }
    inputThread.join();
}