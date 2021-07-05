#include "rejs.h"
#include <ctime>
#include <iostream>
#include <bits/stdc++.h>

rejs::rejs()
{
    //ctor
}

rejs::~rejs()
{
    //dtor
}
//Added functions

bool rejs::isLeap(int y)
{
    if (y%100 != 0 && y%4 == 0 || y %400 == 0)
        return true;

    return false;
}

// Podana data zwraca liczbe dni, które uplynely
// od poczatku biezacego roku (1
// stycznia).
int rejs::offsetDays(int d, int m, int y)
{
    int offset = d;

    switch (m - 1)
    {
    case 11:
        offset += 30;
    case 10:
        offset += 31;
    case 9:
        offset += 30;
    case 8:
        offset += 31;
    case 7:
        offset += 31;
    case 6:
        offset += 30;
    case 5:
        offset += 31;
    case 4:
        offset += 30;
    case 3:
        offset += 31;
    case 2:
        offset += 28;
    case 1:
        offset += 31;
    }

    if (isLeap(y) && m > 2)
        offset += 1;

    return offset;
}

// Biorac pod uwage rok i dni, które w nim uplynely, stwierdza
// data przez przechowywanie wyników w d i m.
void rejs::revoffsetDays(int offset, int y, int *d, int *m)
{
    int month[13] = { 0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31 };

    if (isLeap(y))
        month[2] = 29;

    int i;
    for (i = 1; i <= 12; i++)
    {
        if (offset <= month[i])
            break;
        offset = offset - month[i];
    }

    *d = offset;
    *m = i;
}

// Dodaj x dni do podanej daty.
void rejs::addDays(int d1, int m1, int y1)
{
    int x = 0;
    x = trasa::readCurectDays();

    int offset1 = offsetDays(d1, m1, y1);
    int remDays = isLeap(y1)?(366-offset1):(365-offset1);

    // rok 2 bedzie przechowywac rok wyników i
    // offset2 bedzie przechowywac dni przesuniecia
    // w roku wynikowym.
    int y2, offset2;
    if (x <= remDays)
    {
        y2 = y1;
        offset2 = offset1 + x;
    }

    else
    {
        // x moze przechowywac tysiace dni.
        // Znajdujemy poprawny rok i offset
        // w roku.
        x -= remDays;
        y2 = y1 + 1;
        int y2days = isLeap(y2)?366:365;
        while (x >= y2days)
        {
            x -= y2days;
            y2++;
            y2days = isLeap(y2)?366:365;
        }
        offset2 = x;
    }

    // Znajdz wartosci dnia i miesisca od
    // przesuniecie roku wynikowego.
    int m2, d2;
    revoffsetDays(offset2, y2, &d2, &m2);
    std::cout << "Data w ktorej bedzie w porcie docelowym: " << std::endl;
    std::cout << "Dzien = " << d2 << ", miesiac = " << m2
         << ", rok = " << y2 << std::endl;
}


