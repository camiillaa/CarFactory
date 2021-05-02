//
// Created by Home on 15.12.2020.
//

#ifndef SOCKOKAMILA_ETAP2_CAR_H
#define SOCKOKAMILA_ETAP2_CAR_H


#include "MotorVehicle.h"

class Car : public MotorVehicle {

    int _doors{};
public:
    explicit Car(std::string brand, std::string owner,  std::string color, double fuel, int doors, int mileage=0);
    ~Car() override = default;
    void print() const override;
};


#endif //SOCKOKAMILA_ETAP2_CAR_H
