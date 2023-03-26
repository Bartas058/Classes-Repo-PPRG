#include <iostream>

using namespace std;

int stos[5];
int n = 5;
int top = -1;

void push(int wartosc)
{
    if (top >= n - 1)
        cout << "Przepełnienie stosu." << endl;
    else
    {
        top++;
        stos[top] = wartosc;
    }
}

void pop()
{
    if (top <= -1)
        cout << "Stos jest pusty." << endl;
    else
    {
        cout << "Usunięty element to: "<< stos[top] << endl;
        top--;
    }
}

void display()
{
    if (top >= 0)
    {
        cout << "Elementami stosu są: ";
        for (int i = top; i >= 0; i--)
        cout << stos[i] << " ";
        cout << endl;
    }
    else
        cout << "Stos jest pusty." << endl;
}

void menu()
{
    cout << "1. Dodaj element do stosu." << endl;
    cout << "2. Usuń element ze stosu." << endl;
    cout << "3. Wyświetl stos." << endl;
    cout << "4. Zakończ działanie programu." << endl;
}

int main()
{
    int dzialanie;
    int wartosc;
    menu();
    do
    {
        cout << ">>> ";
        cin >> dzialanie;
        switch (dzialanie)
        {
            case 1:
            {
                cout << "Wprowadź element: ";
                cin >> wartosc;
                push(wartosc);
                menu();
                break;
            }
            case 2:
            {
                pop();
                menu();
                break;
            }
            case 3:
            {
                display();
                menu();
                break;
            }
            case 4:
            {
                cout << "Koniec programu." << endl;
                break;
            }
            default:
            {
                cout << "Nieprawidłowy wybór." << endl;
                menu();
            }
        }
    }
    while (dzialanie != 4);

    return 0;
}