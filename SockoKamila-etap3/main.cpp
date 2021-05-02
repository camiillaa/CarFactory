#include "Factory.h"
#include "Car.h"
#include "Bike.h"
#include "MotorCycle.h"
#include "usedVehicles.h"
#include "Person.h"

std::string selectColor();
template <typename T>
void produceCar(Factory<T> *fabryka);
template <typename T>
void produceMotorCycle(Factory<T> *fabryka);
template <typename T>
void produceBike(Factory<T> *fabryka);
template <typename T>
void goByMotorVehicle(Factory<T> *fabryka);
template <typename T>
void showCap(Factory<T> * fabryka);
template <typename T>
void  buyFromFactory(Factory<T> *fabryka, Person* p);
void sellToUsedVehicles(usedVehicles * komis, Person* p);
void sellFromUsedVehicles(usedVehicles* komis, Person *p);
int readInt();
std::string readString();
std::string chooseBrandOfBikeFactory();
std::string chooseBrandOfCarFactory();
std::string chooseBrandOfMotorCycleFactory();
template <typename T>
void changeColorOfVehicle(Factory<T> *fabryka);
#include <fstream>
bool fileOpen = false;

int main( int argc, char *argv[]) {

    std::ifstream in;
    if(argc==2) {//nazwa programu nazwa pliku
        in.open(argv[1]);//otworz plik
        std::cin.rdbuf(in.rdbuf());//in.rdbuf() zwraca wskaznik do poczatku bufora danych z pliku i wczytanie ich ze standardowego wyjścia
        fileOpen = true;
    }

    std::cout<<"----------------JAK MASZ NA IMIE?----------------\n";
   std::string yourName = readString();
   Person person(yourName);
   std::cout << "\n-----------------TWORZENIE FABRYK----------------\n";
   std::string name1 = chooseBrandOfBikeFactory();
   Factory<Bike> fBike(name1);
   std::string name2 = chooseBrandOfCarFactory();
   Factory<Car> fCar(name2);
   std::string name3 = chooseBrandOfMotorCycleFactory();
   Factory<MotorCycle> fMotorCycle(name3);
   usedVehicles VEHICLES("KOMIS");


    int choice2;
    do {
        std::cout<< "\n-------------------------------------------------\n";
        std::cout << "\n----------------CO CHCESZ WYBRAC?----------------\n"

                     "\n-------------FABRYKA SAMOCHODOW " << name2 <<  "-------------\n"
                     "1: Wyprodukuj Samochod\n"
                     "2: Jedz samochodem\n"
                     "3: Zmien kolor samochodu: \n"
                     "4: Kup samochod z fabryki:\n"
                     "5: Pokaz ladownosc wybranego samochodu:\n"
                     "6: Pokaz fabryke Samochodow\n"

                     "\n-------------FABRYKA MOTOCYKLI " << name3 <<  "------------\n"
                     "7: Wyprodukuj Motocykl\n"
                     "8: Jedz motocyklem\n"
                     "9: Zmien kolor motocykla:\n"
                     "10: Kup motocykl z fabryki:\n"
                     "11: Pokaz ladownosc wybranego motocyklu:\n"
                     "12: Pokaz fabryke Motocyklow\n"

                     "\n--------------FABRYKA ROWEROW " << name1 << "--------------\n"
                     "13: Wyprodukuj Rower\n"
                     "14: Zmien kolor roweru: \n"
                     "15: Pokaz ladownosc roweru: \n"
                     "16: Kup rower z fabryki:\n"
                     "17: Pokaz fabryke Rowerow\n"

                     "\n----------------------KOMIS----------------------\n"
                     "18: Pokaz komis: \n"
                     "19: Sprzedaj pojazd do komisu: \n"
                     "20: Sprzedaj pojazd z komisu: \n"

                     "21: POKAZ MOJE POJAZDY: \n"

                     "22: Wyjdz z programu\n";

        std::cout<< "\n-------------------------------------------------\n";
        choice2 = readInt();

        switch (choice2) {
            case 1: produceCar(&fCar);                        break;
            case 2: goByMotorVehicle(&fCar);                  break;
            case 3: changeColorOfVehicle(&fCar);              break;
            case 4: buyFromFactory(&fCar, &person);           break;
            case 5: showCap(&fCar);                           break;
            case 6: fCar.print();                             break;
            case 7: produceMotorCycle(&fMotorCycle);          break;
            case 8: goByMotorVehicle(&fMotorCycle);           break;
            case 9: changeColorOfVehicle(&fMotorCycle);       break;
            case 10: buyFromFactory(&fMotorCycle, &person);   break;
            case 11: showCap(&fMotorCycle);                   break;
            case 12: fMotorCycle.print();                     break;
            case 13: produceBike(&fBike);                     break;
            case 14: changeColorOfVehicle(&fBike);            break;
            case 15: showCap(&fBike);                         break;
            case 16: buyFromFactory(&fBike, &person);         break;
            case 17: fBike.print();                           break;
            case 18: VEHICLES.printUsedVehicles();            break;
            case 19: sellToUsedVehicles(&VEHICLES, &person);  break;
            case 20: sellFromUsedVehicles(&VEHICLES, &person);break;
            case 21: person.printVehicles();                  break;
            case 22: return 0;
            default: {
                std::cout << "Wpisales: " << choice2 <<std::endl;
                std::cout << "Dozwolone opcje od 1-22" << std::endl;
            }
        }

    } while (choice2 > 0);


    return 0;
}
std::string chooseBrandOfBikeFactory(){


    int choice;
    std::string result;
    do {
        std::cout << "\n--------------WYBIERZ MARKE FABRYKI--------------\n"
                     "-----------------FABRYKA ROWEROW-----------------\n"
                     "1: ROMET\n"
                     "2: SCOTT\n";
        choice = readInt();
        switch (choice) {
            case 1:
                result ="ROMET";
                break;
            case 2:
                result = "SCOTT";
                break;
            default: {
                std::cout << "Wpisales: " << choice <<std::endl;
                std::cout << "Dozwolone opcje od 1-2" << std::endl;
            }
        }
    }while(choice>2 || choice<1 );
    std::cout<< "Wybrana marka rowerow to: " << result << std::endl;
    return result;

}
std::string chooseBrandOfCarFactory(){

    int choice;
    std::string result;
    do {
      std::cout << "-----------------FABRYKA SAMOCHODOW--------------\n"
                     "1: AUDI\n"
                     "2: FORD\n"
                     "3: OPEL\n";
        choice = readInt();
        switch(choice) {
            case 1:
                result = "AUDI";
                break;
            case 2:
                result = "FORD";
                break;
            case 3:
                result = "OPEL";
                break;
            default: {
                std::cout << "Wpisales: " << choice <<std::endl;
                std::cout << "Dozwolone opcje od 1-3" << std::endl;
            }
        }


    } while(choice>3 || choice < 1);
    std::cout<< "Wybrana marka samochodow to: " << result << std::endl;
    return result;


}
std::string chooseBrandOfMotorCycleFactory(){

    int choice;
    std::string result;
    do {
        std::cout << "-----------------FABRYKA MOTOCYKLI---------------\n"
                     "1: SUZUKI\n"
                     "2: YAMAHA\n";
        choice = readInt();
        switch(choice) {
            case 1:
                result =  "SUZUKI";
                break;
            case 2:
                result =  "YAMAHA";
                break;
            default:
                std::cout << "Wpisales: " << choice <<std::endl;
                std::cout << "Dozwolone opcje od 1-2" << std::endl;


        }
    } while(choice>2||choice<1);
    std::cout<< "Wybrana marka motocykli: " << result << std::endl;
    return result;

}
std::string selectColor() {


    int choice;
    std::string result;
    do {
        std::cout << "\n------------JAKI CHCESZ KOLOR POJAZDU?-----------\n"
                     "1: rozowy\n"
                     "2: zielony\n"
                     "3: niebieski\n";
        choice = readInt();
        switch (choice) {
            case 1:
                result = "rozowy";
                break;
            case 2:
                result = "zielony";
                break;
            case 3:
                result=  "niebieski";
                break;

            default:
                std::cout << "Wybrana opcja to: " << choice << std::endl;
                std::cout << "Dozwolone opcje 1-3" << std::endl;
                break;

        }

    } while(choice < 1 || choice >3);
    std::cout<< "Wybrany kolor to: " << result << std::endl;
    return result;
}
template <typename T>
void showCap(Factory<T> * fabryka){

    std::cout<< "\nLADOWNOSC POJAZDU MARKI - "<< fabryka->getBrand() << std::endl;
    std::cout<<"Ktorego pojazdu ladownosc chcesz zobaczyc?\n";
    fabryka->print();
    try {
        fabryka->isValid();
        int choice = readInt();
        std::cout << "Wybrales pojazd o indeksie " << choice << std::endl;
        try {
            Vehicle* v = fabryka->getVehicle(choice);//uzyskuje wskaźnik na wybrany pojazd, dzieki polimorizmowi wiem na jaki typ wskazuje wskaźnik
            //czy na samochod, rower, czy motocykl
            std::cout<<"Ladownosc wynosi: " << v->showCapacity()<< "kg" << std::endl;
        }
        catch(incorrectPosition& f) {
            std::cout << f.message << std::endl;
        }
    }
    catch(factoryFail& f)
    {
        std::cout << f.message << std::endl;
    }
}

template <typename T>
void produceCar(Factory<T> *fabryka){

    std::cout<< "\nPRODUKCJA SAMOCHODU MARKI - "<< fabryka->getBrand();
    std::string color = selectColor();
    std::cout << "Ile drzwi ma miec samochod? Mozesz wybrac 3 lub 5" << std::endl;
    int countDoors = readInt();
    std::cout<< "Twoj wybor to: " << countDoors << std::endl;
    try {
        fabryka->createCar(color, countDoors);//tworze nowy samochod
    }
    catch(vehicleFail& f) {
        std::cout<<f.message <<std::endl;
    }
}
template <typename T>
void produceMotorCycle(Factory<T> *fabryka){

    std::cout<< "\nPRODUKCJA MOTOCYKLU MARKI - "<< fabryka->getBrand();
    std::string color = selectColor();
    fabryka->createMotorCycle(color);//tworze nowy motocykl
}
template <typename T>
void produceBike(Factory<T> *fabryka){

    std::cout<< "\nPRODUKCJA ROWEROW MARKI - "<< fabryka->getBrand();
    std::string color = selectColor();
    fabryka->createBike(color);//tworze nowy rower
}

template <typename T>
void buyFromFactory(Factory<T> *fabryka, Person* p) {

    std::cout<< "\nKUPOWANIE POJAZDU MARKI - "<< fabryka->getBrand() << std::endl;
    std::cout << "Wybierz pojazd, ktory chcesz kupic?" << std::endl;
    fabryka->print();//wypisuje samochody jakie są dostępne
    try {
        fabryka->isValid();
        int choice = readInt();
        std::cout << "Wybrales pojazd o indeksie " << choice << std::endl;
        try {
            Vehicle* toSell = fabryka->sell(p->getName(), choice);//(nowy wlasciciel, ktory samochod), usuwa z fabryki i zmienia wlasciciela
            //wskaznik wie na jaki typ wskazuje czy motocykl czy rower czy samochod
            p->buy(toSell);//kupuje
            return;

        }
        catch (incorrectPosition& f)
        {
            std::cout << f.message << std::endl;
        }
    }
    catch (factoryFail& f)
    {
        std::cout << f.message << std::endl;
    }
}

template <typename T>
void goByMotorVehicle(Factory<T> *fabryka) {

    std::cout<< "\nJAZDA POJAZDEM MARKI - "<< fabryka->getBrand() << std::endl;
    std::cout << "Wybierz pojazd, ktorym chcesz sie przejechac?" << std::endl;
    fabryka->print();
    try {
        fabryka->isValid();
        int num = readInt();
        std::cout << "Wybrales pojazd o indeksie " << num << std::endl;
            try {
                fabryka->getVehicle(num);//aby zlapalo wczesniej wyjatek bez zbednego wypisywania informacji dalszej
                std::cout << "Ile km chcesz przejechac?" << std::endl;
                int ile = readInt();
                std::cout << "Ilosc km: " << ile << std::endl;
                MotorVehicle *p = fabryka->getVehicle(num);
                p->go(ile);
                fabryka->print();
            }
            catch (incorrectPosition& f)
            {
                std::cout << f.message << std::endl;
            }
    }
    catch (factoryFail& f)
    {
        std::cout << f.message << std::endl;
    }


}
template <typename T>
void changeColorOfVehicle(Factory<T> *fabryka) {

    std::cout<< "\nZMIANA KOLORU POJAZDU MARKI - "<< fabryka->getBrand() << std::endl;
    std::cout << "Wybierz pojazd, ktoremu chcesz zmienic kolor?" << std::endl;
    fabryka->print();
    try {
        fabryka->isValid();
        int num = readInt();
        std::cout << "Wybrales pojazd o indeksie " << num << std::endl;
        try {
            std::string newColor = selectColor();
            Vehicle* p = fabryka->getVehicle(num);
            Sprayer::changeColor(p,newColor);
            fabryka->print();
        }
        catch (incorrectPosition& f)
        {
            std::cout << f.message << std::endl;
        }
    }
    catch (factoryFail& f)
    {
        std::cout << f.message << std::endl;
    }

}


void sellToUsedVehicles(usedVehicles* komis, Person* p){

    std::cout<< "\nSPRZEDAWANIE POJAZDU DO KOMISU "<< std::endl;
    p->printVehicles();
    try {
        p->isValid();
        std::cout << "Wybierz pojazd, ktory chcesz sprzedac?" << std::endl;
        int num = readInt();
        std::cout << "Wybrales pojazd o indeksie " << num << std::endl;
        try {
                auto *toSell = dynamic_cast<MotorVehicle *>(p->sell(num,
                                                                    komis->getName()));//sprzedaje i zmieniam wlasciciela na komis
                                                                    //rzutuje pojazd na pojazd silnikowy
                komis->buy(toSell);//kupowanie przez komis
            }
        catch(vehicleFail& x) {//jesli wybrany pojazd to pojazd niesilnikowy
            std::cout << x.message << std::endl;
        }
        catch(incorrectPosition& x) {
            std::cout << x.message << std::endl;
        }
    }
    catch (ownerVehicleFail& f)
    {
        std::cout << f.message << std::endl;
    }
}

void sellFromUsedVehicles(usedVehicles* komis, Person* p){

    std::cout<< "\nSPRZEDAWANIE POJAZDU Z KOMISU "<< std::endl;
    std::cout << "Wybierz pojazd, ktory chcesz sprzedac?" << std::endl;
    komis->printUsedVehicles();
    try {
        komis->isValid();
        int choice = readInt();
        std::cout << "Wybrales pojazd o indeksie " << choice << std::endl;
       try {
           komis->checkPosition(choice);
           std::cout << "Czy ty chcesz byc nowym wlascicielem?" << std::endl;
           std::cout << "Jesli tak wcisnij 1, jesli nie - wcisnij dowolny klawisz" << std::endl;
           int check = readInt();
           if (check == 1) {
               p->buy(komis->sellVehicle(choice, p->getName()));
               return;
           }
           std::cout << "Kto bedzie nowym wlascicielem?" << std::endl;
           std::string newOwner = readString();
           std::cout << "Nowym wlascicielem bedzie: " << newOwner << std::endl;
           komis->sellVehicle(choice, newOwner);
       }
       catch (incorrectPosition& f)
       {
           std::cout << f.message << std::endl;
       }
    }
    catch (usedVehiclesFail& f)
    {
        std::cout << f.message << std::endl;
    }
}

int readInt() {
    std::string line;
    if(fileOpen) {
        std::getline(std::cin, line);
        if (line[line.size() - 1] == '\r') line.resize(line.size() - 1);
    }
    else std::getline(std::cin, line);
    return std::strtol(line.c_str(), nullptr, 10);//konwertuje tekst na liczbe w systeimie  dziesietnym

}

std::string readString() {
    std::string line;
    if(fileOpen) {
        std::getline(std::cin, line);
        if (line[line.size() - 1] == '\r') line.resize(line.size() - 1);
    }
    else
        std::getline(std::cin, line);
    return line;
}
