//
// Created by chrustkiran on 6/12/19.
//

#include "ThreadPool.h"
#include "StreamProcessor.h"


void *ThreadPool::processEvent(void *args) {
    StreamProcessor::window->checkInputEvent();
    StreamProcessor::processor->process(StreamProcessor::buffer->pop());
    StreamProcessor::window->checkOutputEvent();

}


void ThreadPool::initializeThreads(int T_NUM) {
    pthread_t pthreads[T_NUM];

    for (int i = 0; i < T_NUM; i++) {
        pthread_create(&pthreads[i], NULL, &ThreadPool::processEvent, NULL);
    }
}