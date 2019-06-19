//
// Created by chrustkiran on 6/14/19.
//

#include "Benchmark.h"
#include "common.h"
#include <iostream>
#include <chrono>

chrono::_V2::high_resolution_clock::time_point Benchmark::veryFirstTime;
chrono::_V2::high_resolution_clock::time_point Benchmark::emitEndTime;
chrono::_V2::high_resolution_clock::time_point Benchmark::emitPreviousTime;
mutex Benchmark::m_mutex;
long Benchmark::avgNanoGap = 0;
long Benchmark::count = 0;
long Benchmark::emitGap = 0;

void Benchmark::calcTotalTime(chrono::_V2::high_resolution_clock::time_point currTime, Data data) {

    unique_lock<mutex> locker(m_mutex);
    cout << std::chrono::duration_cast<std::chrono::nanoseconds>(currTime - data.getIijTime()).count()<<endl;
    locker.unlock();
}

void Benchmark::calcLatency(long nanoGap) {
    m_mutex.lock();

    avgNanoGap = ((avgNanoGap * count) + nanoGap) / (count + 1);
    Benchmark::emitEndTime = getCurrentTime();
    emitGap = ((emitGap * count) + ((Benchmark::emitEndTime - Benchmark::emitPreviousTime).count())) / (count + 1);
    Benchmark::emitPreviousTime = Benchmark::emitEndTime;

    count++;
    if(count == 100000 ){
        cout <<"Avg Latency "<< avgNanoGap << " Total count " << count << " Emit gap " << emitGap <<"\n";
        cout << "Total time "<< std::chrono::duration_cast<std::chrono::nanoseconds>(getCurrentTime() - Benchmark::veryFirstTime).count() << endl;

    }
    m_mutex.unlock();
}

long Benchmark::getAvgNanoGap() {
    return avgNanoGap;
}
