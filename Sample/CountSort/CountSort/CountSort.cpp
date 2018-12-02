#include "stdafx.h"
#include <iostream>

/************
Tu rozwiązujemy problem sortowania pewnego znanego przedziału liczb. 
*************/

/*
	Powołanie stałej (słowo const) globalnej.
	Stałe - jak sama nazwa wskazuje - nie zmieniają swojej wartości, ustalane są na etapie kompilacji, dzięki czemu kompilator może je wykorzystwać np. przy ustalaniu rozmiaru tablicy
*/
const int ROZMIAR_NASZEGO_PROBLEMU = 5000;

void sorting() {
	/*
	Tworzymy kubełki dla naszego zakresu wartości
	*/
	int tablica[ROZMIAR_NASZEGO_PROBLEMU];

	/*
	Zerowanie tablicy
	*/
	for (int i = 0; i < ROZMIAR_NASZEGO_PROBLEMU; ++i) {
		tablica[i] = 0;
	}

	/*
	Wczytujemy liczby dopóki użytkownik nie wpisze -1
	*/
	int indeks;
	do {
		std::cin >> indeks;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
		}
		else {
			if (indeks >= 0 && indeks < ROZMIAR_NASZEGO_PROBLEMU) {
				tablica[indeks]++;
			}
		}
	} while (indeks != -1);

	/*
	Wypisywanie danych
	*/
	for (int i = 0; i < ROZMIAR_NASZEGO_PROBLEMU; ++i) {
		while (tablica[i]-- > 0) {
			std::cout << i << std::endl;
		}
	}

}

void main()
{
	sorting();
}

