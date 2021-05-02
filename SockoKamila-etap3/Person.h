//
// Created by Home on 18.12.2020.
//

#ifndef SOCKOKAMILA_ETAP3_PERSON_H
#define SOCKOKAMILA_ETAP3_PERSON_H


#include <vector>
#include <iostream>
#include "Vehicle.h"
#include "helperForFail.h"

class Person {//osoba kupujaca z fabryki i sprzedajaca go pozniej

    std::string _name;
    std::vector<Vehicle*> _v;//wektor wskaźników na pojazdy silnikowe
public:
    explicit Person(std::string name);
    ~Person();
    void buy(Vehicle* v);
    bool isValid();//sprawdza czy osoba ma jakies pojazdy
    Vehicle* sell(int num, std::string newOwner);
    void printVehicles() const;
    std::string getName() { return _name;}
};


#endif //SOCKOKAMILA_ETAP3_PERSON_H
