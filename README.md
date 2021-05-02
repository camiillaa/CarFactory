<h3>PROJEKT</h3> 
Programowanie obiektowe c++
Fabryka samochodów

Napisz program oferujący następujące funkcjonalności:

<h5><i>ETAP1</i></h5>
1. Klasa reprezentująca Fabrykę posiada unikalną nazwę określającą markę i produkuje
obiekty klasy Samochód i dodaje je do prywatnej tablicy.
2. Metoda tworząca nowy samochód przyjmuje kolor oraz liczbę drzwi jako argumenty.
Właściciel jest ustawiany na “fabryka”, marka zgodnie z nazwą fabryki).
3. Samochód posiada pola: właściciel, kolor, marka (ustalana zgodnie z fabryką), liczba
drzwi, przebieg oraz metody jedź z argumentem mówiącym o liczbie przejechanych
kilometrów (zwiększa przebieg).
4. Fabryka posiada metodę sprzedaj, która zmienia właściciela na osobą kupującą i usuwa
auto z fabryki.
5. Program powinien udostępniać interfejs pozwalający na wywołania poszczególnych
metod.


<h5><i>ETAP2</i></h5>

Dodajemy klasy Motocykl i Rower (z opcjonalnym koszykiem). Klasa Samochód i Motocykl mają
dodatkowo pole ‘ilość_paliwa’, które jest zmniejszane przez metodę jedź. Wprowadzamy klasy
Pojazd i PojazdSilnikowy. Zaproponuj sposób dziedziczenia oraz sposób rozmieszczenia pól
składowych w tych klasach. Wszystkie Pojazdy posiadają daną ładowność, w przypadku roweru
jest do zależne od posiadanego koszyka, a w klasie Samochodu czy motocyklu jest to
określone rozmiarem bagażnika w danej marce. Klasa Pojazd posiada metodę ‘ładowność’
która zwraca ładowność danego pojazdu.
Dodajemy klasę Komis, która posiada plac (np. vector) na PojazdySilnikowe. Komis może
odkupić auto od właściciela, lub mu je sprzedać. Cena skupu jest funkcją zależną od marki i
przebiegu, a cena sprzedaży jest ceną zakupu z marżą. Przy zakupie przez komis przebieg
niektórych marek jest dzielony przez 2.
Dodajemy klasę Lakiernik, która przyjmuje Pojazd do lakierowania i zmienia mu kolor.

Program pozwala na uruchomienie z argumentem wiersza poleceń, którym jest ścieżka
do pliku. W takim przypadku program ma wykonać polecenia (komendy) znajdujące się w tym
pliku zamiast czytania ze standardowego wejścia. W przypadku braku argumentu wywołania
programu, program zachowuje się jak dotychczas, czyli czyta komendy ze standardowego
wejścia. W przesłanym archiwum proszę umieścić jeden lub więcej plików z komendami. Nazwa
pliku powinna się zaczynać “stdin” i kończyć na “.txt”.



<h5><i>ETAP3</i></h5>

Dodana obsługa wyjątków. Wykorzystanie szablonów.
