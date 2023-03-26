#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;
    cout << "Program na podstawie podannych współczynników podaje rozwiązanie równania kwadratowego." << endl;
    cout << "Podaj współczynnik a: ";
    cin >> a;
    cout << "Podaj współczynnik b: ";
    cin >> b;
    cout << "Podaj współczynnik c: ";
    cin >> c;
    if(a==0 && b!=0)
    {
        cout << "Równanie liniowe, którego wynikiem jest: " << -c/b << "!" << endl;
    }
    else if(a==0 && b==0 && c!=0)
    {
        cout << "Brak rozwiązań!" << endl;
    }
    else if(a==0 && b==0 && c==0)
    {
        cout << "Nieskończenie wiele rozwiązań!" << endl;
    }
    else
    {
        double delta;
        delta = b*b-4*a*c;
        if (delta<0)
            cout << "Równanie nie ma rozwiązań!" << endl;
        else 
        if (delta == 0)
        {
            double x;
            x = -b/(2*a);
            cout << "Rozwiązaniem równania jest liczba: " << x << "!" << endl;
        }
        else
        {
            double x1, x2;
            x1 = (-b-sqrt(delta))/(2*a);
            x2 = (-b+sqrt(delta))/(2*a);
            cout << "Rozwiązaniem równania są liczby: " << x1 << " oraz " << x2 << "!" << endl;
        }
    }
        
    return 0;
}