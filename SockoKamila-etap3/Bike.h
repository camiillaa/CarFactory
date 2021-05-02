//
// Created by Home on 15.12.2020.
//

#ifndef SOCKOKAMILA_ETAP3_BIKE_H
#define SOCKOKAMILA_ETAP3_BIKE_H


#include "Vehicle.h"
#include <iostream>

class Bike : public Vehicle {

        int _basket;//ładownosć koszyka
    public:
        Bike(std::string& brand, std::string& owner, std::string& color) : Vehicle(brand, owner, color){
            this->_basket = 10;//ladownosc koszyka 10kg
        };
        std::string whoamI() override{
          return "BIKE";
         }
        int showCapacity() override { return _basket; };//zaciera ślad po funkcji z klasy podsatwowej
        void print() const override ;//ta również

};


#endif //SOCKOKAMILA_ETAP3_BIKE_H
