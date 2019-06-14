//
// Created by chrustkiran on 6/14/19.
//

#include "Benchmark.h"
#include <iostream>
#include <chrono>

chrono::_V2::high_resolution_clock::time_point Benchmark::veryFirstTime;
chrono::_V2::high_resolution_clock::time_point Benchmark::endTime;
mutex Benchmark::m_mutex;
long Benchmark::avgNanoGap = 0;
long Benchmark::count = 0;

void Benchmark::calcTotalTime(chrono::_V2::high_resolution_clock::time_point currTime, Data data) {

    unique_lock<mutex> locker(m_mutex);
    cout << std::chrono::duration_cast<std::chrono::nanoseconds>(currTime - data.getIijTime()).count()<<endl;
    locker.unlock();
}

void Benchmark::calcLatency(long nanoGap) {
    m_mutex.lock();
    avgNanoGap = ((avgNanoGap * count) + nanoGap) / (count + 1);
    count++;
    if(count == 100000 ){
        cout << avgNanoGap << " " << count <<"\n";
    }
    m_mutex.unlock();
}

long Benchmark::getAvgNanoGap() {
    return avgNanoGap;
}
