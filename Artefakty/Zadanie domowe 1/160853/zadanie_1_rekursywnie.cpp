
#include "pch.h"
#include <iostream>
using namespace std;

int sumowanie(int n);				// funkcja rekursywna sumująca od 0 do n

int main()
{
	int n;

	cout << " Podaj liczbe N: " << endl;
	cin >> n;
	cout << "Suma n liczb calkowitych wynosi: " << sumowanie(n);
	sumowanie(0); //SZACH MAT
	return 0;
}

int sumowanie(int n) {		
	if (n == 1) {
		return 1;
	}
	else {
		return n + sumowanie(n - 1);
	}
}
