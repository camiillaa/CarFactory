#include "Factory.h"


void produceCar(Factory *fabryka);
void sellCar(Factory *fabryka);
void goBycar(Factory *fabryka);
int readInt();
std::string readString();

int main() {

    Factory fabryka("FORD"); //Tworzę fabryke o nazwie FORD - wykonanie konstruktora Factory(const std::string&  name, int count = 0),
    // w ciele konstruktora zostanie stworzona tablica wskaźników na obiekty klasy Samochod


    int choice;
    do {
        std::cout << "\n---CO CHCESZ WYBRAC?---\n"
                     "0: Przerwij dzialanie programu\n"
                     "1: Wyprodukuj samochod\n" // produkuje samochod w danej fabryce
                     "2: Sprzedaj samochod\n" // sprzedajemy samochod
                     "3: Jedz! - zwieksz przebieg\n" // jedziemy, zwiekszamy przebieg samochoddu
                     "4: Pokaz fabryke\n"//Pokazuje dostepne samochody
                     "5: Pokaz wszystkie samochody w rejestrze\n";//Pokazujemy wszystkie samochody jakie dotąd wyprodukowaliśmy i sprzedaliśmy


        choice = readInt();

        switch (choice) {
            case 0:
                break;
            case 1:
                //stworz samochod
                produceCar(&fabryka);
                break;
            case 2:
                //sprzedaj samochod
                sellCar(&fabryka);
                break;
            case 3:
                //przejedz sie
                goBycar(&fabryka);
                break;
            case 4:
                //pokaz wszystkie samochody w fabryce
                fabryka.print();
                break;
            case 5:
                //pokaz wszystkie samochody z rejestru(te ktore zostaly i sprzedane)
                Car::printAllCars();
                break;

            default:
                std::cout << "Dozwolone opcje od 0-5" << std::endl;
        }

    } while (choice > 0);


    return 0;
}

void produceCar(Factory *fabryka){
    std::cout << "Jakiego koloru chcialbys samochod?"<<std::endl;
    std::string color = readString();
    std::cout<<"Ile drzwi ma miec samochod?"<<std::endl;
    int countDoors = readInt();
    if(countDoors<3) {
        std::cout <<"Ilosc drzwi w samochodzie musi byc wieksza niz 3";
        return;
    }
    fabryka->createCar(color,countDoors);//tworze nowy samochod
}
void sellCar(Factory *fabryka) {
    std::cout << "Wybierz samochod, ktory chcesz sprzedac?" << std::endl;
    fabryka->print();//wypisuje samochody jakie są dostępne
    int choice = readInt();

    std::cout<<"Kto bedzie nowym wlascicielem?"<<std::endl;
    std::string newOwner = readString();
    fabryka->sell(newOwner, choice);//sprzedaje wybrany samochod
}

void goBycar(Factory *fabryka) {
    std::cout << "Wybierz samochod, ktorym chcesz sie przejechac?" << std::endl;
    fabryka->print();
    int num = readInt();
    std::cout<<"Ile km chcesz przejechac?"<<std::endl;
    int ile = readInt();
    fabryka->getCar(num)->go(ile);//chce zmienic przebieg jednego z wybranych samochodow, dzieki funkcji getCar dostane wybrany samochod i zmieniam jego przebieg funkcją go
}


int readInt() {
    std::string line;
    std::getline(std::cin, line);
    return atoi(line.c_str());
}

std::string readString() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}
