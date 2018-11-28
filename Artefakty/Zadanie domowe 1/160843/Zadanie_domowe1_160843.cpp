// Zadanie_domowe1_160843

#include "pch.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/*
Spisałeś się chłopie!
*/


int suma()		//Proszę to jako funkcję od N, bez wczytywania danych
{
	int n;
	int sum = 0;
	int a[1000];
	a[0] = 1;

	cout << "Podaj liczbe wyrazow sumy: "; // tego nie chce
	cin >> n;					// tego nie chce
	
	while (n <= 0) // tego nie chce
	{ // tego nie chce
		cout << "Liczba musi byc wieksza od 0" << endl << "Podaj nowa liczbe: "; // tego nie chce
		cin >> n; // tego nie chce
	} // tego nie chce
	
	for (int i = 1; i <= n; i++)
	{
		a[i] = a[0] + i;
		sum = sum + a[i];				
	}
	sum = (a[0] + a[n - 1])*n / 2;		//Tego nie trzeba. Wiadomo, istnieje wzór, ale ćwiczymy pętle. Wykonałeś obliczenia w 33 linijce... a w tej je zaorałeś
	cout <<"Suma "<<n<<" wyrazow szeregu: "<< sum<<endl;

	return(0);			// Co to robi?
}

int suma_r(int n)
{
	if (n == 0) return 0; // To rozbij na klamry
	/*
	Like this:
	if (n == 0) {
		return 0;
	}
	*/
	return suma_r(n - 1) + n;
}

int silnia() //iteracyjnie //Proszę to jako funkcję od N, bez wczytywania danych
{
	int s;
	long long silnia = 1;

	cout << "Podaj silnie: ";	// tego nie chce
	cin >> s;	// tego nie chce

	while (s <= 0)	// tego nie chce
	{	// tego nie chce
		cout << "silnia musi byc wieksza od 0" << endl << "Podaj nowa silnie: ";	// tego nie chce
		cin >> s;	// tego nie chce
	}	// tego nie chce
	
	for (int i = 1; i <= s; i++)
	{
		silnia *= i;
	}

	cout <<"Silnia "<<s<<" wyrazow wynosi: "<< silnia << endl;

	return(0);	// Co to robi?
} 

int silnia_r(int liczba)//rekurencyjnie
{
	if (liczba < 2) return liczba; // To rozbij na klamry
	/*
	Like this:
	if (liczba < 2) {
		return liczba;
	}
	*/
	return liczba * silnia_r(liczba - 1);
}

void sortowanie(int tab[],int size) // spacja pomiędzy parametrami: void sortowanie(int tab[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (tab[j] > tab[j + 1])
			{
				swap(tab[j], tab[j + 1]);
			}

		}
	}
}

int main()
{
	/*
	Rozbudowane menu. Nice.
	Od tego momentu nie czytam.
	*/
	int wybor;

	cout << "1. Suma szeregu" << endl;
	cout << "2. Silnia" << endl;
	cout << "3. Sortowanie" << endl;
	cout << "4. Wyjscie" << endl;
	cin >> wybor;

	if (wybor == 1)  //suma
	{

		int decyzja;

		cout << "1.Iteracyjnie" << endl;
		cout << "2.Rekurencyjnie" << endl;
		cin >> decyzja;
		if (decyzja == 1)
		{
			suma();
			system("Pause");
			system("cls");
			return main();
		}
		else
		{
			int n;

			cout << "Podaj liczbe wyrazow sumy: " << endl;
			cin >> n;

			cout << suma_r(n) << endl;

			system("Pause");
			system("cls");
			return main();
		}


	}
	else if (wybor == 2) //silnie
	{
		int decyzja;

		cout << "1.Iteracyjnie"<<endl;
		cout << "2.Rekurencyjnie" << endl;
		cin >> decyzja;
		if (decyzja == 1)
		{
			silnia();
			system("Pause");
			system("cls");
			return main();
		}
		else 
		{
			int s;

			cout << "Podaj liczbe: " << endl;
			cin >> s;

			cout << silnia_r(s) << endl;

			system("Pause");
			system("cls");
			return main();
		}
	}
	else if (wybor == 3)  //sortowanie
	{
		/*
		Tu wraca moja uwaga
		*/
		int l;
		
		int tablica[1000]; // Hohoh... a co jak mam 2^32 liczb?
		int *tab,n=0;

		cout << "Podaj liczby: ";
		cin >> l;

		tab = new int[n];

		while (l != -1 && l < 5000 && l>0)	//Spacje  while (l != -1 && l < 5000 && l > 0)
		{
			for (int i = 0; i <= 999; i++)
			{
				cin >> tablica[i];			
				if (tablica[i] == -1)
				{
					sortowanie(tab, n);
				}
			}
		} 
		/*
		Robi co ma robić ale dla tylko 1000 elementów :(
		*/
	
		for (int i = 0; i < n; i++) // Klamry!
			cout << tab[i] << " ";

		system("Pause");
		system("cls");
		return main();
	}
	else //wyjscie 
	{ 
		cout << "Do widzenia!" << endl;
		system("Pause");
	}
}