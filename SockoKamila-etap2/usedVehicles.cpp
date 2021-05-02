//
// Created by Home on 15.12.2020.
//

#include "usedVehicles.h"
#include "MotorCycle.h"

#include <utility>

usedVehicles::usedVehicles(std::string  name) : _name(std::move(name)) {
    this->parking = std::vector<MotorVehicle*>();
   parking.push_back(new Car("SKODA",_name, "czarny", 10, 5, 150000));
   parking.push_back(new MotorCycle("APRILLA",_name, "czarny", 8, 5000));



}
void usedVehicles::buy(MotorVehicle* vehicle){
    if(this->cashHoldings - vehicle->countPrice()-50000 > 0) {
        this->prCash = vehicle->countPrice()-50000;//odejmuje bo tyle zakladam ze spadlo na wartosci z przebiegu i uzytkowania
        this->cashHoldings -= prCash;
        if( vehicle->getBrand() == "AUDI" || vehicle->getBrand() == "OPEL") vehicle->changeMileage();//przebieg niektorych marek dzielony przez dwa
        vehicle->changeOwner(this->_name);

        parking.push_back(vehicle);
    } else std::cout <<"Komis nie ma tylu pieniedzy, samochod zostanie sprzedany prywatnej osobie\n";
}

MotorVehicle* usedVehicles::sellVehicle(int id, std::string newOwner){

    MotorVehicle *p = nullptr;
    for (int i = 0; i < parking.size(); ++i) {
        if(i == id) {
            p = parking[i];
            parking.erase(parking.begin() + i);
            break;
        }
    }
    p->changeOwner(newOwner);
    this->cashHoldings += (this->prCash + 5000);//cena skupu +marza
    return p;//zwracam sprzedany pojazd

}

void usedVehicles::printUsedVehicles() {
    std::cout << "\nPOKAZYWANIE KOMISU\n";
    if (!parking.empty()) {
        int i=0;
        std::cout << "KOMIS: " << std::endl;
        for (auto vehicle : parking) {
            std::cout<< i++ <<": "; vehicle->print();
        }

    } else std::cout << "Komis nie posiada zadnych pojazdow" << std::endl;
}

usedVehicles::~usedVehicles() {

    for (auto p : parking)
    {
        delete p;
    }
    parking.clear();
}
