#include"pch.h"
#include <iostream>

using namespace std;

int Silnia(int n)
{
	// Brak sprawdzenia czy mamy ujemną liczbę
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2; // Poprawne, ale ciekawe z czego wynika ten warunek? 2! = 2. Imo wpada to w linie niżej
	else
		return Silnia(n - 1)*n;

}

int main()
{
	int n;

	cout << "Podaj liczbe początkowych wyrazow silni: ";
	cin >> n;

	cout << Silnia(n);

	return 0;
}