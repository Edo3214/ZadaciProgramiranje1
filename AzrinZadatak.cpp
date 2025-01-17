#include<iostream>
using namespace std;

char* createTextFrom()
{
    cin.ignore();
    char temp[500];
    cin.getline(temp, 500);
    char* niz = new char[strlen(temp) + 1];
    strcpy_s(niz, strlen(temp), temp);
    return niz;
}

struct Vozilo
{
    char* markaVozila;
    char* nazivVozila;
    char* tipVozila;  //omoguciti unos samo A B C
    float* potrosnja_goriva_poKm;
    //sizeof()
    void unos()
    {
        
        cout << "Unesite marku vozila " << endl;
        markaVozila = createTextFrom();
        cout << "Unesite naziv vozila " << endl;
        nazivVozila = createTextFrom();
        cout << "Unesite tip vozila " << endl;
        do
        {
            tipVozila = createTextFrom(); 
        } while (!strcmp(tipVozila,"A"));
        potrosnja_goriva_poKm = new float;
        cout << "Unesite potrosnju goriva po kilometru " << endl;
        cin >> *potrosnja_goriva_poKm;
        cin.ignore();

    }
    void ispis()
    {
        cout << "Marka vozila je " << markaVozila << endl;
        cout << "Naziv vozila je " << nazivVozila << endl;
        cout << "Tip vozila je " << tipVozila << endl;
        cout << "Potrosnja po predjenom kilometru je " << *potrosnja_goriva_poKm << endl;
    }
    void dealokacija()
    {
        delete[]markaVozila;
        delete[]nazivVozila;
        delete[]tipVozila;
        markaVozila = nazivVozila = tipVozila = nullptr;
        delete potrosnja_goriva_poKm;
        potrosnja_goriva_poKm = nullptr;
    }
};

float prosjekPoFirmi(Vozilo** m, int red, int kolona)
{
    int najvecaPotrosnja = INT_MAX;
    float suma = 0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            suma += (*(*(*(m + i) + j)).potrosnja_goriva_poKm);
        }
        if (suma > najvecaPotrosnja)
            najvecaPotrosnja = suma;
        suma = i;
    }
    return suma;



}
float prosjekTipaC(Vozilo** m, int red, int kolona)
{
    float suma = 0;
    int brojac = 0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if (strcmp((*(*(m + i) + j)).tipVozila, "C") == 0)
            {
                suma += (*(*(*(m + i) + j)).potrosnja_goriva_poKm);
                brojac++;
            }
        }
    }
    if (brojac == 0)
        return 0;
    return suma /= brojac;
}

int main()
{
    int red, kolona;
    do
    {
        cout << "Unesite velicinu red i kolone " << endl;
        cin >> red >> kolona;
    } while (red <= 0 || kolona <= 0);

    Vozilo** brmbrm = new Vozilo * [red];
    for (int i = 0; i < red; i++)
    {
        *(brmbrm + i) = new Vozilo[kolona];
    }
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            (*(*(brmbrm + i) + j)).unos();
        }
    }  for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            (*(*(brmbrm + i) + j)).ispis();
        }
    }
    cout << "Prosjek vozila tipa C " << prosjekTipaC(brmbrm, red, kolona) << endl;
    cout << "Najveci prosjek potrosnje je u firmi " << prosjekPoFirmi(brmbrm, red, kolona) << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            (*(*(brmbrm + i) + j)).dealokacija();
        }
    }
    for (int i = 0; i < red; i++)
    {
        delete[] * (brmbrm + i); *(brmbrm + i) = nullptr;
    }
    delete[]brmbrm; brmbrm = nullptr;


    return 0;
}
