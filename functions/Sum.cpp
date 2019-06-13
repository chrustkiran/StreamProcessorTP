//
// Created by chrustkiran on 6/13/19.
//

#include "Sum.h"

int Sum::SUM = 0;

void Sum::calculateSum(int data) {
    m.lock();
    SUM = SUM + data;
    m.unlock();
}

void Sum::reset() {
    Sum::SUM = 0;
}

int Sum::getOutput() {
    return SUM;
}