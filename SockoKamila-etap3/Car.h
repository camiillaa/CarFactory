//
// Created by Home on 15.12.2020.
//

#ifndef SOCKOKAMILA_ETAP3_CAR_H
#define SOCKOKAMILA_ETAP3_CAR_H


#include "MotorVehicle.h"

class Car : public MotorVehicle {

    int _doors{};//drzwi na początku inicjalizuje na 0
public:
    explicit Car(std::string brand, std::string owner,  std::string color, double fuel, int doors, int mileage=0);//
    //explicit aby nie bylo żadnych niejawnych konwersji
    //przesyłam przez wartosc, jest robiona kopia-przydaje sie przy komisie, w którym tworze obiekty o danych wartościach
    ~Car() override = default;//zaciera ślad po destruktorze z klasy MotorVehicle i Vehicle
    void print() const override;//ta też zaciera, funkcja wirtualna
};


#endif //SOCKOKAMILA_ETAP3_CAR_H
