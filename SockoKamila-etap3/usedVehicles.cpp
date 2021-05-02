//
// Created by Home on 15.12.2020.
//

#include "usedVehicles.h"
#include <utility>
#include <iomanip>
#include <cmath>
usedVehicles::usedVehicles(std::string  name) : _name(std::move(name)) {
    this->parking = std::vector<MotorVehicle*>();
   parking.push_back(new Car("SKODA",_name, "czarny", 10, 5, 150000));
   parking.push_back(new Car("HYUNDAI",_name, "zolty", 9, 5, 4000));

}
void usedVehicles::buy(MotorVehicle* vehicle){

    std::cout << "Komis moze zakupic pojazdy w lacznej kwocie: " << cashHoldings << " zl" << std::endl;
    if(this->cashHoldings - vehicle->countPrice()> 0) { //jesli wystarczy pieniedzy to kup
        this->prCash = vehicle->countPrice();//cena skupu pojazdu
        std::cout << "Cena pojazdu to: " << prCash << " zl" << std::endl;
        std::cout << "Poprzedni wlasciciel przejechal " << 100 << " km\n";
        this->cashHoldings -= prCash;//od dochodow odejmuje cene skupu
        if( vehicle->getBrand() == "FORD" || vehicle->getBrand() == "OPEL") {
            vehicle->changeMileage();//przebieg niektorych marek dzielony przez dwa
            std::cout << "Ze wzgledu, ze marka pojazdu to " << vehicle->getBrand() << " przebieg zostal zmniejszony dwukrotnie" << std::endl;
        }
        vehicle->changeOwner(this->_name);
        parking.push_back(vehicle);
        std::cout << "Pojazd zostal kupiony!" << std::endl;
        std::cout << "Obecne dochody komisu wynosza: " << this->cashHoldings << " zl" << std::endl;
        printUsedVehicles();
    } else {
        std::cout << "Cena pojazdu to: " << vehicle->countPrice() << " zl" <<std::endl;
        std::cout <<"Komis nie ma tylu pieniedzy, dochody komisu wynosza: " << cashHoldings <<  " zl, samochod zostanie sprzedany prywatnej osobie\n";
    }
}

MotorVehicle* usedVehicles::sellVehicle(int id, std::string newOwner){

        std::cout<<"Obecne dochody komisu przed sprzedaza to: " << cashHoldings << "zl" << std::endl;
        MotorVehicle *p = nullptr;
        for (int i = 0; i < parking.size(); ++i) {
            if(i == id) {
                p = parking[i];
                parking.erase(parking.begin() + i);
                break;
            }
        }
        p->changeOwner(newOwner);
        this->cashHoldings += (this->prCash+5000);//do dochodow komisu dodaje cene skupu +marza
        std::cout << "Cena pojazdu: " << this->prCash<< " zl" << std::endl;
        std::cout << "Cena skupu samochodu z marza: " << this->prCash +5000<< " zl" << std::endl;
        std::cout << "Pojazd sprzedano z komisu!" << std::endl;
        std::cout<<"Obecne dochody komisu po sprzedazy to: " << cashHoldings << "zl" << std::endl;
        printUsedVehicles();
        return p;//zwracam sprzedany pojazd


}

void usedVehicles::printUsedVehicles() const {
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

int usedVehicles::checkPosition(int num) {
    if( num >= 0 && num < parking.size() ) {
       return 1;
    }
    else {
        //incorrectPosition f;
        //f.message = "Niepoprawna pozycja zostala wprowadzona. Mozesz wybrac tylko opcje 0-" +std::to_string(parking.size() -1);
        throw incorrectPosition("Exception: Niepoprawna pozycja zostala wprowadzona. Mozesz wybrac tylko opcje 0-" +std::to_string(parking.size() -1));
    }
}

bool usedVehicles::isValid() const {
    if (!parking.empty()) return !parking.empty();
    else {
        throw usedVehiclesFail("Exception: Komis jest pusty.");
    }
}


