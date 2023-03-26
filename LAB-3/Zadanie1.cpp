#include <iostream>
#include <cmath>

using namespace std;

int sumaCyfr(int n)
{
    int wynik;
    wynik = 0;
    
    while (n != 0)
    {
        wynik += n % 10;
        n /= 10;
    }
    return abs(wynik);
        
    cout << wynik << endl;
    
}

int main()
{
    int liczba_calkowita;
    cout << "Program, który wyzancza sumę cyfr podanej liczby całkowitej." << endl;
    cout << "Podaj liczbę całkowitą: ";
    cin >> liczba_calkowita;
    
    cout << "Suma cyfr wynosi: " << sumaCyfr(liczba_calkowita) << "!" << endl;
    
    return 0;
}