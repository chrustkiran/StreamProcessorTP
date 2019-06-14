//
// Created by chrustkiran on 6/14/19.
//

#include "Benchmark.h"
#include <iostream>
#include <chrono>

chrono::_V2::high_resolution_clock::time_point Benchmark::veryFirstTime;
chrono::_V2::high_resolution_clock::time_point Benchmark::endTime;
mutex Benchmark::m_mutex;

void Benchmark::calcTotalTime(chrono::_V2::high_resolution_clock::time_point currTime, Data data) {

    unique_lock<mutex> locker(m_mutex);
    cout << std::chrono::duration_cast<std::chrono::nanoseconds>(currTime - data.getIijTime()).count()/1000000<<endl;
    locker.unlock();
}