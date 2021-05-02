//
// Created by Home on 15.12.2020.
//

#ifndef SOCKOKAMILA_ETAP3_MOTORCYCLE_H
#define SOCKOKAMILA_ETAP3_MOTORCYCLE_H

#include "MotorVehicle.h"

class MotorCycle : public MotorVehicle {

public:
    MotorCycle(std::string brand, std::string owner, std::string color, double fuel, int mileage=0);
    ~MotorCycle() override = default;
    void print() const override;
};

#endif //SOCKOKAMILA_ETAP3_MOTORCYCLE_H
