#include <iostream>
#include <string>
#include <unistd.h>
#include <iomanip>

using namespace std;

const int maksymalna_liczba_studentow = 50;
const int maksymalna_liczba_absolwentow = 50;
const int maksymalna_liczba_ocen = 3;
const int maksymalna_liczba_semestrow = 5;
int liczba_studentow = 0;
int pierwszy_numer_indeksu = 11111;
int liczba_absolwentow = 0;

struct Semestr {
    string nazwa_przedmiot1;
    string nazwa_przedmiot2;
    string nazwa_przedmiot3;
    string nazwa_przedmiot4;
    
    int ects_przedmiot1;
    int ects_przedmiot2;
    int ects_przedmiot3;
    int ects_przedmiot4;
    
    float oceny_przedmiot1[maksymalna_liczba_ocen];
    float oceny_przedmiot2[maksymalna_liczba_ocen];
    float oceny_przedmiot3[maksymalna_liczba_ocen];
    float oceny_przedmiot4[maksymalna_liczba_ocen];
    
    float srednia_przedmiot1;
    float srednia_przedmiot2;
    float srednia_przedmiot3;
    float srednia_przedmiot4;
    
    float liczba_ocen_przedmiot1 = 0;
    float liczba_ocen_przedmiot2 = 0;
    float liczba_ocen_przedmiot3 = 0;
    float liczba_ocen_przedmiot4 = 0;
    
    float ocena_koncowa_przedmiot1;
    float ocena_koncowa_przedmiot2;
    float ocena_koncowa_przedmiot3;
    float ocena_koncowa_przedmiot4; 
    
    float ogolna_ocena_koncowa;
};

struct Student {
    string imie;
    string nazwisko;
    int semestr;
    int numer_indeksu;
    bool czyAbsolwent = false, wszystkie_oceny, czy_mozna_przeniesc;
    Semestr aktualny_semestr;
} studenci[maksymalna_liczba_studentow];

struct Absolwenci {
    string imie;
    string nazwisko;
    int numer_indeksu;
} absolwenci[maksymalna_liczba_absolwentow];

void menu();
void pokazAbsolwentow();
float srednia_ocen(float oceny[], float ilosc);
void dodajOceny(int id);
void pokazStudentow();
void dodajSemestrPierwszy(int id);
void dodajSemestrDrugi(int id);
void dodajSemestrTrzeci(int id);
void dodajSemestrCzwarty(int id);
void dodajSemestrPiaty(int id);
void dodajStudentow(int nastepny_indeks);
void pokazOceny(int id);
void edytujStudenta(int id);
void pokazSemestr();
void sesja(int id);

int main()
{
    int dzialanie;
    bool koniec_programu = false;
    cout << endl << "WIRTUALNY SYSTEM DZIEKANATU" << endl;
    menu();
    do
    {
        cout << ">>> ";
        cin >> dzialanie;
        switch (dzialanie)
        {
            case 1:
                pokazStudentow();
                int dzialanie;
                int id;
                cout << ">>> ";
                cin >> dzialanie;
                switch (dzialanie)
                {
                    case 1:
                        dodajStudentow(liczba_studentow);
                        break;
                    case 2:
                        cout << "Podaj numer ID: ";
                        cin >> id;
                        edytujStudenta(id);
                        break;
                    case 3:
                        cout << "Podaj numer ID: ";
                        cin >> id;
                        pokazOceny(id);
                        break;
                    case 4:
                        menu();
                        break;
                    case 0:
                        koniec_programu = true;
                        break;
                    default:
                        cout << "Wystąpił błąd." << endl;
                        break;
                }
                break;
            case 2:
                pokazSemestr();
                break;
            case 3:
                pokazAbsolwentow();
                break;
            case 4:
                koniec_programu = true;
                break;
            default:
                cout << "Wystąpił błąd." << endl;
                menu();
                break;
        }       
    }
    while(!koniec_programu);
    return 0;
}

void menu()
{
    cout << endl << "--- MENU SYSTEMU ---" << endl;
    cout << "====================================" << endl;
    cout << "1. Studenci." << endl;
    cout << "2. Wyświetl semestry." << endl;
    cout << "3. Wyświetl listę absolwentów." << endl;
    cout << "4. Zamknięcie programu." << endl;
}

void pokazAbsolwentow()
{
    if(liczba_absolwentow != 0) 
    {
        cout << endl << "Imię | Nazwisko | Numer indeksu" << endl;
        for (int  i = 0; i < liczba_absolwentow; i++) 
        {
            cout << absolwenci[i].imie << " | " << absolwenci[i].nazwisko << " | " << absolwenci[i].numer_indeksu << endl;
        }
    }
    else
    {
        cout << "Brak absolwentów na liście." << endl;
    }
    menu();
}

float srednia_ocen (float oceny[], float ilosc)
{
    int oceny_sum = 0;
    for (int i = 0; i < ilosc; i++)
    {
        oceny_sum += oceny[i]; 
    }
    return oceny_sum / ilosc;
}

void dodajOceny(int id)
{
    int dzialanie;
    cout << endl << "Jaki przedmiot chcesz wybrać, by przypisać ocenę?" << endl;
    cout << "1. " << studenci[id].aktualny_semestr.nazwa_przedmiot1 << endl;
    cout << "2. " << studenci[id].aktualny_semestr.nazwa_przedmiot2 << endl;
    cout << "3. " << studenci[id].aktualny_semestr.nazwa_przedmiot3 << endl;
    cout << "4. " << studenci[id].aktualny_semestr.nazwa_przedmiot4 << endl;
    cout << ">>> ";
    cin >> dzialanie;
    switch (dzialanie) 
    {
        case 1:
        {
            float ocena1;
            int wybor1, ocena_numer1;
            
            bool petla1 = false;
            
            cout << "Wybierz rodzaj oceny." << endl;
            cout << "1. Ocena w terminie zerowym." << endl;
            cout << "2. Ocena w terminie poprawkowym." << endl;
            cin >> wybor1;
            switch (wybor1)
            {
                case 1:
                    cout << "Wpisz ocenę: ";
                    cin >> ocena1;
                    for (int i = 0; i < sizeof(studenci[id].aktualny_semestr.oceny_przedmiot1) / sizeof(float); i++)
                    {
                        if (studenci[id].aktualny_semestr.oceny_przedmiot1[i] == 0)
                        {
                            studenci[id].aktualny_semestr.oceny_przedmiot1[i] = ocena1;
                            petla1 = true;
                            studenci[id].aktualny_semestr.liczba_ocen_przedmiot1++;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    if (!petla1) 
                    {
                        cout << "Wystąpił błąd. Nie można wpisać więcej ocen." << endl;
                        usleep(1000000);
                    }
                    break;
                case 2:
                    cout << "Jaką ocenę chcesz poprawić? (1), (2), (3)." << endl << ">>> ";
                    cin >> ocena_numer1;
                    cout << "Wpisz ocenę: ";
                    cin >> ocena1;
                    studenci[id].aktualny_semestr.oceny_przedmiot1[ocena_numer1 - 1] = ocena1;
                    break;
                default:
                    cout << "Wystąpił błąd." << endl;
                    break;
            }
            break;
        }
        case 2:
        {
            float ocena2;
            int wybor2, ocena_numer2;
            bool petla2 = false;
            cout << "Wybierz rodzaj oceny" << endl;
            cout << "1. Ocena w terminie zerowym." << endl;
            cout << "2. Ocena w terminie poprawkowym." << endl;
            cin >> wybor2;
            switch (wybor2)
            {
                case 1:
                    cout << "Wpisz ocenę: ";
                    cin >> ocena2;
                    for (int i = 0; i < sizeof(studenci[id].aktualny_semestr.oceny_przedmiot2) / sizeof(float); i++)
                    {
                        if (studenci[id].aktualny_semestr.oceny_przedmiot2[i] == 0)
                        {
                            studenci[id].aktualny_semestr.oceny_przedmiot2[i] = ocena2;
                            petla2 = true;
                            studenci[id].aktualny_semestr.liczba_ocen_przedmiot2++;
                            break;
                        }
                        else 
                        {
                            continue;
                        }
                    }
                    if (!petla2) 
                    {
                        cout << "Wystąpił błąd. Nie można wpisać więcej ocen." << endl;
                        usleep(1000000);
                    }
                    break;
                case 2:
                    cout << "Jaką ocenę chcesz poprawić? (1), (2), (3)." << endl << ">>> ";
                    cin >> ocena_numer2;
                    cout << "Wpisz ocenę: ";
                    cin >> ocena2;
                    studenci[id].aktualny_semestr.oceny_przedmiot2[ocena_numer2 - 1] = ocena2;
                    break;
                default:
                    cout << "Wystąpił błąd." << endl;
                    break;
            }
            break;
        }
        case 3: 
        {
            float ocena3;
            int wybor3, ocena_numer3;
            bool petla3 = false;
            cout << "Wybierz rodzaj oceny" << endl;
            cout << "1. Ocena w terminie zerowym." << endl;
            cout << "2. Ocena w terminie poprawkowym." << endl;
            cin >> wybor3;
            switch (wybor3) 
            {
                case 1:
                    cout << "Wpisz ocenę: ";
                    cin >> ocena3;
                    for (int i = 0; i < sizeof(studenci[id].aktualny_semestr.oceny_przedmiot3) / sizeof(float); i++) 
                    {
                        if (studenci[id].aktualny_semestr.oceny_przedmiot3[i] == 0)
                        {
                            studenci[id].aktualny_semestr.oceny_przedmiot3[i] = ocena3;
                            petla3 = true;
                            studenci[id].aktualny_semestr.liczba_ocen_przedmiot3++;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    if(!petla3) 
                    {
                        cout << "Wystąpił błąd. Nie można wpisać więcej ocen." << endl;
                        usleep(1000000);
                    }
                    break;
                case 2:
                    cout << "Jaką ocenę chcesz poprawić? (1), (2), (3)." << endl << ">>> ";
                    cin >> ocena_numer3;
                    cout << "Wpisz ocenę: ";
                    cin >> ocena3;
                    studenci[id].aktualny_semestr.oceny_przedmiot3[ocena_numer3 - 1] = ocena3;
                    break;
                default:
                    cout << "Wystąpił błąd." << endl;
                    break;
            }
            break;
        }
        case 4:
        {
            float ocena4;
            int wybor4, ocena_numer4;
            bool petla4 = false;
            cout << "Wybierz rodzaj oceny" << endl;
            cout << "1. Ocena w terminie zerowym." << endl;
            cout << "2. Ocena w terminie poprawkowym." << endl;
            cin >> wybor4;
            switch (wybor4) 
            {
                case 1:
                    cout << "Wpisz ocenę: ";
                    cin >> ocena4;
                    for (int i = 0; i < sizeof(studenci[id].aktualny_semestr.oceny_przedmiot4) / sizeof(float); i++) 
                    {
                        if (studenci[id].aktualny_semestr.oceny_przedmiot4[i] == 0)
                        {
                            studenci[id].aktualny_semestr.oceny_przedmiot4[i] = ocena4;
                            petla4 = true;
                            studenci[id].aktualny_semestr.liczba_ocen_przedmiot4++;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    if (!petla4)
                    {
                        cout << "Wystąpił błąd. Nie można wpisać więcej ocen." << endl;
                        usleep(1000000);
                    }
                    break;
                case 2:
                    cout << "Jaką ocenę chcesz poprawić? (1), (2), (3)." << endl << ">>> ";
                    cin >> ocena_numer4;
                    cout << "Wpisz ocenę: ";
                    cin >> ocena4;
                    studenci[id].aktualny_semestr.oceny_przedmiot4[ocena_numer4 - 1] = ocena4;
                    break;
                default:
                    cout << "Wystąpił błąd." << endl;
            }
            break;
        }
        default:
            cout << "Wystąpił błąd." << endl;
            break;
    }
    
    studenci[id].aktualny_semestr.srednia_przedmiot1 = srednia_ocen(studenci[id].aktualny_semestr.oceny_przedmiot1, studenci[id].aktualny_semestr.liczba_ocen_przedmiot1);
    studenci[id].aktualny_semestr.srednia_przedmiot2 = srednia_ocen(studenci[id].aktualny_semestr.oceny_przedmiot2, studenci[id].aktualny_semestr.liczba_ocen_przedmiot2);
    studenci[id].aktualny_semestr.srednia_przedmiot3 = srednia_ocen(studenci[id].aktualny_semestr.oceny_przedmiot3, studenci[id].aktualny_semestr.liczba_ocen_przedmiot3);
    studenci[id].aktualny_semestr.srednia_przedmiot4 = srednia_ocen(studenci[id].aktualny_semestr.oceny_przedmiot4, studenci[id].aktualny_semestr.liczba_ocen_przedmiot4);
    
    if (studenci[id].aktualny_semestr.liczba_ocen_przedmiot1 == maksymalna_liczba_ocen && studenci[id].aktualny_semestr.liczba_ocen_przedmiot2 == maksymalna_liczba_ocen && studenci[id].aktualny_semestr.liczba_ocen_przedmiot3 == maksymalna_liczba_ocen && studenci[id].aktualny_semestr.liczba_ocen_przedmiot4 == maksymalna_liczba_ocen) 
    {
        studenci[id].wszystkie_oceny = true;
    }
}

void pokazStudentow()
{
    cout << endl << "Numer ID | Imię | Nazwisko | Numer indeksu | Aktualny semestr" << endl;
    for (int i = 0; i < liczba_studentow; i++)
    {
        cout << "[" << i << "] | " << studenci[i].imie << " | " << studenci[i].nazwisko << " | " << studenci[i].numer_indeksu << " | " << studenci[i].semestr << endl;
    }
    cout << "====================================" << endl;
    cout << "1. Dodaj studenta." << endl;
    cout << "2. Edytuj studenta." << endl;
    cout << "3. Wyświetl oceny studenta." << endl;
    cout << "4. Powrót do menu." << endl;
    cout << "0. Zamknięcie programu." << endl;
}

void dodajSemestrPierwszy(int id)
{
    studenci[id].aktualny_semestr.nazwa_przedmiot1 = "Algebra liniowa.";
    studenci[id].aktualny_semestr.ects_przedmiot1 = 6;
    studenci[id].aktualny_semestr.nazwa_przedmiot2 = "Podstawy programowania.";
    studenci[id].aktualny_semestr.ects_przedmiot2 = 6;
    studenci[id].aktualny_semestr.nazwa_przedmiot3 = "Inżynieria oprogramowania.";
    studenci[id].aktualny_semestr.ects_przedmiot3 = 6;
    studenci[id].aktualny_semestr.nazwa_przedmiot4 = "Wychowanie fizyczne.";
    studenci[id].aktualny_semestr.ects_przedmiot4 = 4;
    
    for (int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot1[i] = 0;
    }
    
    for(int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot2[i] = 0;
    }

    for (int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot3[i] = 0;
    }

    for(int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot4[i] = 0;
    }

    studenci[id].aktualny_semestr.ogolna_ocena_koncowa = 0;
}

void dodajSemestrDrugi(int id) 
{
    studenci[id].aktualny_semestr.nazwa_przedmiot1 = "Matematyka elementarna.";
    studenci[id].aktualny_semestr.ects_przedmiot1 = 6;
    studenci[id].aktualny_semestr.nazwa_przedmiot2 = "Wytwarzanie aplikacji internetowych.";
    studenci[id].aktualny_semestr.ects_przedmiot2 = 4;
    studenci[id].aktualny_semestr.nazwa_przedmiot3 = "Platformy technologiczne.";
    studenci[id].aktualny_semestr.ects_przedmiot3 = 4;
    studenci[id].aktualny_semestr.nazwa_przedmiot4 = "Grafika komputerowa.";
    studenci[id].aktualny_semestr.ects_przedmiot4 = 6;
    
    for (int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot1[i] = 0;
    }

    for (int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot2[i] = 0;
    }

    for (int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot3[i] = 0;
    }
    
    for(int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot4[i] = 0;
    }

    studenci[id].aktualny_semestr.ogolna_ocena_koncowa = 0;
}

void dodajSemestrTrzeci(int id)
{
    studenci[id].aktualny_semestr.nazwa_przedmiot1 = "Układy cyfrowe.";
    studenci[id].aktualny_semestr.ects_przedmiot1 = 6;
    studenci[id].aktualny_semestr.nazwa_przedmiot2 = "Algorytmy i struktury danych.";
    studenci[id].aktualny_semestr.ects_przedmiot2 = 5;
    studenci[id].aktualny_semestr.nazwa_przedmiot3 = "Programowanie obiektowe.";
    studenci[id].aktualny_semestr.ects_przedmiot3 = 3;
    studenci[id].aktualny_semestr.nazwa_przedmiot4 = "Fizyka współczesna.";
    studenci[id].aktualny_semestr.ects_przedmiot4 = 4;
    
    for (int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot1[i] = 0;
    }

    for(int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot2[i] = 0;
    }

    for (int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot3[i] = 0;
    }

    for(int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot4[i] = 0;
    }

    studenci[id].aktualny_semestr.ogolna_ocena_koncowa = 0;
}

void dodajSemestrCzwarty(int id)
{
    studenci[id].aktualny_semestr.nazwa_przedmiot1 = "Architektura komputerów.";
    studenci[id].aktualny_semestr.ects_przedmiot1 = 3;
    studenci[id].aktualny_semestr.nazwa_przedmiot2 = "Sztuczna inteligencja.";
    studenci[id].aktualny_semestr.ects_przedmiot2 = 4;
    studenci[id].aktualny_semestr.nazwa_przedmiot3 = "Hipertekst i hipermedia.";
    studenci[id].aktualny_semestr.ects_przedmiot3 = 5;
    studenci[id].aktualny_semestr.nazwa_przedmiot4 = "Sieci komputerowe.";
    studenci[id].aktualny_semestr.ects_przedmiot4 = 5;
    
    for (int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot1[i] = 0;
    }

    for (int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot2[i] = 0;
    }

    for (int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot3[i] = 0;
    }
    
    for (int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot4[i] = 0;
    }
    
    studenci[id].aktualny_semestr.ogolna_ocena_koncowa = 0;
}

void dodajSemestrPiaty(int id)
{
    studenci[id].aktualny_semestr.nazwa_przedmiot1 = "Systemy operacyjne.";
    studenci[id].aktualny_semestr.ects_przedmiot1 = 3;
    studenci[id].aktualny_semestr.nazwa_przedmiot2 = "Multimedia i interfejsy.";
    studenci[id].aktualny_semestr.ects_przedmiot2 = 5;
    studenci[id].aktualny_semestr.nazwa_przedmiot3 = "Humanistyka dla inżynierów.";
    studenci[id].aktualny_semestr.ects_przedmiot3 = 2;
    studenci[id].aktualny_semestr.nazwa_przedmiot4 = "Przetwarzanie rozproszone.";
    studenci[id].aktualny_semestr.ects_przedmiot4 = 2;
    
    for (int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot1[i] = 0;
    }

    for(int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot2[i] = 0;
    }

    for(int i = 0; i < maksymalna_liczba_ocen; i++)
    {
        studenci[id].aktualny_semestr.oceny_przedmiot3[i] = 0;
    }

    for(int i = 0; i < maksymalna_liczba_ocen; i++) 
    {
        studenci[id].aktualny_semestr.oceny_przedmiot4[i] = 0;
    }

    studenci[id].aktualny_semestr.ogolna_ocena_koncowa = 0;
}

void dodajStudentow(int nastepny_indeks)
{
    int semestr;
    cout << endl << "Wprowadź dane nowego studenta." << endl;
    cout << "Imię: ";
    cin >> studenci[nastepny_indeks].imie;
    cout << "Nazwisko: ";
    cin >> studenci[nastepny_indeks].nazwisko;
    cout << "Semestr: ";
    cin >> semestr;
    studenci[nastepny_indeks].semestr = semestr;
    
    switch (semestr) 
    {
        case 1:
            dodajSemestrPierwszy(nastepny_indeks);
            break;
        case 2:
            dodajSemestrDrugi(nastepny_indeks);
            break;
        case 3:
            dodajSemestrTrzeci(nastepny_indeks);
            break;
        case 4:
            dodajSemestrCzwarty(nastepny_indeks);
            break;
        case 5:
            dodajSemestrPiaty(nastepny_indeks);
            break;
        default:
            cout << "Wystąpił błąd." << endl;
    }

    studenci[nastepny_indeks].numer_indeksu = pierwszy_numer_indeksu;
    studenci[nastepny_indeks].wszystkie_oceny = false;
    studenci[nastepny_indeks].czy_mozna_przeniesc = false;
    pierwszy_numer_indeksu++;
    liczba_studentow++;
    menu();
}

void pokazOceny(int id)
{
    cout << endl << "Oceny studenta: " << studenci[id].imie << " " << studenci[id].nazwisko << " (0 - brak)" << endl << endl;
    cout << studenci[id].aktualny_semestr.nazwa_przedmiot1 << " - | ";
    for (int i = 0; i < sizeof(studenci[id].aktualny_semestr.oceny_przedmiot1) / sizeof(float); i++)
    {
        if (i == maksymalna_liczba_ocen - 1)
        {
            cout << studenci[id].aktualny_semestr.oceny_przedmiot1[i];
        }
        else
        {
            cout << studenci[id].aktualny_semestr.oceny_przedmiot1[i] << " | ";
        }   
    }
    if (studenci[id].aktualny_semestr.liczba_ocen_przedmiot1 != 0)
    {
        cout << " | Średnia ocen: " << setprecision(3) <<studenci[id].aktualny_semestr.srednia_przedmiot1;
    }
    cout << " | ECTS: " << studenci[id].aktualny_semestr.ects_przedmiot1 << endl;
    cout << studenci[id].aktualny_semestr.nazwa_przedmiot2 << " - | ";
    for (int i = 0; i < sizeof(studenci[id].aktualny_semestr.oceny_przedmiot2) / sizeof(float); i++)
    {
        if (i == maksymalna_liczba_ocen - 1)
        {
            cout << studenci[id].aktualny_semestr.oceny_przedmiot2[i];
        }
        else
        {
            cout << studenci[id].aktualny_semestr.oceny_przedmiot2[i] << " | ";
        }
    }
    if (studenci[id].aktualny_semestr.liczba_ocen_przedmiot2 != 0) 
    {
        cout << " | Średnia ocen: " << setprecision(3) <<studenci[id].aktualny_semestr.srednia_przedmiot2;
    }
    cout << " | ECTS = " << studenci[id].aktualny_semestr.ects_przedmiot2 << endl;
    cout << studenci[id].aktualny_semestr.nazwa_przedmiot3 << " - | ";
    for (int i = 0; i < sizeof(studenci[id].aktualny_semestr.oceny_przedmiot3) / sizeof(float); i++)
    {
        if (i == maksymalna_liczba_ocen - 1)
        {
            cout << studenci[id].aktualny_semestr.oceny_przedmiot3[i];
        }
        else
        {
            cout << studenci[id].aktualny_semestr.oceny_przedmiot3[i] << " | ";
        }
    }
    if (studenci[id].aktualny_semestr.liczba_ocen_przedmiot3 != 0)
    {
        cout << " | Średnia ocen: " << setprecision(3) <<studenci[id].aktualny_semestr.srednia_przedmiot3;
    }
    cout << " | ECTS = " << studenci[id].aktualny_semestr.ects_przedmiot3 << endl;
    cout << studenci[id].aktualny_semestr.nazwa_przedmiot4 << " - | ";
    for (int i = 0; i < sizeof(studenci[id].aktualny_semestr.oceny_przedmiot4) / sizeof(float); i++)
    {
        if (i == maksymalna_liczba_ocen - 1)
        {
            cout << studenci[id].aktualny_semestr.oceny_przedmiot4[i];
        }
        else
        {
            cout << studenci[id].aktualny_semestr.oceny_przedmiot4[i] << " | ";
        }
    }
    if (studenci[id].aktualny_semestr.liczba_ocen_przedmiot4 != 0)
    {
        cout << " | Średnia ocen: " << setprecision(3) <<studenci[id].aktualny_semestr.srednia_przedmiot4;
    }
    cout << " | ECTS = " << studenci[id].aktualny_semestr.ects_przedmiot4 << endl;
    usleep(2000000);
    menu();
}

void edytujStudenta(int id)
{
    int dzialanie;
    cout << endl << "Wybierz działanie: " << endl;
    cout << "1. Edytuj dane studenta." << endl;
    cout << "2. Przenieś studenta na następny semestr." << endl;
    cout << "3. Dodaj ocenę studentowi." << endl;
    cout << "4. Usuń studenta z listy." << endl;
    cout << "5. Zakończ sesję studentowi." << endl;
    cout << ">>> ";
    cin >> dzialanie;
    switch (dzialanie)
    {
        case 1:
            cout << "Wprowadź zaktualizowane dane studenta" << endl;
            cout << "Imię: ";
            cin >> studenci[id].imie;
            cout << "Nazwisko: ";
            cin >> studenci[id].nazwisko;
            break;
        case 2:
            if (!studenci[id].czyAbsolwent && studenci[id].czy_mozna_przeniesc)
            {
                if (studenci[id].semestr == 1)
                {
                    studenci[id].semestr = 2;
                    cout << "Student " << studenci[id].imie << " " << studenci[id].nazwisko << " został skutecznie przeniesiony na 2 semestr." << endl;
                    dodajSemestrDrugi(id);
                    studenci[id].wszystkie_oceny = false;
                }
                else if(studenci[id].semestr == 2)
                {
                    studenci[id].semestr = 3;
                    cout << "Student " << studenci[id].imie << " " << studenci[id].nazwisko << " został skutecznie przeniesiony na 3 semestr." << endl;
                    dodajSemestrTrzeci(id);
                    studenci[id].wszystkie_oceny = false;
                }
                else if (studenci[id].semestr == 3) {
                    studenci[id].semestr = 4;
                    cout << "Student " << studenci[id].imie << " " << studenci[id].nazwisko << " został skutecznie przeniesiony na 4 semestr." << endl;
                    dodajSemestrCzwarty(id);
                    studenci[id].wszystkie_oceny = false;
                }
                else if (studenci[id].semestr == 4)
                {
                    studenci[id].semestr = 5;
                    cout << "Student " << studenci[id].imie << " " << studenci[id].nazwisko << " został skutecznie przeniesiony na 5 semestr." << endl;
                    dodajSemestrPiaty(id);
                    studenci[id].wszystkie_oceny = false;
                }
                else if (studenci[id].semestr == 5)
                {
                    studenci[id].czyAbsolwent = true;
                    cout << "Student ukończył studia i został przeniesiony na listę absolwentów." << endl;
                    absolwenci[liczba_absolwentow].imie = studenci[id].imie;
                    absolwenci[liczba_absolwentow].nazwisko = studenci[id].nazwisko;
                    absolwenci[liczba_absolwentow].numer_indeksu = studenci[id].numer_indeksu;
                    
                    for (int i = id; i < sizeof(studenci) / sizeof(studenci[0]); i++)
                    {
                        studenci[i] = studenci[i + 1];
                    }
                    liczba_absolwentow++;
                    liczba_studentow--;
                }
            }
            else if (studenci[id].czyAbsolwent == true) 
            {
                cout << "Wystąpił błąd. Student jest już absolwentem. Widnieje na liście absolwentów." << endl;
            }
            else if (studenci[id].czy_mozna_przeniesc == false)
            {
                cout << "Wystąpił błąd. Student nie zaliczył wszystkich obowiązkowych przedmiotów." << endl;
            }
            break;
        case 3:
            dodajOceny(id);
            break;
        case 4:
            for (int i = id; i < sizeof(studenci) / sizeof(studenci[0]); i++)
            {
                studenci[i] = studenci[i + 1];
            }
            liczba_studentow--;
            break;
        case 5:
            sesja(id);
            break;
        default:
            cout << "Wystąpił błąd." << endl;
    }
    menu(); 
}

void pokazSemestr() 
{
    cout << endl << "====================================" << endl;
    cout << "SEMESTR 1" << endl;
    cout << "====================================" << endl;
    cout << "Przedmiot 1 - Algebra liniowa; ECTS - 6" << endl;
    cout << "Przedmiot 2 - Podstawy programowania.; ECTS - 6" << endl;
    cout << "Przedmiot 3 - Inżynieria oprogramowania.; ECTS - 6" << endl;
    cout << "Przedmiot 4 - Wychowanie fizyczne; ECTS - 4" << endl;
    cout << "====================================" << endl;
    cout << "SEMESTR 2" << endl;
    cout << "====================================" << endl;
    cout << "Przedmiot 1 - Matematyka elementarna; ECTS - 6" << endl;
    cout << "Przedmiot 2 - Wytwarzanie aplikacji internetowych; ECTS - 4" << endl;
    cout << "Przedmiot 3 - Platformy technologiczne; ECTS - 4" << endl;
    cout << "Przedmiot 4 - Grafika komputerowa.; ECTS - 6" << endl;
    cout << "====================================" << endl;
    cout << "SEMESTR 3" << endl;
    cout << "====================================" << endl;
    cout << "Przedmiot 1 - Układy cyfrowe; ECTS - 6" << endl;
    cout << "Przedmiot 2 - Algorytmy i struktury danych; ECTS - 5" << endl;
    cout << "Przedmiot 3 - Programowanie obiektowe; ECTS - 3" << endl;
    cout << "Przedmiot 4 - Fizyka współczesna.; ECTS - 4" << endl;
    cout << "====================================" << endl;
    cout << "SEMESTR 4" << endl;
    cout << "====================================" << endl;
    cout << "Przedmiot 1 - Architektura komputerów.; ECTS - 3" << endl;
    cout << "Przedmiot 2 - Sztuczna inteligencja.; ECTS - 4" << endl;
    cout << "Przedmiot 3 - Hipertekst i hipermedia.; ECTS - 5" << endl;
    cout << "Przedmiot 4 - Sieci komputerowe; ECTS - 5" << endl;
    cout << "====================================" << endl;
    cout << "SEMESTR 5" << endl;
    cout << "====================================" << endl;
    cout << "Przedmiot 1 - Systemy operacyjne; ECTS - 3" << endl;
    cout << "Przedmiot 2 - Multimedia i interfejsy; ECTS - 5" << endl;
    cout << "Przedmiot 3 - Humanistyka dla inżynierów.; ECTS - 2" << endl;
    cout << "Przedmiot 4 - Przetwarzanie rozproszone.; ECTS - 2" << endl;
    cout << "====================================" << endl;
    usleep(3000000);
    menu();
}

void sesja(int id)
{
    int my_sum = 0;
    if (studenci[id].wszystkie_oceny)
    {
        cout << "Wyniki sesji studenta: " << studenci[id].imie << " " << studenci[id].nazwisko << "Do zaliczenia potrzebna jest przynajmniej ocena dostateczna (3)." << endl << endl;
        if (studenci[id].aktualny_semestr.srednia_przedmiot1 <= 2.50) 
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot1 = 2;
        }
        if (studenci[id].aktualny_semestr.srednia_przedmiot1 >= 2.51 && studenci[id].aktualny_semestr.srednia_przedmiot1 <= 3.50)
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot1 = 3; 
            my_sum += 1;
        }
        if (studenci[id].aktualny_semestr.srednia_przedmiot1 >= 3.51 && studenci[id].aktualny_semestr.srednia_przedmiot1 <= 4.50)
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot1 = 4; 
            my_sum += 1;
        }
        if(studenci[id].aktualny_semestr.srednia_przedmiot1 >= 4.51)
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot1 = 5; 
            my_sum += 1;
        }
        cout << "Przedmiot 1 (" << studenci[id].aktualny_semestr.nazwa_przedmiot1 << ")" << " - ocena końcowa: " << studenci[id].aktualny_semestr.ocena_koncowa_przedmiot1 << endl;
        if (studenci[id].aktualny_semestr.srednia_przedmiot2 <= 2.50)
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot2 = 2;
        }
        if (studenci[id].aktualny_semestr.srednia_przedmiot2 >= 2.51 && studenci[id].aktualny_semestr.srednia_przedmiot2 <= 3.50)
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot2 = 3; 
            my_sum += 1;
        }
        if (studenci[id].aktualny_semestr.srednia_przedmiot2 >= 3.51 && studenci[id].aktualny_semestr.srednia_przedmiot2 <= 4.50)
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot2 = 4; 
            my_sum += 1;
        }
        if (studenci[id].aktualny_semestr.srednia_przedmiot2 >= 4.51)
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot2 = 5; 
            my_sum += 1;
        }
        cout << "Przedmiot 2 (" << studenci[id].aktualny_semestr.nazwa_przedmiot2 << ")" << " - ocena końcowa: " << studenci[id].aktualny_semestr.ocena_koncowa_przedmiot2 << endl;
        if (studenci[id].aktualny_semestr.srednia_przedmiot3 <= 2.50)
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot3 = 2;
        }
        if (studenci[id].aktualny_semestr.srednia_przedmiot3 >= 2.51 && studenci[id].aktualny_semestr.srednia_przedmiot3 <= 3.50)
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot3 = 3; 
            my_sum += 1;
        }
        if (studenci[id].aktualny_semestr.srednia_przedmiot3 >= 3.51 && studenci[id].aktualny_semestr.srednia_przedmiot3 <= 4.50)
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot3 = 4; 
            my_sum += 1;
        }
        if (studenci[id].aktualny_semestr.srednia_przedmiot3 >= 4.51)
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot3 = 5; 
            my_sum += 1;
        }
        cout << "Przedmiot 3 (" << studenci[id].aktualny_semestr.nazwa_przedmiot3 << ")" << " - ocena końcowa: " << studenci[id].aktualny_semestr.ocena_koncowa_przedmiot3 << endl;
        if (studenci[id].aktualny_semestr.srednia_przedmiot4 <= 2.50)
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot4 = 2;
        }
        if (studenci[id].aktualny_semestr.srednia_przedmiot4 >= 2.51 && studenci[id].aktualny_semestr.srednia_przedmiot4 <= 3.50)
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot4 = 3; 
            my_sum += 1;
        }
        if (studenci[id].aktualny_semestr.srednia_przedmiot4 >= 3.51 && studenci[id].aktualny_semestr.srednia_przedmiot4 <= 4.50)
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot4 = 4; 
            my_sum += 1;
        }
        if (studenci[id].aktualny_semestr.srednia_przedmiot4 >= 4.51)
        {
            studenci[id].aktualny_semestr.ocena_koncowa_przedmiot4 = 5; 
            my_sum += 1;
        }
        cout << "Przedmiot 4 (" << studenci[id].aktualny_semestr.nazwa_przedmiot4 << ")" << " - ocena końcowa: " << studenci[id].aktualny_semestr.ocena_koncowa_przedmiot4 << endl;

        studenci[id].aktualny_semestr.ogolna_ocena_koncowa = ((studenci[id].aktualny_semestr.ocena_koncowa_przedmiot1 * studenci[id].aktualny_semestr.ects_przedmiot1) + (studenci[id].aktualny_semestr.ocena_koncowa_przedmiot2 * studenci[id].aktualny_semestr.ects_przedmiot2) + (studenci[id].aktualny_semestr.ocena_koncowa_przedmiot3 * studenci[id].aktualny_semestr.ects_przedmiot3) + (studenci[id].aktualny_semestr.ocena_koncowa_przedmiot4 * studenci[id].aktualny_semestr.ects_przedmiot4)) / (studenci[id].aktualny_semestr.ects_przedmiot1 + studenci[id].aktualny_semestr.ects_przedmiot2 + studenci[id].aktualny_semestr.ects_przedmiot3 + studenci[id].aktualny_semestr.ects_przedmiot4);

        cout << endl << "Ocena końcowa ważona punktami ECTS: [" << studenci[id].aktualny_semestr.ogolna_ocena_koncowa << "]" << endl;
        if (my_sum >= 4)
        {
            studenci[id].czy_mozna_przeniesc = true;
        }
    }
    else
    {
        cout << "Student nie posiada wszystkich wymaganych ocen." << endl;
    }  
}