//
// Created by Home on 15.12.2020.
//

#ifndef SOCKOKAMILA_ETAP3_USEDVEHICLES_H
#define SOCKOKAMILA_ETAP3_USEDVEHICLES_H

#include <string>
#include "MotorVehicle.h"
#include <vector>
#include <memory>
#include "Car.h"

class usedVehicles {

   std::vector<MotorVehicle*> parking;

    double cashHoldings = 200000;//zasoby komisu
    double prCash=20000;//domyslna cena dla samochodow juz bedacych w komisie przed interakcja z wlasicielem samochodow z fabryki
    std::string _name;

public:
    explicit usedVehicles(std::string  name);
    ~usedVehicles();
    void buy(MotorVehicle* vehicle);
    MotorVehicle* sellVehicle(int id, std::string newOwner);
    void printUsedVehicles() const;
    bool isValid() const;
    std::string getName() { return _name; };
    int checkPosition(int num);
};

#endif //SOCKOKAMILA_ETAP2_USEDVEHICLES_H
