
#include "Car.h"

Car::Car(std::string& owner, const std::string& color, const std::string& brand, int doors, int mileage) : _owner(
        owner), _color(color), _brand(brand), _doors(doors), _mileage(mileage) {
  // do statycznej tablicy wskaznikow na nasze samochody wkladam wsk na wyprodukowany samochod,
        // w indeks czyli id przypisuje ilosc samochodow (na poczatku 0) ktore bedzie zwiekszane w przyplywie nowych samochodow

        allCars[_id = allCarsCount++] = this;

}

Car::~Car() {

    allCars[_id] = nullptr;
}

void Car::go(int mileage) {
    if (_mileage < 0) {
        std::cout << "Mileage can't be lower than 0" << std::endl;
        return;
    }
    this->_mileage += mileage;//do przebiegu ktory poczatkowo byl 0 dodaje kilometry, gdy przejechalismy sie naszym samochodem
}

void Car::print() const {
    std::cout << "Wlasciciel: " << _owner << " Kolor: " << _color << " Marka: " << _brand << " Ilosc drzwi: " << _doors
              << " Przebieg: " << _mileage << std::endl;
}

void Car::changeOwner(std::string& owner) {
    this->_owner = owner;//zmieniam wlasciciela, przypisuje ownerowi nową wartosc
}

void Car::printAllCars() {
    if(allCarsCount>0) {
        for (auto car : allCars) {
             if(car) car->print();
        }
    }
    else std::cout<<"W fabryce nie wyprodukowano ani nie sprzedano zadnych samochodow!" << std::endl;

}

int Car::allCarsCount{0};//najpierw w fabryce nie ma samochodow
Car* Car::allCars[100];//jest inicjalizowana nullptr
