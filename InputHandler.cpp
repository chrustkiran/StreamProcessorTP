//
// Created by chrustkiran on 6/13/19.
//

#include "InputHandler.h"


void InputHandler::feedData(Buffer<Data> *buffer) {

    for(int i=10;i<100;i++){
        Data data;
        data.setWeight(i);
        data.setTemperature(100+i);
        buffer->push(data);
    }
}