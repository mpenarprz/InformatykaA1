

#include "pch.h"
#include <iostream>

using namespace std;

int sumowanie(int n){
	int suma=0;

	for (int i = 0; i <= n; i++) {			// sumowanie wszystkich elementów od 0 do n
		suma += i;			
	}
	return suma;
	
}

int main()
{
	int n;

	cout << "Podaj liczbe N" <<endl;
	cin >> n;

	int suma=0;

	for (int i = 0; i <= n; i++) {			// sumowanie wszystkich elementów od 0 do n
		suma += i;			// Przyjemnie że zastosowany skrót
	}
	
	cout << "Suma n liczb calkowitych wynosi: " << suma << endl;

	return 0;
}

/*
To nie jest funkcja
*/