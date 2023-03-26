#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct punktA {
    string punkt;
    int x;
    int y;
    
    string toString() {
        return "{ punkt: " + punkt
            + ", x: " + to_string(x)
            + ", y: " + to_string(y) + "}";
    }
} punktA[2];

struct punktB {
    string punkt;
    int x;
    int y;

    string toString() {
        return "{ punkt: " + punkt
            + ", x: " + to_string(x)
            + ", y: " + to_string(y) + "}";
    }
} punktB[2];

struct punktC {
    string punkt;
    int x;
    int y;

    string toString() {
        return "{ punkt: " + punkt
            + ", x: " + to_string(x)
            + ", y: " + to_string(y) + "}";
    }
} punktC[2];

int iloscPunktow = 0;

void uzupelnijA()
{
    int pierwszaWspolrzedna;
    int drugaWspolrzedna;
    cout << "Podaj współrzędną x_1: ";
    cin >> pierwszaWspolrzedna;
    cout << "Podaj współrzedną y_1: ";
    cin >> drugaWspolrzedna;

    punktA[iloscPunktow].x = pierwszaWspolrzedna;
    punktA[iloscPunktow].y = drugaWspolrzedna;
}

void uzupelnijB()
{
    int pierwszaWspolrzedna;
    int drugaWspolrzedna;
    cout << "Podaj współrzędną x_2: ";
    cin >> pierwszaWspolrzedna;
    cout << "Podaj współrzędną y_2: ";
    cin >> drugaWspolrzedna;

    punktB[iloscPunktow].x = pierwszaWspolrzedna;
    punktB[iloscPunktow].y = drugaWspolrzedna;
}

void uzupelnijC()
{
    int pierwszaWspolrzedna;
    int drugaWspolrzedna;
    cout << "Podaj współrzędną x_3: ";
    cin >> pierwszaWspolrzedna;
    cout << "Podaj współrzędną y_3: ";
    cin >> drugaWspolrzedna;

    punktC[iloscPunktow].x = pierwszaWspolrzedna;
    punktC[iloscPunktow].y = drugaWspolrzedna;
}

void obliczOdlegosc()
{
    float odleglosc;
    int odleglosc_x;
    int odleglosc_y;
    odleglosc_x = punktB[iloscPunktow].x - punktA[iloscPunktow].x;
    odleglosc_y = punktB[iloscPunktow].y - punktA[iloscPunktow].y;
    
    odleglosc = sqrt((double) odleglosc_x * odleglosc_x + odleglosc_y * odleglosc_y);

    cout << "Odległość między punktami (" << punktA[iloscPunktow].x << "," << punktA[iloscPunktow].y << ") " << "oraz" << " (" << punktB[iloscPunktow].x << "," << punktB[iloscPunktow].y << ") wynosi: " << odleglosc << endl;
}

void czyTrojkat()
{
    float aktualnie_najdluzszy;
    float suma;
    
    float odleglosc_ab;
    int odleglosc_x1;
    int odleglosc_y1;
    odleglosc_x1 = punktB[iloscPunktow].x - punktA[iloscPunktow].x;
    odleglosc_y1 = punktB[iloscPunktow].y - punktA[iloscPunktow].y;

    odleglosc_ab = sqrt((double) odleglosc_x1 * odleglosc_x1 + odleglosc_y1 * odleglosc_y1);

    cout << "Odległość między punktami (" << punktA[iloscPunktow].x << ";" << punktA[iloscPunktow].y << ") " << "oraz" << " (" << punktB[iloscPunktow].x << ";" << punktB[iloscPunktow].y << ") wynosi: " << odleglosc_ab << endl;

    float odleglosc_ac;
    int odleglosc_x2;
    int odleglosc_y2;
    odleglosc_x2 = punktC[iloscPunktow].x - punktA[iloscPunktow].x;
    odleglosc_y2 = punktC[iloscPunktow].y - punktA[iloscPunktow].y;

    odleglosc_ac = sqrt((double) odleglosc_x2 * odleglosc_x2 + odleglosc_y2 * odleglosc_y2);

    cout << "Odległość między punktami (" << punktA[iloscPunktow].x << ";" << punktA[iloscPunktow].y << ") " << "oraz" << " (" << punktC[iloscPunktow].x << ";" << punktC[iloscPunktow].y << ") wynosi: " << odleglosc_ac << endl;

    float odleglosc_cb;
    int odleglosc_x3;
    int odleglosc_y3;
    odleglosc_x3 = punktB[iloscPunktow].x - punktC[iloscPunktow].x;
    odleglosc_y3 = punktB[iloscPunktow].y - punktC[iloscPunktow].y;

    odleglosc_cb = sqrt((double) odleglosc_x3 * odleglosc_x3 + odleglosc_y3 * odleglosc_y3);

    cout << "Odległość między punktami (" << punktC[iloscPunktow].x << ";" << punktC[iloscPunktow].y << ") " << "oraz" << " (" << punktB[iloscPunktow].x << ";" << punktB[iloscPunktow].y << ") wynosi: " << odleglosc_cb << endl;
    
    aktualnie_najdluzszy = odleglosc_ab;

    if (odleglosc_ac > aktualnie_najdluzszy)
    aktualnie_najdluzszy = odleglosc_ac;

    if (odleglosc_cb > aktualnie_najdluzszy)
    aktualnie_najdluzszy = odleglosc_cb;

    suma = odleglosc_ab + odleglosc_ac + odleglosc_cb - aktualnie_najdluzszy;

    if (suma > aktualnie_najdluzszy)
        cout << "Punkty (" << punktA[iloscPunktow].x << ";" << punktA[iloscPunktow].y << "), (" << punktB[iloscPunktow].x << ";" << punktB[iloscPunktow].y << "), (" << punktC[iloscPunktow].x << ";" << punktC[iloscPunktow].y << ") tworzą trókąt." << endl;
    else
        cout << "Punkty (" << punktA[iloscPunktow].x << ";" << punktA[iloscPunktow].y << "), (" << punktB[iloscPunktow].x << ";" << punktB[iloscPunktow].y << "), (" << punktC[iloscPunktow].x << ";" << punktC[iloscPunktow].y << ") nie tworzą trókąta." << endl;
}

void najbardziejOddalone()
{
    float odleglosc_ab;
    int odleglosc_x1;
    int odleglosc_y1;
    odleglosc_x1 = punktB[iloscPunktow].x - punktA[iloscPunktow].x;
    odleglosc_y1 = punktB[iloscPunktow].y - punktA[iloscPunktow].y;

    odleglosc_ab = sqrt((double) odleglosc_x1 * odleglosc_x1 + odleglosc_y1 * odleglosc_y1);

    float odleglosc_ac;
    int odleglosc_x2;
    int odleglosc_y2;
    odleglosc_x2 = punktC[iloscPunktow].x - punktA[iloscPunktow].x;
    odleglosc_y2 = punktC[iloscPunktow].y - punktA[iloscPunktow].y;

    odleglosc_ac = sqrt((double) odleglosc_x2 * odleglosc_x2 + odleglosc_y2 * odleglosc_y2);

    float odleglosc_cb;
    int odleglosc_x3;
    int odleglosc_y3;
    odleglosc_x3 = punktB[iloscPunktow].x - punktC[iloscPunktow].x;
    odleglosc_y3 = punktB[iloscPunktow].y - punktC[iloscPunktow].y;

    odleglosc_cb = sqrt((double) odleglosc_x3 * odleglosc_x3 + odleglosc_y3 * odleglosc_y3);

    if (odleglosc_ab >= odleglosc_ac &&  odleglosc_ab >= odleglosc_cb)
        cout << "Punkty (" << punktA[iloscPunktow].x << ";" << punktA[iloscPunktow].y << ") oraz (" << punktB[iloscPunktow].x << ";" << punktB[iloscPunktow].y << ") są punktami najbardziej oddalonymi od siebie." << endl;
    else if (odleglosc_ac >= odleglosc_ab && odleglosc_ac >= odleglosc_cb)
        cout << "Punkty (" << punktA[iloscPunktow].x << ";" << punktA[iloscPunktow].y << ") oraz (" << punktC[iloscPunktow].x << ";" << punktC[iloscPunktow].y << ") są punktami najbardziej oddalonymi od siebie." << endl;
    else
        cout << "Punkty (" << punktC[iloscPunktow].x << ";" << punktC[iloscPunktow].y << ") oraz (" << punktB[iloscPunktow].x << ";" << punktB[iloscPunktow].y << ") są punktami najbardziej oddalonymi od siebie." << endl;
}

int main()
{
    int dzialanie;
    while (true) 
    {
        cout << "Wybór operacji, którą chcesz wykonać." << endl;
        
        cout << "1. Oblicz odległość między dwoma podanymi punktami." << endl;

        cout << "2. Sprawdź, czy trzy podane punkty tworzą trójkąt." << endl;

        cout << "3. Dla wybranych punktów sprawdź, które są najbardziej oddalone od siebie." << endl;

        cout << "4. Zakończ działanie programu." << endl;

        cout << "Wprowadź swój wybor: ";
        cin >> dzialanie;

        switch (dzialanie)
        {
            case 1:
                uzupelnijA();
                uzupelnijB();
                obliczOdlegosc();
                break;
            
            case 2:
                uzupelnijA();
                uzupelnijB();
                uzupelnijC();
                czyTrojkat();
                break;

            case 3:
                uzupelnijA();
                uzupelnijB();
                uzupelnijC();
                najbardziejOddalone();
                break;

            case 4:
                exit(0);
                break;
        }
    }

    return 0;
}