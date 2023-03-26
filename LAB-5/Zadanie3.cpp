#include <iostream>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct wezelDrzewa
{
	char info;
	wezelDrzewa *lewy, *prawy;
} wezelDrzewa;

typedef struct wezelDrzewa *wyrazenieDrzewo;

wyrazenieDrzewo stworzWezel(int info);
wyrazenieDrzewo zbudujDrzewo(wyrazenieDrzewo D, char postfiks[]);
int uzyskajKolejnosc(char znak);
void konwertujWsteczne(string infiks, char postfiks[]);
void wynikWyrazenia(char postfiks[]);
int height(wyrazenieDrzewo D);
int size(wyrazenieDrzewo wezel);
void pokazWezel(wyrazenieDrzewo D);
void przejscieWzdluzne(wyrazenieDrzewo D);
void przejsciePoprzeczne(wyrazenieDrzewo D);
void przejscieWsteczne(wyrazenieDrzewo D);
void wyswietlanieWyniku(char postfiks[], wyrazenieDrzewo drzewo);
void przechodzenieDrzewa(wyrazenieDrzewo drzewo, char postfiks[]);
bool czyPoprawny(string infiks);
bool czyOperator(char znak);
bool czyLiczba(char znak);

void przechodzenieDrzewa(wyrazenieDrzewo drzewo, char postfiks[])
{
	cout << "Przejście wzdłużne | (1. Wartość 2. Lewy syn 3. Prawy syn) : [ ";
	przejscieWzdluzne(drzewo);
	cout << "]" << endl;
	cout << "Przejście poprzeczne | (1. Lewy syn 2. Wartość 3. Prawy syn) : [ ";
    przejsciePoprzeczne(drzewo);
	cout << "]" << endl;
    cout << "Przejście wsteczne | (1. Lewy syn 2. Prawy syn 3. Wartość) : [ ";
    przejscieWsteczne(drzewo);
	cout << "]" << endl;
}

void wyswietlanieWyniku(char postfiks[], wyrazenieDrzewo drzewo)
{
	cout << "Wynik wyrażenia: ";
	przejsciePoprzeczne(drzewo);
	wynikWyrazenia(postfiks);
	cout << "Liczba węzłów: " << size(drzewo) << endl;
	cout << "Wysokość: " << height(drzewo) << endl;
}

bool czyLiczba(char znak)
{
	if (znak > 47 && znak < 57)
		return true;
	return false;
}

bool czyOperator(char znak)
{
	if (znak == '+' || znak == '-' || znak == '*' || znak == '/' || znak == '%' || znak == '^')
		return true;
	return false;
}

bool czyPoprawny(string infiks)
{
	for (unsigned int i = 0; i < infiks.length(); i++)
	{
		if (!czyLiczba(infiks[i]) && !czyOperator(infiks[i]) && infiks[i] != '(' && infiks[i] != ')')
			return false;
	}
	return true;
}

wyrazenieDrzewo stworzWezel(int info)
{
	wezelDrzewa *tymczasowe;
	tymczasowe = (wezelDrzewa *)malloc(sizeof(wezelDrzewa));
	if (tymczasowe == NULL)
	{
		cout << "Nie ma miejsca!" << endl;
		return (tymczasowe);
	}
	tymczasowe -> lewy = NULL;
	tymczasowe -> prawy = NULL;
	tymczasowe -> info = info;
	return tymczasowe;
};

wyrazenieDrzewo zbudujDrzewo(wyrazenieDrzewo drzewo, char postfiks[])
{
	int i = 0;
	stack < wezelDrzewa *> stos;
	wezelDrzewa *tymczasowe_drzewo1;
	wezelDrzewa *tymczasowe_drzewo2;
	while (postfiks[i] != '\0')
	{
		if (!(postfiks[i] == '+' || postfiks[i] == '-' || postfiks[i] == '*' || postfiks[i] == '/'
			|| postfiks[i] == '%' || postfiks[i] == '^'))
		{
			drzewo = stworzWezel(postfiks[i]);
			stos.push(drzewo);
		}
		else
		{
			drzewo = stworzWezel(postfiks[i]);
			tymczasowe_drzewo1 = stos.top(); stos.pop();
			tymczasowe_drzewo2 = stos.top(); stos.pop();
			drzewo -> prawy = tymczasowe_drzewo1;
			drzewo -> lewy = tymczasowe_drzewo2;
			stos.push(drzewo);
		}
		i++;
	}
	return drzewo;
}

void pokazWezel(wyrazenieDrzewo D)
{
	cout << D -> info << " ";
}

void przejscieWzdluzne(wyrazenieDrzewo D)
{
	if (D != NULL)
	{
		pokazWezel(D);
		przejscieWzdluzne(D -> lewy);
		przejscieWzdluzne(D -> prawy);
	}
}

void przejsciePoprzeczne(wyrazenieDrzewo D)
{
	if (D != NULL)
	{
		przejsciePoprzeczne(D -> lewy);
		pokazWezel(D);
		przejsciePoprzeczne(D -> prawy);
	}
}

void przejscieWsteczne(wyrazenieDrzewo D)
{
	if (D != NULL)
	{
		przejscieWsteczne(D -> lewy);
		przejscieWsteczne(D -> prawy);
		pokazWezel(D);
	}
}

int uzyskajKolejnosc(char znak)
{
	switch (znak)
	{
	    case '^':
		    return 4;
	    case '%':
		    return 3;
	    case '/':
	    case '*':
		    return 2;
	    case '+':
	    case '-':
		    return 1;
	    default:
		    return 0;
	}
}

void konwertujWsteczne(string infiks, char postfiks[])
{
	unsigned int licznik1 = 0;
	stack < char > stos;
	int wsteczneLicznik = 0;
	char element;
	while (licznik1 < infiks.length())
	{
		element = infiks[licznik1];
		if (element == '(')
		{
			stos.push(element);
			licznik1++;
			continue;
		}
		if (element == ')')
		{
			while (!stos.empty() && stos.top() != '(')
			{
				postfiks[wsteczneLicznik++] = stos.top();
				stos.pop();
			}
			if (!stos.empty())
			{
				stos.pop();
			}
			licznik1++;
			continue;
		}
		if (uzyskajKolejnosc(element) == 0)
		{
			postfiks[wsteczneLicznik++] = element;
		}
		else
		{
			if (stos.empty())
			{
				stos.push(element);
			}
			else
			{
				while (!stos.empty() && stos.top() != '(' && uzyskajKolejnosc(element) <= uzyskajKolejnosc(stos.top()))
				{
					postfiks[wsteczneLicznik++] = stos.top();
					stos.pop();
				}
				stos.push(element);
			}
		}
		licznik1++;
	}
	while (!stos.empty())
	{
		postfiks[wsteczneLicznik++] = stos.top();
		stos.pop();
	}
	postfiks[wsteczneLicznik] = '\0';
}

void wynikWyrazenia(char postfiks[])
{
	stack < float > wynik;
	int k = 0;
	bool error = false;
	while (postfiks[k] && !error)
	{
		char znak = postfiks[k];
		if (czyLiczba(znak))
		{
			wynik.push((float)postfiks[k] - '0');
		}
		else if (znak == '+' || znak == '-' || znak == '*' || znak == '/' || znak == '%' || znak == '^')
		{
			float num1 = wynik.top();
			wynik.pop();
			float num2 = wynik.top();
			wynik.pop();
			float calc = 0;
			switch (znak)
			{
			case '+':
				calc = num2 + num1;
				break;
			case '-':
				calc = num2 - num1;
				break;
			case '*':
				calc = num2 * num1;
				break;
			case '/':
				if (num1 == 0)
				{
					cout << "\nWystąpił błąd. Nie można dzielić przez 0!" << endl;
					error = true;
					break;
				}
				calc = num2 / num1;
				break;
			case '%':
				if (num1 == 0)
				{
					cout << "\nWystąpił błąd. Nie można dzielić przez 0!" << endl;
					error = true;
					break;
				}
				calc = ((int)num2) % ((int)num1);
				break;
			case '^':
				calc = pow(num2, num1);
				break;
			}
			wynik.push(calc);
		}
		k++;
	}
	if (!error)
		cout << " = " << wynik.top() << endl;
}

int size(wyrazenieDrzewo wezel)
{
	if (wezel == NULL)
		return 0;
	else
		return(1 + size(wezel -> lewy) + size(wezel -> prawy));
}

int height(wyrazenieDrzewo D)
{
	if (D == NULL)
		return -1;
	else
	{
		return 1 + max(height(D -> lewy), height(D -> prawy));
	}
}

void menu()
{
    cout << "Wybierz opcję, którą chcesz wykonać: " << endl;
    cout << "1. Oblicz wartość wyrażenia." << endl;
    cout << "2. Zakończ działanie programu." << endl;
    cout << "Twój wybór: ";
}

int main()
{
	int dzialanie;
    menu();
    while (cin >> dzialanie)
    {
        switch (dzialanie)
        {
            case 1:
            {
                cout << "--- Drzewo wyrażeń binarnych ---" << endl;
	            cout << "Wprowadź wyrażenie: ";
	            string infiks;
	            cin >> infiks;
	            if (!czyPoprawny(infiks))
                {
		            cout << "Wyrażenie może zawierać tylko: (1-9 , ( , ) , + , - , * , / , % , ^ )" << endl;
	            }
	            char *postfiks = (char *)malloc(sizeof(char) *infiks.length());
	            konwertujWsteczne(infiks, postfiks);
	            wyrazenieDrzewo drzewo1 = NULL;
                drzewo1 = zbudujDrzewo(drzewo1, postfiks);
	            przechodzenieDrzewa(drzewo1, postfiks);
                wyswietlanieWyniku(postfiks, drzewo1);
                return 0;
            }
                break;
            case 2:
            {
                return 0;
            }
        }
    }
    return 0;
}