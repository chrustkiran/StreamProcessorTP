//
// Created by chrustkiran on 6/13/19.
//

#include "InputHandler.h"
#include "common.h"

 void InputHandler::feedData(Buffer<Data> *buffer) {

    for(int i=0;i<100000;i++){
        Data data;
        data.setWeight(i);
        data.setIijTime(std::chrono::high_resolution_clock::now());
        buffer->push(data);
    }
}