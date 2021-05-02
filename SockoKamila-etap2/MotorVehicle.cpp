//
// Created by Home on 15.12.2020.
//

#include "MotorVehicle.h"

void MotorVehicle::go(int mileage) {

    double fuel = this->_amountOfFuel -_fConsumption*mileage/100;
    if (mileage < 0) {
        std::cout << "Przebieg nie moze byc mniejszy od 0" << std::endl;
        return;
    } else if( fuel < 0 ) {
        std::cout<< "Brak paliwa, dostepne: " << _amountOfFuel << "litrow" << std::endl;
        return;
    }
    this->_mileage += mileage;//do przebiegu ktory poczatkowo byl 0 dodaje kilometry, gdy przejechalismy sie naszym samochodem
    this->_amountOfFuel -=_fConsumption*mileage/100;


}

void MotorVehicle::changeMileage() {
    this->_mileage = (_mileage+10000)/2;//+10000(zakladam ze tyle przejedzie wlasciciel)/2 bo komis zmieni licznik
}

MotorVehicle::MotorVehicle(std::string &brand, std::string &owner, std::string &color, double fuel,
                           int mileage) : Vehicle(brand,owner,color), _amountOfFuel(fuel), _mileage(mileage) {

    if(_brand == "FORD" || _brand == "AUDI" ) {
        this->_fConsumption = 16.7;
        this->_price = 100000;
        this->_trunk = 500;
    }
    else if(_brand == "OPEL") {
        this->_fConsumption = 10.7;
        this->_price = 90000;
        this->_trunk = 500;
    }
    else {
        this->_fConsumption = 4.0;//dla motocykli
        this->_price = 30000;
        this->_trunk = 150;
    }
}

double MotorVehicle::countPrice() const {
    return this->_price - _mileage*0.5;
}

