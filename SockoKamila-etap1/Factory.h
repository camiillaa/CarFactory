
#ifndef FABRYKA_SAMOCHODOW_FABRYKA_H
#define FABRYKA_SAMOCHODOW_FABRYKA_H

#include <iostream>
#include <string>
#include "Car.h"

constexpr int FACTORY_size {20};//max rozmiar tab

class Factory {

private:
    int _carCount;
    std::string _brand;
    Car* *_cars;//tablica wskaznikow wskazujacych na obiekty typu Car



public:
    explicit Factory(const std::string&  name, int count = 0);//Fabryka ma stala nazwe
    ~Factory();
    void createCar(std::string& color, int doors);
    void print() const;//wypisywanie na ekran
    void sell(std::string wlasciciel, int num); // usuwa samochod z fabryki z pozycji 'num' i zmienia wlasciciela wybranego samochodu
    Car* getCar(int position) { return _cars[position];}//zwraca wsk na wybrany samochod

};

#endif //FABRYKA_SAMOCHODOW_FABRYKA_H
