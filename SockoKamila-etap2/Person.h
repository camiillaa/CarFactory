//
// Created by Home on 18.12.2020.
//

#ifndef SOCKOKAMILA_ETAP2_PERSON_H
#define SOCKOKAMILA_ETAP2_PERSON_H


#include <vector>
#include <iostream>
#include "Vehicle.h"
struct fail {
    std::string message;
};

class Person {//osoba kupujaca z fabryki i sprzedajaca pozniej go do komisu

    std::string _name;
    std::vector<Vehicle*> _v;
public:
    explicit Person(std::string name);
    ~Person();
    void buy(Vehicle* v);
    bool isValid() { return !_v.empty();}
    Vehicle* sell(int num, std::string newOwner);
    void printVehicles();
    int getCount() { return _v.size(); };
    std::string getName() { return _name;}
};


#endif //SOCKOKAMILA_ETAP2_PERSON_H
