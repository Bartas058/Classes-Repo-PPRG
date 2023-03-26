#include <iostream>
#include <cmath>

using namespace std;

bool czyPierwsza(int n)
{
    if (n < 2)
    {
        return false;
    }    
    
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    double liczba_startowa;
    double liczba_koncowa;
    
    cout << "Podaj liczbę startową: ";
    cin >> liczba_startowa;
    cout << "Podaj liczbę końcową: ";
    cin >> liczba_koncowa;
    
    cout << "Liczby pierwsze w podanym zakresie to: ";
    
    for (int i = liczba_startowa; i <= liczba_koncowa; i++)
    {
        if (czyPierwsza(i))
        {
            cout << i << " ";
        }
    }
    
    cout << endl;
    return 0;
}