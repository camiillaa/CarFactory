
#ifndef SOCKOKAMILA_ETAP3_FACTORY_H
#define SOCKOKAMILA_ETAP3_FACTORY_H
constexpr int FACTORY_size {20};
#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Sprayer.h"
#include "MotorVehicle.h"
#include "helperForFail.h"
#include <memory>
constexpr int defaultFuel = 50;
template <typename T>
class Factory {

    int _count;//ilosc pojazdow
    std::string _brand;//marka
    T** _vehicles;//tablica wskaznikow wskazujacych na obiekty

public:
    explicit Factory(std::string   name, int count = 0);//konstruktor o wywołaniu jawnym, z arg domyślnym count =0, bo na początku ilosc pojazdow w fabryce to 0
    ~Factory();
    void createCar(std::string& color, int doors);
    void createMotorCycle(std::string& color);
    void createBike(std::string&color);
    Vehicle* sell(std::string owner, int num);//sprzedawanie pojazdu
    void print() const;
    T* getVehicle(int position);//zwraca wskaznik do wybranego pojazdu
    bool isValid() const; //jest ok - fabryka
    std::string getBrand() { return _brand; };//funkcja odnoszaca sie do prywatnego skladnika klasy


};
template<typename T>
T* Factory<T>::getVehicle(int position) {
    if( position >= 0 && position < _count )
     return _vehicles[position];
    else
    {
        throw incorrectPosition("Exception: Niepoprawna pozycja zostala wprowadzona. Mozesz wybrac tylko opcje 0-" +std::to_string(_count -1));
    }
}
template<typename T>
bool Factory<T>::isValid() const{//stala bo nie modyfikuje skladnikow, funkcja sprawdzajaca czy w fabryce są pojazdy czy nie

    if( _count ) return _count;
    else {
    throw factoryFail( "Exception: Nie mozna wykonac tej operacji na fabryce.");
    }
}
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
    if (doors== 3 || doors== 5) {
        _vehicles[_count++]= new T(_brand,_brand,color,defaultFuel, doors);//tworze obiekt Car i definuje do niego wskaźnik
    }
    else {
       throw vehicleFail("Exception: Ilosc drzwi w samochodzie musi byc rowna 3 lub 5");
    }
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
    else std::cout<<"PUSTA FABRYKA!" << std::endl;
}

template<typename T>
Vehicle* Factory<T>::sell(std::string owner, int num) {
    if( num >= 0 && num < _count ) {//jesli wybrana pozycja jest prawidlowa
        T *soldVehicle = _vehicles[num];//kopiuje wsk na dany poojazd
        soldVehicle->changeOwner(owner);//samochodowi o podanym indeksie chce zmienic wlasciciela
        for (int i = num; i < _count - 1; i++)
            _vehicles[i] = _vehicles[i +
                                     1];//przesuwam tablice, aby zlikwidować sprzedany samochod z fabryki i uporządkowac ją
                                     //trace adres obiektu _vehicles[num]


        _count--;//po sprzedaniu zmniejsza się ilość samochodów w fabryce

        return soldVehicle;
    }
    else
    {
        throw incorrectPosition("Exception: Niepoprawna pozycja zostala wprowadzona. Mozesz wybrac tylko opcje 0-" +std::to_string(_count -1));
    }

}



#endif //SOCKOKAMILA_ETAP3_FACTORY_H