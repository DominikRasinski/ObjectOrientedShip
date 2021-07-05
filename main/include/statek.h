#ifndef STATEK_H
#define STATEK_H
#include <string>
#include <cstdlib>

#include <trasa.h>
#include <rejs.h>

class statek : public rejs
{
    public:

        void getNameOfTheShip();
        void setNameOfTheShip(std::string name);

        int setHeavyFuelStatus(int valueOfHeavyFuel);
        int getHeavyFuelStatus();

        int setLightFuelStatus(int valueOfLightFuel);
        int getLightFuelStatus();

        float usedFuel(); //metoda zwracajaca zuzycie paliwa

        statek();           //konstruktor
        virtual ~statek();  //destruktor

    protected:

    private:
        std::string name;       //zmienna prywatna przechowujaca imie statku
        int heavyFuelStatus;    //zmienna prywatna przechowujaca wartosc ciezkiego paliwa
        int lightFuelStatus;    //zmienna prywatna przechowujaca wartosc lekkiego paliwa

        float usedHeavy(float czas);     //prywatna funkcja do ktorej ma dostep jedynie metoda 'usedFuel'
        float usedLight(float czas);     //pruwatna funkcja do ktorej ma dostep jedynie metoda 'usedFuel'
};

#endif // STATEK_H
