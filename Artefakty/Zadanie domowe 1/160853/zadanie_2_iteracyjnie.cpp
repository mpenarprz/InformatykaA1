
#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int n;

	cout << "Podaj liczbe N" << endl;
	cin >> n;

	int silnia = 1;

	for (int i = 1; i <= n; i++) {			// silnia n elementów
		silnia *= i;					// Przyjemnie że zastosowany skrót
	}

	cout << "Silnia n elementow wynosi: " << silnia << endl;

	return 0;
}


/*
To nie jest funkcja
*/