#include <iostream>

using namespace std;

int main() 
{
    double a, b, c, d, e;
    cout << "Program przerywa działanie, jeżeli kolejna liczba nie jest większa od poprzedniej." << endl;
    cout << "Podaj pierwszą liczbę: ";
    cin >> a;
    cout << "Podaj drugą liczbę: ";
    cin >> b;
        if (b<=a)
            cout << "KONIEC PROGRAMU! Liczba " << b << " nie jest większa od liczby " << a << "!" << endl;
        else
            cout << "Podaj trzecią liczbę: ";
            cin >> c;
        if (c<=b)
            cout << "KONIEC PROGRAMU! Liczba " << c << " nie jest większa od liczby " << b << "!" << endl;
        else
            cout << "Podaj czwartą liczbę: ";
            cin >> d;
        if (d<=c)
            cout << "KONIEC PROGRAMU! Liczba " << d << " nie jest większa od liczby " << c << "!" << endl;
        else
            cout << "Podaj piątą liczbę: ";
            cin >> e;
        if (e<=d)
            cout << "KONIEC PROGRAMU! Liczba " << e << " nie jest większa od liczby " << d << "!" << endl;
        else
            cout << "Liczba " << e << " jest największą z wszystkich pozostałych!" << endl;
        
    return 0;
}