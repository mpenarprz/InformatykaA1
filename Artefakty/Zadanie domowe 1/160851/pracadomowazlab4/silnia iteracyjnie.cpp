#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int n, silnia = 1 ;

	cout << "Podaj LICZBĘ liczb do oblicznia silni: ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		silnia = silnia * i;		//Jako funkcję proszę - tu obcinam punkty
	}
	cout << silnia;

	return 0;
}