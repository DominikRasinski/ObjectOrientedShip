#include "trasa.h"
#include <iostream>
#include <string>



trasa::trasa()
{
    //ctor
}

trasa::~trasa()
{
    //dtor
}

void trasa::insertIdOfPorts()
{
    int portStartName, portTargetName;
    std::cout << "Podaj indentyfikator z ktorego portu zaczynasz: ";
    std::cin >> portStartName;
    std::cout << "Podaj indentyfikator portu do ktorego plyniesz: ";
    std::cin >> portTargetName;
    if(portStartName != portTargetName){
        insertPortStartName(portStartName);
        insertPortTargetName(portTargetName);
        whatACourse(portStartName, portTargetName);
    }
    else{
        std::cout << "Nie mozna podawac tych samych identyfikatorow do celu podrozy i do startu podrozy!!" << std::endl;
        insertIdOfPorts();
    }
}
//pobieranie i zwracanie ekonomicznej predkosci
int trasa::setEconimicSpeed(int valueOfEconomicSpeed)
{
    economicSpeed = valueOfEconomicSpeed;
}
int trasa::getEconomicSpeed()
{
    return economicSpeed;
}
//pobieranie portow i ich zwracanie
int trasa::insertPortStartName(int portStartName)
{
    switch(portStartName)
    {
    case 123264:
        std::cout << "Port z ktorego zaczynasz to: Tinjin " << "identyfikator portu to: " << portStartName << std::endl;
        break;
    case 123468:
        std::cout << "Port z ktorego zaczynasza to: Qinqdao " << "identyfikator portu to: " << portStartName << std::endl;
        break;
    case 123672:
        std::cout << "Port z ktorego zaczynasz to: Ningbo " << "identyfikator portu to: " << portStartName << std::endl;
        break;
    case 123876:
        std::cout << "Port z ktorego zaczynasz to: Shanghai " << "identyfikator portu to: " << portStartName << std::endl;
        break;
    default:
        std::cout << "Cos jest nie tak sprawdz czy identyfikator zostal dobrze podany: " << portStartName <<  std::endl;
    }
}
int trasa::insertPortTargetName(int portTargetName)
{
    switch(portTargetName)
    {
    case 123264:
        std::cout << "Port do ktorego zmierzasz to: Tinjin " << "identyfikator portu to: " << portTargetName << std::endl;
        break;
    case 123468:
        std::cout << "Port do ktorego zmierzasz to: Qinqdao " << "identyfikator portu to: " << portTargetName << std::endl;
        break;
    case 123672:
        std::cout << "Port do ktorego zmierzasz to: Ningbo " << "identyfikator portu to: " << portTargetName << std::endl;
        break;
    case 123876:
        std::cout << "Port do ktorego zmierzasz to: Shanghai " << "identyfikator portu to: " << portTargetName << std::endl;
        break;
    default:
        std::cout << "Cos jest nie tak sprawdz czy identyfikator zostal dobrze podany: " << portTargetName <<  std::endl;
    }
}
int trasa::whatACourse(int portStartName, int portTargetName)
{
    int rangeArray[6] = {10000,15000,16000,14000,16000,18000};

    if((portStartName == 123264 && portTargetName == 123468) || (portStartName == 123468 && portTargetName == 123264)){
        std::cout << "Odleglosc od portu startowego do portu celu wynosi: " << rangeArray[0] << " km, a w milach to: "<< convertKMtoMM(rangeArray[0]) << " mil morskich" << std::endl;
        howLongItTake(rangeArray[0]);
    }
    else if((portStartName == 123264 && portTargetName == 123672) || (portStartName == 123672 && portTargetName == 123264)){
        std::cout << "Odleglosc od portu startowego do portu celu wynosi: " << rangeArray[1] << " km, a w milach to: "<< convertKMtoMM(rangeArray[1]) << " mil morskich" << std::endl;
        howLongItTake(rangeArray[1]);
    }
    else if((portStartName == 123264 && portTargetName == 123876) || (portStartName == 123876 && portTargetName == 123264)){
        std::cout << "Odleglosc od portu startowego do portu celu wynosi: " << rangeArray[2] << " km, a w milach to: "<< convertKMtoMM(rangeArray[2]) << " mil morskich" << std::endl;
        howLongItTake(rangeArray[2]);
    }
    else if((portStartName == 123468 && portTargetName == 123672) || (portStartName == 123672 && portTargetName == 123468)){
        std::cout << "Odleglosc od portu startowego do portu celu wynosi: " << rangeArray[3] << " km, a w milach to: "<< convertKMtoMM(rangeArray[3]) << " mil morskich" << std::endl;
        howLongItTake(rangeArray[3]);
    }
    else if((portStartName == 123468 && portTargetName == 123876) || (portStartName == 123876 && portTargetName == 123468)){
        std::cout << "Odleglosc od portu startowego do portu celu wynosi: " << rangeArray[4] << " km, a w milach to: "<< convertKMtoMM(rangeArray[4]) << " mil morskich" << std::endl;
        howLongItTake(rangeArray[4]);
    }
    else if((portStartName == 123672 && portTargetName == 123876) || (portStartName == 123876 && portTargetName == 123672)){
        std::cout << "Odleglosc od portu startowego do portu celu wynosi: " << rangeArray[5] << " km, a w milach to: "<< convertKMtoMM(rangeArray[5]) << " mil morskich" << std::endl;
        howLongItTake(rangeArray[5]);
    }
}

float trasa::convertKMtoMM(int rangeArray) //funkcja konwertujaca odleglosc z kilometrow na mile morskie miedzynarodowe
{
    float result = 0;
    result = rangeArray * 0.53996;
    return result;
}
int trasa::howLongItTake(int rangeArray) //funkcja obliczajaca ile dni zajmie podroz przyjmujac ze statek kazdego dnia bedzie robic tyle KM ile jest w predkosci
{
    float days = 0;
    days = rangeArray / getEconomicSpeed();
    trasa::setValueDays(days);
}
void trasa::setValueDays(float value)
{
    curectDays = value;
}
float trasa::readCurectDays()
{
    return trasa::curectDays;
}
