//
// Created by Home on 15.12.2020.
//

#include "MotorVehicle.h"

void MotorVehicle::go(int mileage) {
    try {
        check(mileage);//sprawdzam czy przebieg jest odpowiednią wartością
        try {
            double fuel = this->_amountOfFuel - _fConsumption * mileage / 100;//liczę ilość paliwa, po przejechaniu jakiejś ilości kilometrów
            check(fuel);//sprawdzam czy mamy wystarczajacą ilość paliwa, jesli nie to rzucany jest wyjątek
            this->_mileage += mileage;//do przebiegu ktory poczatkowo byl 0 dodaje kilometry, gdy przejechalismy sie naszym pojazdem
            this->_amountOfFuel -=_fConsumption*mileage/100;//zmieniam ilość paliwa
        }
        catch(vehicleFail& p )
        {
            std::cout << p.message <<std::endl;
        }
    }
    catch(vehicleFail& p )
    {
        std::cout << p.message <<std::endl;
    }
}
void MotorVehicle::changeMileage() {
    this->_mileage = (_mileage)/2;//funkcja ktora zmienia licznik przy sprzedaży do komisu
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
        this->_fConsumption = 4.0;//dla motocykli/ tez dla pojazdów będącyh w komisie
        this->_price = 20000;
        this->_trunk = 150;
    }
}
double MotorVehicle::countPrice() const {
    return (this->_price - _mileage*2);//cena skupu jest funkcja zalezna od marki oraz przebiegu, u mnie funkcja wyglada wlasnie tak ze od ceny danego pojazdu
    // odejmowany jest przebieg mnozony razy 2
}

double MotorVehicle::check(int var){

    if(var>0) return 1;
    else {
        throw vehicleFail("Exception: Przebieg nie moze byc mniejszy od 0");
    }
}
double MotorVehicle::check(double fuel) const {

    if(fuel>0) return 1;
    else {
        throw vehicleFail("Exception: Brak paliwa, dostepne: "+std::to_string(_amountOfFuel)+ "l");
    }
}
