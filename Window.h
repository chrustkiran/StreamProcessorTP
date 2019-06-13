//
// Created by chrustkiran on 6/13/19.
//

#ifndef STREAMPROCESSORLLVM_TP_WINDOW_H
#define STREAMPROCESSORLLVM_TP_WINDOW_H

#include <condition_variable>
#include <mutex>

using namespace std;
class Window {


private:
    int condVariable = 0;   //length or duration
    int inputCounter = 0;
    int outputCounter = 0;
    int testVar = 0;
    condition_variable m_condition;
    mutex m_mutex;
    static bool inputBarrier;

public:
    void checkInputEvent();
    void checkOutputEvent();

    int getCondVariable() const;

    void setCondVariable(int condVariable);


};


#endif //STREAMPROCESSORLLVM_TP_WINDOW_H
