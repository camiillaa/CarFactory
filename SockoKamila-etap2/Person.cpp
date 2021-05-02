//
// Created by Home on 18.12.2020.
//

#include "Person.h"
Person::Person(std::string name) : _name(std::move(name)){
    _v = std::vector<Vehicle*>();
    std::cout<<"---WITAJ " << _name << "---" << std::endl;
}
void Person::buy(Vehicle* v) {
    _v.push_back(v);

};
Vehicle* Person::sell(int num, std::string newOwner)
{
    Vehicle *p = nullptr;
    if(_v[num]->whoamI() == "MOTORVEHICLE") {//sprawdzam czy pojazdem ktory wybrano nie jest przypadkiem rower
        p = _v[num];
        _v.erase(_v.begin() + num);//usuwam pojazd z zadanej pozycji
        p->changeOwner(newOwner);
        return p;
    }
    else {
        fail f;
        f.message = " W komisie moga byc tylko pojazdy silnikowe";
        throw f;
    }
};

void Person::printVehicles() {
    std::cout << "\nPOJAZDY WLASCICIELA: " << std::endl;
    if (!_v.empty()) {
        int i = 0;
        for (auto vehicle : _v) {
            std::cout << i++ << ": ";
            vehicle->print();
        }

    } else std::cout << "Nie masz zadnych pojazdow" << std::endl;
}

Person::~Person() {

           for (auto p : _v)
        {
            delete p;
        }
        _v.clear();
}
