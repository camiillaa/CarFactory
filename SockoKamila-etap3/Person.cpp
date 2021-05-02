//
// Created by Home on 18.12.2020.
//

#include "Person.h"
#include "MotorVehicle.h"

Person::Person(std::string name) : _name(std::move(name)){
    _v = std::vector<Vehicle*>();//tworze pusty wektor wskaźników gdy tworzymy osobe
    std::cout<<"WITAJ " << _name << "!" << std::endl;
}
void Person::buy(Vehicle* v) {

    _v.push_back(v);//dodaje pojazd do wektora wskaźników
    if(v->whoamI() == "MOTORVEHICLE") {//jesli jest to pojazd silnikowy to musze zmienic mu przebieg, ponieważ osoba w trakcie
        //posiadania uzywala pojazdu silnikowego
        auto *p = dynamic_cast<MotorVehicle *>(v);
        p->go(100);//wlasciciel przejdzie tyle km dopoki nie bedzie chcial sprzedac pojazd
        std::cout << "W trakcie posiadania pojazdu przejechales 100 km" << std::endl;
    }

    std::cout << "Pojazd zostal kupiony przez Ciebie!" << std::endl;
    printVehicles();
}
Vehicle* Person::sell(int num, std::string newOwner)
{

    if( num >= 0 && num < _v.size() ) {
        Vehicle *p;
        if (_v[num]->whoamI() == "MOTORVEHICLE") {//sprawdzam czy pojazdem ktory wybrano nie jest przypadkiem rower
            p = _v[num];
            _v.erase(_v.begin() + num);//usuwam pojazd z zadanej pozycji
            p->changeOwner(newOwner);
            return p;
        } else {
            throw vehicleFail("Exception: Nie mozesz sprzedac pojazdu do komisu. W komisie moga byc tylko pojazdy silnikowe!");
        }
    }
    else {
       // incorrectPosition f;
        //f.message = "Niepoprawna pozycja zostala wprowadzona. Mozesz wybrac tylko opcje 0-" +std::to_string(_v.size() -1);
        throw incorrectPosition("Exception: Niepoprawna pozycja zostala wprowadzona. Mozesz wybrac tylko opcje 0-" +std::to_string(_v.size() -1));
    }
}

void Person::printVehicles() const{
    std::cout << "\nTWOJE POJAZDY: " << std::endl;
    if (!_v.empty()) {
        int i = 0;
        for (auto vehicle : _v) {
            std::cout << i++ << ": ";
            vehicle->print();
        }
    } else std::cout << "Nie masz zadnych pojazdow" << std::endl;
}

Person::~Person() {

           for (auto p : _v)//destruktor dealokuje pamieć którą zarezerwowaliśmy
        {
            delete p;
        }
        _v.clear();
}
bool Person::isValid() {
    if( !_v.empty() ) return !_v.empty();
    else {
       // ownerVehicleFail f;
       // f.message = "Nie mozna wykonac tej operacji na pojazdach wlasciciela.";
        throw ownerVehicleFail("Exception: Nie mozna wykonac tej operacji na pojazdach wlasciciela.");
    }
}
