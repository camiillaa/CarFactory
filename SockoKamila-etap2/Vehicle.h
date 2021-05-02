//
// Created by Home on 15.12.2020.
//

#ifndef SOCKOKAMILA_ETAP2_VEHICLE_H
#define SOCKOKAMILA_ETAP2_VEHICLE_H


#include <string>


class Vehicle {

protected:
    std::string  _brand;
    std::string _owner;
public:
    std::string  _color;
    std::string getBrand() const { return _brand; }
    void changeOwner(std::string& owner);
    Vehicle(std::string& brand, std::string& owner, std::string& color);
    Vehicle() = delete;
    virtual ~Vehicle();
    virtual int showCapacity() = 0;
    virtual void print() const = 0;
    virtual std::string whoamI() = 0;
};


#endif //SOCKOKAMILA_ETAP2_VEHICLE_H
