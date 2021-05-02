//
// Created by Home on 15.12.2020.
//

#ifndef SOCKOKAMILA_ETAP2_MOTORVEHICLE_H
#define SOCKOKAMILA_ETAP2_MOTORVEHICLE_H


#include "Vehicle.h"
#include "Sprayer.h"
#include <iostream>

class MotorVehicle : public Vehicle {

protected:

    int _mileage;
    double _fConsumption;
    int _trunk;//bagaznik
    double _amountOfFuel;
    double _price;

public:
    void go(int mileage);
    void changeMileage();

    MotorVehicle(std::string &brand, std::string &owner, std::string &color, double fuel,
                 int mileage=0);
    virtual ~MotorVehicle() = default;
    virtual void print() const = 0;

    int showCapacity() override { return _trunk; };
    double countPrice() const;
    std::string whoamI() override{
        return "MOTORVEHICLE";
    }




};

#endif //SOCKOKAMILA_ETAP2_MOTORVEHICLE_H
