
#ifndef FABRYKA_SAMOCHODOW_SAMOCHOD_H
#define FABRYKA_SAMOCHODOW_SAMOCHOD_H

#include <iostream>
#include <string>

class Car{

    std::string _owner;
    std::string  _color;
    std::string  _brand; //zgodna z fabryka
    int _doors;
    int _mileage;
    int _id;

public:
    static int allCarsCount;//zmienna ktora pozwoli na zapis ilosci wszystkich samochodow w fabryce
    static Car* allCars[100];//wspolna dla wszystkich samochodow, statyczna tablica wskaznikow na obiekty typu Car majaca 100 elementow, inicjalizowana nullptr bo jest static
    Car(std::string& owner, const std::string& color, const std::string&  brand, int doors=0, int mileage=0);//konstruktor ma staly color i marke, wlasciciel moze sie zmieniac
    ~Car();
    void changeOwner(std::string& owner);
    void go( int mileage );
    void print() const;
    static void printAllCars();//dziala na statyczmych skladnikach, nie ma wskaznika this

};


#endif //FABRYKA_SAMOCHODOW_SAMOCHOD_H
