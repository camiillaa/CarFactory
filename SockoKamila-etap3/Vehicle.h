//
// Created by Home on 15.12.2020.
//

#ifndef SOCKOKAMILA_ETAP3_VEHICLE_H
#define SOCKOKAMILA_ETAP3_VEHICLE_H


#include <string>


class Vehicle {

protected://znane dla klas dziedziczacych po Vehicle
    std::string  _brand;
    std::string _owner;
public:
    std::string  _color;//tu tez powinnam zrobic funkcje getColor i color zrobic protected
    std::string getBrand() const { return _brand; }
    void changeOwner(std::string& owner);//funkcja zmieniajaca wlasciciela na innego
    Vehicle(std::string& brand, std::string& owner, std::string& color);//konstruktor
    Vehicle() = delete;//mowimy kompilatorowi że nie chcemy, aby tworzył konstruktora domyślnego, nie potrzebuje go, bo nie będe tworzyc żadnego obiektu z tej klasy, a tylko po inej dziedziczyc
    virtual ~Vehicle();//destruktor wirtualny
    virtual int showCapacity() = 0;
    virtual void print() const = 0;
    virtual std::string whoamI() = 0;
};


#endif //SOCKOKAMILA_ETAP3_VEHICLE_H
