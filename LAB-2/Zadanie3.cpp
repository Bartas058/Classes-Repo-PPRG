#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    int fibonacci_poprzedni = 1, fibonacci_aktualny = 1;
    cout << "Podaj liczbę naturalną n: ";
    cin >> n;

    if (n == 1 && n == 2)
    {
        cout << "Wynikiem jest liczba 1!" << endl;
    }
    else if (n <= 0)
        return 0;
    else
        for (int i = 2; i < n; i++)
        {
            int fibonacci_nastepny = fibonacci_poprzedni + fibonacci_aktualny;
            fibonacci_poprzedni = fibonacci_aktualny;
            fibonacci_aktualny = fibonacci_nastepny;
        }

            cout << "Wynikiem jest liczba " << fibonacci_aktualny << "!" << "\n";

    return 0;
}