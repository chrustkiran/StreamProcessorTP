//
// Created by chrustkiran on 6/12/19.
//

#include "ThreadPool.h"
#include "StreamProcessor.h"


void ThreadPool::processEvent() {
    StreamProcessor::window->checkInputEvent();
    StreamProcessor::processor->process(StreamProcessor::buffer->pop());
    StreamProcessor::window->checkOutputEvent();

}


void ThreadPool::initializeThreads(int T_NUM) {
    thread pthreads[T_NUM];
    for (int i = 0; i < T_NUM; i++) {
        thread(&ThreadPool::processEvent,this);
    }
    for (int i = 0; i < T_NUM; ++i) {
        pthreads[i].join();
    }
}