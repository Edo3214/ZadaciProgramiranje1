#include<iostream>
using namespace std;
void popuni(long long int*, int,int);
int main()
{
	int velicina;
	do
	{
		cout << "Unesi velicinu niza koja mora biti veca od 2" << endl;
		cin >> velicina;
	} while (velicina<2);
	
	long long int* niz = new long long int[velicina];
	popuni(niz, velicina,0);


	for (int i = 0; i < velicina; i++)
	{
		if (*(niz + i) < 0)
			cout << "ovdje je junk vrijednost (niza bez funkcije) jer se desio overflow" << endl;
		else
			cout << *(niz + i) << endl;
	}

	return 0;
}
void popuni(long long int* niz,int duzina,int i=0)
{
	if (duzina==i)
		return;
	if (i == 0) *(niz + i) = 1;
	else if (i == 1)*(niz + i) = 3;
	else
		*(niz + i) = *(niz+i-1)**(niz+i-2);
	
	if (*(niz + i) < 0)
		return;
	popuni(niz, duzina, i + 1);

}
