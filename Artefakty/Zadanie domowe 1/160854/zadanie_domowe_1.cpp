#include "pch.h"
#include <iostream>

using namespace std; 

int suma_r(unsigned int n) {   // 2) i jak sprytnie że unsigned int
	return n == 0 ? 0 : n + suma_r(n - 1); // 1) O jak ładnie, o jak pięknie
}
// 3) I jakie fajne formtowanie kodu!

int suma_i(unsigned int z) { 
	if (z == 0) return 0;
	int add = 0;
	for (int i = 1; i <= z; i++) {
		add += i;
	}
	return add;
}
/*
	Ad: suma_i/suma_r: bardzo sprytnie i czysto rozwiązane. Nie ma do czego się przyczepić.
	Może do : 
	if (z == 0) return 0;
	
	Na tym etapie zawsze opakowywuj w nawiasy
	if (z == 0){
		return 0;
	}
	
	Bo jeszcze kiedyś z prędkości zrobisz:
	if(z == 0); return 0; i będziesz miał szukanie średnika po (z == 0);
*/


int silnia_r(unsigned int n) {
	return n == 0 ? 1 : n==1 ? 1 : n * silnia_r(n - 1); 
}
/*
	Ad: silnia_r: Lapsus przy formatowaniu n==1 (n == 1). Ale to mój największy zarzut.
	No dobra, można było skrócić:
	return n <= 1 ? 1 : n * silnia_r(n - 1); 
*/

int silnia_i(unsigned int z) {
	int tim = 1;
	if (z == 0 || z == 1) return 1;
	for (int i = 2; i <= z; i++) {
		tim *= i;
	}
	return tim;
}
/*
	Bez komentarza.
*/

// ZAD 3
int main() {
	int x;
	int tab[5000];
	for (int i = 0; i < 5000; i++) {
		tab[i] = 0;
	}
	for (;;) {
		cin >> x;
		if (x >= 0 && x <= 5000) {
			tab[x] += 1; // Albo krócej tab[x]++ lub najkrócej i najszybciej ++tab[x];
		}
		else if (x == -1) {
			for (int z = 0; z < 5000; z++) {
				if (tab[z] > 0) {
					for (int c = 1; c <= tab[z];c++) {
						cout << z << endl;
					}
				}
				else { continue; }
				}
				//Ten for jest trochę skłapany, tj. robi to co ma robić. Ale można go skrócić do:
				/*
				for (int z = 0; z < 5000; z++) {
					while (tab[z]-- > 0) {
						cout << z << endl;
					}
				}
				*/
			break;
			}
			break;
			}
		else {
			continue;
		}
	}
}
/*
O to chodziło.
*/