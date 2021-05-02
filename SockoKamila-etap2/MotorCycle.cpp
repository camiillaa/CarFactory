//
// Created by Home on 15.12.2020.
//

#include "MotorCycle.h"

MotorCycle::MotorCycle(std::string brand, std::string owner, std::string color, double fuel, int mileage)
        : MotorVehicle(brand, owner, color, fuel, mileage) {

}
void MotorCycle::print() const {
    std::cout << "Wlasciciel: " << _owner << " Kolor: " << _color << " Marka: " << _brand <<
             " Przebieg: " << _mileage <<"km" << " Ilosc paliwa: " << _amountOfFuel << " l" << std::endl;

}


