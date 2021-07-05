#include <iostream>
#include <string>
#include <cstdlib>
#include "statek.h"

statek::statek() //kontruktor klasy
{

}

statek::~statek() //destruktor klasy
{

}

//Metody klasy 'statek'


void statek::getNameOfTheShip()
{
    std::cout << "Nazwa statku: " << name << std::endl;
}
void statek::setNameOfTheShip(std::string name)
{
    this->name = name;
}
int statek::getHeavyFuelStatus()
{
    return heavyFuelStatus;
}
int statek::setHeavyFuelStatus(int valueOfHeavyFuel)
{
    heavyFuelStatus = valueOfHeavyFuel;
}
int statek::getLightFuelStatus()
{
    return lightFuelStatus;
}
int statek::setLightFuelStatus(int valueOfLightFuel)
{
    lightFuelStatus = valueOfLightFuel;
}
float statek::usedFuel()
{
    float czas = trasa::readCurectDays()*24;
    usedHeavy(czas);
    usedLight(czas);
}
float statek::usedHeavy(float czas){
    float fSH = heavyFuelStatus - (czas*0.15);
    std::cout << "Zuzycie paliwa ciezkiego w czasie " << czas << " h " << "Paliwo: " << fSH << std::endl;
}
float statek::usedLight(float czas){
    float fSL = lightFuelStatus - (czas*0.25);
    std::cout << "Zuzycie paliwa lekkiego w czasie " << czas << " h " << "Paliwo: " << fSL << std::endl;
}
