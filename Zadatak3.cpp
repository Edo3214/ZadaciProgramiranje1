#include<iostream>
using namespace std;

void popuni(int*, int,int);
void pretraga(int*, int, int,int);

int main()
{
	int velicina;
	cout << "Unesite velicinu niza" << endl;
	cin >> velicina;
	int* niz = new int[velicina];
	popuni(niz, velicina, 0);
	cout << "Niz je popunjem serijom fibbonaci brojeva" << endl;
	for (int i = 0; i < velicina; i++)
	{
		cout << *(niz + i) << "   ";
	}
	cout << "Unesite broj koji zelite pronaci u nizu" << endl;
	int trazenje;
	cin >> trazenje;
	pretraga(niz, velicina, trazenje, 0);
	return 0;
}

void popuni(int* niz, int velicina,int i=0)
{
	if (i == velicina)
		return;
	if (i == 0)
		*(niz + i) = 0; //ili samo *niz
	else if (i == 1)
		*(niz + i) = 1;
	else
		*(niz + i) = *(niz + i - 1) + *(niz + i - 2);
	if (*(niz + i) < 0)
		return;
	popuni(niz, velicina, i + 1);
}
void pretraga(int* niz, int velicina,int trazenje, int i = 0)
{
	if (*(niz + i) == trazenje)
	{
		cout << "Pronasli smo broj " << *(niz + i); //ovdje se moglo ispisati samo "trazenje" ali ovako osiguravamo
		return;
	}
	if (i == velicina)
	{
		cout << "Nema tog broja" << endl;
		return;
	}
	pretraga(niz, velicina, trazenje,i+1);

}
