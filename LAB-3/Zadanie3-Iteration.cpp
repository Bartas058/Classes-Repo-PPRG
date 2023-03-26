#include <iostream>
#include <cmath>

using namespace std;

int symbolNewtona(int n, int k)
{
    int s = 1;
    for (int i = 2; i <= n; i++)
    s *= i;
    for (int i = 2; i <= k; i++)
    s /= i;
    for (int i = 2; i <= n - k; i++)
    s /= i;
    
    return s;
}

int algorytmEuklidesa(int a, int b)
{
    while (a != b)
        if (a < b)
            b -= a;
        else
            a -= b;
    
    return a;
}

int main()
{
    int n, k;
    cout << "Podaj liczbę n: ";
    cin >> n;
    cout << "Podaj liczbę k: ";
    cin >> k;
    
    cout << "Symbol Newtona wynosi: " << symbolNewtona(n, k) << "!" << endl;
    
    int a, b;
    cout << "Podaj liczbę a: ";
    cin >> a;
    cout << "Podaj liczbę b: ";
    cin >> b;
    
    cout << "Największy współczynnik liczb " << a << " oraz " << b << " wynosi: " << algorytmEuklidesa(a, b) << "!" << endl;
    
    return 0;
}