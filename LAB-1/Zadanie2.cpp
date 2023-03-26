#include <iostream>

using namespace std;

int main()
{
    double a, b;
    cout << "Program na podstawie podanych współczynników podaje rozwiązanie równania." << endl;
    cout << "Podaj współczynnik a: ";
    cin >> a;
    cout << "Podaj współczynnik b: ";
    cin >> b;
        if (a==0)
            if (b==0)
                cout << "Równanie tożsamościowe. Nieskończenie wiele rozwiązań!" << endl;
            else
                cout << "Równanie sprzeczne. Brak rozwiązań!" << endl;
        else
        {
            double x;
            x = -b/a;
            cout << "Rozwiązaniem równania jest liczba: " << x << "!" << endl;
        }
            
    return 0;
}