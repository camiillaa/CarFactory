//
// Created by Home on 15.12.2020.
//

#ifndef SOCKOKAMILA_ETAP2_BIKE_H
#define SOCKOKAMILA_ETAP2_BIKE_H


#include "Vehicle.h"
#include <iostream>

class Bike : public Vehicle {

        int _basket;
    public:
        Bike(std::string& brand, std::string& owner, std::string& color) : Vehicle(brand, owner, color){
            this->_basket = 10;//ladownosc koszyka 10kg
        };
        std::string whoamI() override{
          return "BIKE";
         }
        int showCapacity() override { return _basket; };
        void print() const override ;

};


#endif //SOCKOKAMILA_ETAP2_BIKE_H
