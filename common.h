#ifndef STREAM_PROCESSOR_COMMON_H
#define STREAM_PROCESSOR_COMMON_H

#include "vector"

#include <iostream>
#include <sys/time.h>
#include <chrono>

using namespace std;

inline chrono::_V2::high_resolution_clock::time_point getCurrentTime() {
   /* struct timeval tp;
    gettimeofday(&tp, NULL);
    return tp.tv_sec * 1000L + tp.tv_usec / 1000;*/
    return std::chrono::high_resolution_clock::now();
}

#endif //STREAM_PROCESSOR_COMMON_H