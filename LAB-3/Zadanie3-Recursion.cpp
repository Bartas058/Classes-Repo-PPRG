#include <iostream>
#include <cmath>

using namespace std;

int symbolNewtona(int n, int k)
{
    if (k == n || k == 0)
        return 1;
    
    return symbolNewtona(n - 1, k - 1) + symbolNewtona(n - 1, k);
}

int algorytmEuklidesa(int a, int b)
{
    if (a == 0)
        return b;
    
    return algorytmEuklidesa(b % a, a);
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