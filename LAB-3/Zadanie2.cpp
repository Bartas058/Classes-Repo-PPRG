#include <iostream>
#include <cmath>

using namespace std;

int czySzescian(int n)
{
    int szescian;
    
    for (double i = -10000; i*i*i <= n; i++)
        if (i*i*i == n)
        {
            szescian = 1;
            return szescian;
        }
        else
            szescian = 0;
            return szescian;
            
    cout << szescian << endl;
}

int main()
{
    int liczba_calkowita;
    cout << "Program sprawdzający, czy podana liczba całkowita jest sześcianem pewnej liczby całkowitej." << endl;
    cout << "Podaj dowolną cyfrę całkowitą: ";
    cin >> liczba_calkowita;
    
    cout << "Wartość stwierdzenia to: " << czySzescian(liczba_calkowita) << "!" << endl;
    
    return 0;
}