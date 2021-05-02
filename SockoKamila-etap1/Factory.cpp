#include "Factory.h"

Factory::Factory(const std::string&  name, int count) : _carCount(count),_brand(name){
    //Cars* *_cars;//tablica wskaznikow wskazujacych na obiekty typu Car
    _cars=new Car*[FACTORY_size];//tworze dynamiczną tablice wskaźników na obiekt typu Car* o wielkości FACTORY_size
}
Factory::~Factory(){
    for (int i = 0; i < _carCount; ++i) {
        delete _cars[i];//usuwam kazdy wsk w tablicy
    }
    delete [] _cars;//usuwam cala tablice wskaznikow
}


void Factory::createCar(std::string& color, int doors){

    _cars[_carCount++]= new Car(_brand,color,_brand,doors);//carCount =0 na początku, posłuzy mi jako indeks tablicy //new zwraca wskaznik na wartosc wiec do kazdego elementu tablicy, bede po kolei wkladac nowy wsk wskazujacy na stworzony samochod
    //do mojej tablicy wskaznikow wkladam nowo stworzony obiekt na pozycje cars[0](przy pierwszej produkcji), nastepnie w cars[1] itd (konstruktorem  Car(std::string& owner, const std::string& color, const std::string&  brand, int doors=0, int mileage=0)
    //Na poczatku brand i owner ustawiani są na FORD czyli naszą fabryke
    //mileage domyslnie 0

}
void Factory::print() const {
    std::cout<< '|' << _brand << '|' << std::endl;
    if(_carCount>0) {
        for (int i = 0; i < _carCount; ++i) {
            std::cout << i << ":";
            _cars[i]->print();
        }
    }
    else std::cout<<"W fabryce nie ma jeszcze zadnych dostepnych samochodow!" << std::endl;
}

void Factory::sell(std::string wlasciciel, int num){
    _cars[num]->changeOwner(wlasciciel);//samochodowi o podanym indeksie chce zmienic wlasciciela

    for(int i=num; i< _carCount-1; i++)
        _cars[i] = _cars[i + 1];//przesuwam tablice, aby zlikwidować sprzedany samochod z fabryki(zostanie w tablicy stworzonej do rejestru) i uporządkowac ją


    _carCount--;//po sprzedaniu zmniejsza się ilość samochodów w fabryce

}