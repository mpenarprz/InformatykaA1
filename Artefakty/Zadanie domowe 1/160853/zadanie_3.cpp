#include "pch.h"
#include <vector>
#include <iostream>
using namespace std;

void wczytaj(int &n);					// funkcja wczytująca dane z konsoli
void posortuj(vector<int> &liczby);						// funkcja sortująca tablice elementów

int main()
{
	int n;
	vector<int> liczby;

	wczytaj(n);

		while (n != -1) {
			if (n >= 0 && n <= 5000) {
				liczby.push_back(n);
			}
			wczytaj(n);
		}

		posortuj(liczby);								// sortowanie tablicy

		cout << endl;
		for (int i = 0; i < liczby.size(); i++) {		// petla wyswietlajcą kolejne elementy tablicy
			cout << liczby[i] << " ";
		}
	return 0;
}

void wczytaj(int &n) {
	cout << "Podaj liczbe calkowita" << endl;
	cin >> n;
	system("cls"); cout << endl << "Poprawnie wczytano liczbe!" << endl<<endl;		// czyszczenie zawartosci konsoli

}

void posortuj(vector<int> &liczby) {
	int pom; // pomocnicza zmienna
	for (int j = liczby.size(); j >= 0; j--) {
		for (int i = 1; i < liczby.size(); i++) {
			if (liczby[i-1] > liczby[i]) {
				pom = liczby[i-1];
				liczby[i-1] = liczby[i];
				liczby[i] = pom;
			}
		}
	}
	/*
	Brutal!
	Szczerze - to nie widzę że to sortuje.
	K... teraz widzę - bo bubble sort odpalasz J razy. A w pesymistycznym przypadku J razy trzeba wykonać zamianę
	*/
}