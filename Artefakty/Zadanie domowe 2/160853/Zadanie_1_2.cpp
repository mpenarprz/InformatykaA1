

#include "pch.h"
#include <iostream>
using namespace std;

/*
V. nice....
*/
long long silnia(int n);
double sinus(float x, int n);


int main()
{	
	int n;
	float x;
	cin >> n;
	cin >> x;
	cout << sinus(x, n);
	
}


long long silnia(int n) {
	if (n > 1) {
		return n*silnia(n - 1);
	}
	else {
		return 1;
	}
}

double sinus(float x, int n) {
	if (n > 0) {
		return (sinus(x, n - 1) + (pow(-1, n) / silnia(2 * n + 1)*pow(x, (2 * n + 1))));
	}
	else {
		return x;
	}
}
/*
powyżej wszystko wygląda git.
Defensywnie rozegrane if'y - wysoko cenię.

Jedyne do czego się można czepić, to że nie liczysz Taylora z N wyrazów, tylko (chyba) z n+2
*/

/*
Zadanie 2
-------------------------------------------
// Przy 4 bajtówej architekturze
// brakuje mi tu info jak wygląda sterta - to chyba tylko na obrazku można przedstawić
void main(){
	char smth[10];		10 bajt
	int * x = new int(1);		18 bajt
	long * y = new long(5);		26 bajt
	delete x;		22 bajt
	std::cout << "hej" << std::endl; 22 bajt
}
*/