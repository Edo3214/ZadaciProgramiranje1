#include<iostream>
using namespace std;
void popuni(int**, int, int, int, int, int);
void ispis(int**, int, int);
int ogranici(int, int);
int main()
{
	int redovi=0, kolone=0;
	cout << "Unesi broj redova" << endl;
	redovi = ogranici(redovi, 0);
	cout << "Unesi vrijednost kolone"<<endl;
	kolone = ogranici(kolone, 0);

	//formiranje matrice
	int** matrica = new int* [redovi];
	for (int i = 0; i < redovi; i++)
		*(matrica + i) = new int[kolone];
	//end formiranje matrice

	int target=0, mjestoR, mjestoK;
	cout << "Unesi vrijednost targeta" << endl;
	target = ogranici(target, 0);
	do
	{
		cout << "Unesi red targeta" << endl;
		cin >> mjestoR;
	} while (mjestoR>redovi || mjestoR<0);
	do
	{
		cout << "Unesi kolonu targeta" << endl;
		cin >> mjestoK;
	} while (mjestoK > kolone || mjestoK < 0);
	popuni(matrica, redovi, kolone, target, mjestoR, mjestoK);
	ispis(matrica, redovi, kolone);

	return 0;
}
int ogranici(int broj, int ogranicenje)
{
	do
	{
		cout << "Unesi broj, tvoj broj mora biti veci od "<<ogranicenje << endl;
		cin >> broj;
	} while (ogranicenje>=broj);
	return broj;
}
void popuni(int** matrica, int redovi, int kolone, int target, int Tred, int Tkolona)
{
	
	for (int i = 0; i < redovi; i++)
	{
		for (int j = 0; j < kolone ; j++)
		{
			int temp = (max(abs((j - Tkolona)), abs((i - Tred))));
			
			*(*(matrica + i) + j) =max( target-temp,0);
		}
	}
}
void ispis(int** matrica, int redovi, int kolone)
{
	for (int i = 0; i < redovi; i++)
	{
		for (int j = 0; j < kolone; j++)
			cout<<*(*(matrica + i) + j)<<"   ";
		cout << endl;
	}
}
