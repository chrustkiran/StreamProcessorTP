//
// Created by chrustkiran on 6/13/19.
//

#include "Window.h"
#include "StreamProcessor.h"

bool Window::inputBarrier = true;

void Window::checkInputEvent() {
    //conditional variable

    unique_lock<mutex> m_lock(m_mutex);
    if(this->inputCounter < this->condVariable){
        inputBarrier = false;
    }
    while (inputBarrier){ m_condition.wait(m_lock);}

    this->inputCounter++;
    m_lock.unlock();
}

int Window::getCondVariable() const {
    return condVariable;
}

void Window::setCondVariable(int condVariable) {
    Window::condVariable = condVariable;
}


void Window::checkOutputEvent() {
    m_mutex.lock();
    this->outputCounter++;
    if(outputCounter == this->inputCounter){
        //StreamProcessor::outputEmitter->canEmit = true;
        StreamProcessor::outputEmitter->emitData();
        StreamProcessor::processor->reset();
        inputBarrier = false;
        m_condition.notify_all();
    }
    m_mutex.unlock();

}