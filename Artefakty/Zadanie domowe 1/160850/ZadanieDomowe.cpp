#include "pch.h"
#include <iostream>
#include <vector>

//Zadanie 1
//iteracyjnie
int SumaI(int n) {
	int suma = 0;
	while (n > 0) {
		suma += n--; // Ładnie choć nieczytelnie
	}
	return suma;
}

//rekursywnie
int SumaR(int n) {
	if (n > 1) {
		return n + SumaR(n - 1); 
	}
	else {
		return 1;
	}
	
}

//Zadanie 2
//iteracyjnie
long long SilniaI(int n) {
	long long silnia = 1;
	while (n > 1) {
		silnia *= n--;
	}
	return silnia;
}

//rekursywnie
long long SilniaR(int n) {
	if (n > 2) {
		return n * SilniaR(n - 1);
	}
	else {
		return 2;	// Lekki błąd n! = 0 i n! = 1
	}
}

//Zadanie 3
//sortowanie
std::vector<int> sortuj(std::vector<int> tablica) {		//nie programujemy po polsku
	int temp,i;
	bool sorted = false;
	while (sorted == false) {
		sorted = true;
		for (i = 0; i < tablica.size()-1; i++) {		 // Masz tu złozoność O(n^2) i możesz przetworzyć jedynie 2^32 elementów 
			if (tablica[i] > tablica[i + 1]) {
				sorted = false;
				temp = tablica[i];
				tablica[i] = tablica[i + 1];
				tablica[i + 1] = temp;
			}
		}
	}
	// Stary "dobry" bubblesort

	return tablica;
}
/*
*/

//wczytywanie
void Zadanie3() {
	int input;
	std::vector<int> tab;
	std::cout << "Podaj liczbe z zakresu 0-5000" << std::endl;
	std::cin >> input;
	while (input != -1) {
		if (input >= 0 && input <= 5000) { 	// Tu jest overkill - skoro operujesz na wektorach to możesz sortować dowolny zakres liczb. Z jakiegoś powodu podany jest 0-5000. Co jakbym chciał móc posortować do 5000 * 2 ^ 32 elementów?
			tab.push_back(input);
		}
		else {
			std::cout << "Liczba poza zakresem" << std::endl;
		}
		std::cout << "Podaj liczbe z zakresu 0-5000" << std::endl;
		std::cin >> input;
	}
	tab = sortuj(tab);
	//wypisanie
	std::cout << "Posortowana tablica" << std::endl;
	for (int i = 0; i < tab.size();i++) {
		std::cout << tab[i] << std::endl;
	}
}


int main()
{
	/*
	std::cout << SumaI(10) << std::endl;
	std::cout << SumaR(10) << std::endl;
	std::cout << SilniaI(5) << std::endl;
	std::cout << SilniaR(5) << std::endl;
	*/
	Zadanie3();
}
