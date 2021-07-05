#include <string>
#include <statek.h>
#include <trasa.h>
#include <rejs.h>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int d = 0, m = 0, y = 0, knots = 0;
    statek tankowiec1;

    std::string name;
    std::cout << "Nazwij swoj statek: ";
    std::cin >> name;
    tankowiec1.setNameOfTheShip(name);
    tankowiec1.getNameOfTheShip();
    std::cout << "Podaj prekosc statku w wezlach: ";
    std::cin >> knots;
    tankowiec1.setEconimicSpeed(knots);
    std::cout << "Optymalna predkosc to: " << tankowiec1.getEconomicSpeed() << std::endl;

    tankowiec1.insertIdOfPorts();

    std::cout << "Podaj dzien rozpoczecia podrozy: ";
    std::cin >> d;
    std::cout << "Podaj miesiac rozpoczecia podrozy: ";
    std::cin >> m;
    std::cout << "Podaj rok rozpoczacia podrozy: ";
    std::cin >> y;

    tankowiec1.addDays(d,m,y);

    tankowiec1.setHeavyFuelStatus(2000);
    std::cout << "Zapas paliwa ciezkiego: " << tankowiec1.getHeavyFuelStatus() << " ton"<< std::endl;

    tankowiec1.setLightFuelStatus(3000);
    std::cout << "Zapas paliwa lekkiego: " << tankowiec1.getLightFuelStatus() << " ton" << std::endl;

    tankowiec1.usedFuel(); //obliczanie zuzycia obu surowcow przez na dobe, kazda wpisana liczba jest konwertowana na doby np. 6 = 6 dni
}
