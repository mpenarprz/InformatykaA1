// Zadanie1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>

using namespace std;


long silnia(int n) {

	if (n <= 1) return 1;

	else return silnia(n - 1) * n;
}


float sin(float x, int n) {

	if (n > 0) {
		return ((sin(x, n - 1)) + ((pow(-1, n)) / (silnia(2 * n + 1)) * (pow(x, 2 * n + 1)))); // bardzo dużo zbędnych nawiasów. Tzw. defensywne programowanie
	}

	else return x;

}



int main()
{
	float x = 0;
	int n = 0;

	cout << "Podaj x: ";
	cin >> x;

	cout << "Podaj n: ";
	cin >> n;

	cout << "Sinus wynosi: " << sin(x, n) << endl;

}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
