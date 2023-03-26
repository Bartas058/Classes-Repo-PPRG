#include <iostream>

using namespace std;

struct Osoba
{
    string imie;
    int wiek;
    double zarobki;
};

void sortujOsoby(Osoba osoby[], int rozmiar, bool (*porownaj)(Osoba, Osoba))
{
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            if (porownaj(osoby[i], osoby[j]))
            {
                Osoba tymczasowa = osoby[i];
                osoby[i] = osoby[j];
                osoby[j] = tymczasowa;
            }
        }
    }
}

bool porownajWiek(Osoba a, Osoba b)
{
    if (a.wiek < b.wiek)
    {
        return true;
    }
    else if (a.wiek == b.wiek)
    {
        if (a.imie < b.imie)
        {
            return true;
        }
    }
    return false;
}

bool porownajZarobki(Osoba a, Osoba b)
{
    if (a.zarobki < b.zarobki)
    {
        return true;
    }
    else if (a.zarobki == b.zarobki)
    {
        if (a.wiek < b.wiek)
        {
            return true;
        }
    }
    return false;
}

void pokazOsoby(Osoba osoby[], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        cout << osoby[i].imie << " " << osoby[i].wiek << " " << osoby[i].zarobki << endl;
    }
}

int main()
{
    Osoba osoby[] = {
        {"Ada", 30, 5700},
        {"Bartosz", 25, 8500},
        {"Czarek", 40, 8500},
        {"Daniel", 35, 19300},
        {"Ewelina", 30, 6700},
    };
 
    cout << "Posortowane według wieku:" << endl;
    sortujOsoby(osoby, 5, porownajWiek);
    pokazOsoby(osoby, 5);
    cout << endl;
    cout << "Posortowane według zarobków:" << endl;
    sortujOsoby(osoby, 5, porownajZarobki);
    pokazOsoby(osoby, 5);
    
    return 0;
}