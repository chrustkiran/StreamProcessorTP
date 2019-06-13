//
// Created by chrustkiran on 6/12/19.
//

#ifndef STREAMPROCESSORLLVM_TP_DATA_H
#define STREAMPROCESSORLLVM_TP_DATA_H


class Data {
public:
    int getWeight() const;

    void setWeight(int weight);

    int getTemperature() const;

    void setTemperature(int temperature);

private:
    int weight;
    int temperature;

};


#endif //STREAMPROCESSORLLVM_TP_DATA_H
