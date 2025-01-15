#include<iostream>
using namespace std;

void rekurzija(int*,int,int,int);

int main()
{
	int duzina;
	cout << "Unesite velicinu niza" << endl;
	cin >> duzina;
	int* niz = new int[duzina];
	rekurzija(niz, duzina,2,0);
	for (int i = 0; i < duzina; i++)
	{
		cout << *(niz + i) << endl;
	}
	return 0;
}

void rekurzija(int* niz,int duzina,int broj,int  i)
{
	if (i == duzina || broj==INT_MAX || broj<0)
		return;
	*(niz + i) = broj;
	rekurzija(niz, duzina, broj * 2, i=i+1);
}
