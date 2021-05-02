
#ifndef SOCKOKAMILA_ETAP2_FACTORY_H
#define SOCKOKAMILA_ETAP2_FACTORY_H
constexpr int FACTORY_size {20};
#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Sprayer.h"
#include "MotorVehicle.h"
#include <memory>
constexpr int defaultFuel = 50;
template <typename T>
class Factory {

    int _count;
    std::string _brand;
    T** _vehicles;//tablica wskaznikow wskazujacych na obiekty

public:
    explicit Factory(std::string   name, int count = 0);
    ~Factory();
    void createCar(std::string& color, int doors);
    void createMotorCycle(std::string& color);
    void createBike(std::string&color);
    Vehicle* sell(std::string owner, int num);
    void print() const;
    T* getVehicle(int position) { return _vehicles[position];}
    bool isValid() const { return _count; }//jest ok - fabryka
    int getCount() { return _count; };
    std::string getBrand() { return _brand; };


};

template<typename T>
Factory<T>::Factory(std::string name, int count) : _brand(std::move(name)), _count(count) {
    _vehicles = new T*[FACTORY_size];
}

template<typename T>
Factory<T>::~Factory() {

    for (int i = 0; i < _count; ++i) {
        delete _vehicles[i];//usuwam kazdy wsk w tablicy
    }
    delete [] _vehicles;//usuwam cala tablice wskaznikow
}

template<typename T>
void Factory<T>::createCar(std::string& color, int doors){

    _vehicles[_count++]= new T(_brand,_brand,color,defaultFuel, doors);


}

template<typename T>
void Factory<T>::createMotorCycle(std::string& color){

    _vehicles[_count++]= new T(_brand,_brand,color,defaultFuel);


}
template<typename T>
void Factory<T>::createBike(std::string &color) {

    _vehicles[_count++]= new T(_brand,_brand,color);
}

template<typename T>
void Factory<T>::print() const{

    std::cout << "\nPOKAZYWANIE FABRYKI\n";
    std::cout<< '|' << _brand << '|' << std::endl;
    if(_count>0) {
        for (int i = 0; i < _count; ++i) {
            std::cout << i << ":";
            _vehicles[i]->print();
        }
    }
    else std::cout<<"W fabryce nie ma jeszcze zadnych dostepnych pojazdow!" << std::endl;
}

template<typename T>
Vehicle* Factory<T>::sell(std::string owner, int num) {
    T* soldVehicle = _vehicles[num];//kopiuje wsk na dany poojazd
    soldVehicle->changeOwner(owner);//samochodowi o podanym indeksie chce zmienic wlasciciela
    for(int i=num; i< _count-1; i++)
        _vehicles[i] = _vehicles[i + 1];//przesuwam tablice, aby zlikwidować sprzedany samochod z fabryki i uporządkowac ją


    _count--;//po sprzedaniu zmniejsza się ilość samochodów w fabryce

  return soldVehicle;

}



#endif //SOCKOKAMILA_ETAP2_FACTORY_H