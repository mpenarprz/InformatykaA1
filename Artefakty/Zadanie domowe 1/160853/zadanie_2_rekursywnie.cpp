
#include "pch.h"
#include <iostream>
using namespace std;

int silnia(int n);				// funkcja rekursywna licząca silnie n elementów

int main()
{
	int n;

	cout << " Podaj liczbe N: " << endl;
	cin >> n;
	cout << "Silnia n elementow: " << silnia(n);
	silnia(1); // SZACH MAT
	return 0;

}

int silnia(int n) {
	if (n == 2) {
		return 2;
	}
	else {
		return n * silnia(n - 1);
	}
}
