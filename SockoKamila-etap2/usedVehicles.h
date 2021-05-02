//
// Created by Home on 15.12.2020.
//

#ifndef SOCKOKAMILA_ETAP2_USEDVEHICLES_H
#define SOCKOKAMILA_ETAP2_USEDVEHICLES_H

#include <string>
#include "MotorVehicle.h"
#include <vector>
#include <memory>
#include "Car.h"

class usedVehicles {

   std::vector<MotorVehicle*> parking;

    double cashHoldings = 200000;
    double prCash = 0;
    std::string _name;

public:
    explicit usedVehicles(std::string  name);
    ~usedVehicles();
    void buy(MotorVehicle* vehicle);
    MotorVehicle* sellVehicle(int id, std::string newOwner);
    void printUsedVehicles() ;
    bool isValid() const { return !parking.empty(); }
    int getCount() { return parking.size(); };
    std::string getName() { return _name; };

};

#endif //SOCKOKAMILA_ETAP2_USEDVEHICLES_H
