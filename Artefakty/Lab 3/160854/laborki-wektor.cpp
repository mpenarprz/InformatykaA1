#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct School {
	string patron;
	vector<pupil> l_ucz; // Ładnie
	vector<teacher> l_naucz; // Ładnie
};
// Może się czepiać że pupil i teacher są niezdefiniowane i trzeba je przerzucić nad School
struct pupil { // czemu pupil z małej litery, a School z dużej?
	string name, surname, sex;
};
struct teacher {// czemu teacher z małej litery, a School z dużej?
	string name, surname, sex;
};

/*
Ładnie - zgodnie z definicją
*/
int fibbonacci(int n) {
	if (n == 0) {
		return 0;
	}
	else if(n == 1) {
		return 1;
	}
	else {
		return fibbonacci(n - 1) + fibbonacci(n - 2);
	}
}

int main() {
	for (;;) {
		vector<int> fib = { 0, 1 }; // Pretty damn nice
		unsigned int x;
		cout << "wybierz liczbe ciagu fibonnaciego ";
		cin >> x;
		for (int i = 0; i < x; i++) {
			int suma = fib[i] + fib[i + 1]; // Sprytnie
			fib.push_back(suma);  
		}
		//Szkoda że nie zrobiłeś z tego funkcji
		cout << "twoja liczba to: " << fib[x] << endl;
		cout << "twoja liczba z funkcji to: " << fibbonacci(x) << endl;
	}
}

/* np tak: */

vector<int> fibonacciList(int n){
	vector<int> fib = { 0, 1 }
	for (int i = 0; i < n; i++) {
		int suma = fib[i] + fib[i + 1]; 
		fib.push_back(suma);  
	}
	return fib;
}