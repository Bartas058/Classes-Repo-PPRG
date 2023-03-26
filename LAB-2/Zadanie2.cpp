#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m, sum_1, sum_2;
    cout << "Podaj liczbę początkową zakresu: ";
    cin >> n;
    cout << "Podaj liczbę końcową zakresu: ";
    cin >> m;

    for (int a = n; a <= m; a++)
    {
        sum_1 = 0;
        for (int x = 1; x < a; x++)
            if (a % x == 0)
                sum_1 += x;
                sum_2 = 0;
        for (int b = 1; b < sum_1; b++)
            if (sum_1 % b == 0)
                sum_2 += b;
        if (a == sum_2 && sum_1 != sum_2 && a < sum_1) 
            cout << "Liczby zaprzyjaźnione w podanym zakresie to pary liczb: " << a << " " << sum_1 << "!" << endl;
    }
    return 0;
}