//
// Created by Home on 15.12.2020.
//

#include "Car.h"

Car::Car(std::string brand, std::string owner, std::string color, double fuel, int doors,  int mileage)
        : MotorVehicle(brand, owner,color, fuel, mileage), _doors(doors){
}

void Car::print() const {
    std::cout << "Wlasciciel: " << _owner << " Kolor: " << _color << " Marka: " << _brand << " Ilosc drzwi: " << _doors
              << " Przebieg: " << _mileage << "km" << " Ilosc paliwa: " << _amountOfFuel << "l" << std::endl;

}
