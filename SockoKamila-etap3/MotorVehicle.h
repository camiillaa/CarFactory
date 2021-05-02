//
// Created by Home on 15.12.2020.
//

#ifndef SOCKOKAMILA_ETAP3_MOTORVEHICLE_H
#define SOCKOKAMILA_ETAP3_MOTORVEHICLE_H


#include "Vehicle.h"
#include "Sprayer.h"
#include <iostream>

class MotorVehicle : public Vehicle {

protected:

    int _mileage;
    double _fConsumption;//spalanie
    int _trunk;//bagaznik
    double _amountOfFuel;//obecna ilosc paliwa
    double _price;//cena

public:
    void go(int mileage);//funkcja pozwalajaca na przejazd pojazdem
    void changeMileage();//zmienia nam przebieg

    MotorVehicle(std::string &brand, std::string &owner, std::string &color, double fuel,
                 int mileage=0);
    virtual ~MotorVehicle() = default;//destruktor wirtualny
    virtual void print() const = 0;//wirtualna funkcja składowa

    int showCapacity() override { return _trunk; };//zaciera ślad po funkcji z klasy podstawowoej
    double countPrice() const;//liczy cene skupu
    std::string whoamI() override{
        return "MOTORVEHICLE";
    }
    static double check(int mileage);//przeładowanie nazw, mamy ten sam typ zwracany, inne typy argumentow,
    //static bo nie mamy wskaźnika this, niepracuje na niestetycznych składnikach klasy, wspólna funkcja dla wszystkch obiektów
    double check(double fuel) const;// stała po nie zmieniam żadnych wartości, tylko do odczytu
};

#endif //SOCKOKAMILA_ETAP3_MOTORVEHICLE_H
