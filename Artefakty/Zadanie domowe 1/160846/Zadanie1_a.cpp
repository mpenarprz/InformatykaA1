// Zadanie1_a.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>

using namespace std;

int f (int x) {
	int suma = 0;
	for (int i = 0; i <= x; i++) {		// Tu warunek i <= x zabezpiecza nas gdy użytkownik poda x = -1
		suma = suma + i; // To można skrócić do: suma += i;
	}
	return suma;
}
// Tu nie ma co komentować

int main()
{
	int n;

	do {
		cout << "Podaj nieujemne n: ";
		cin >> n;
	} while (n < 0);


	cout << "Suma n poczatkowych liczb calkowitych wynosi: " << f(n) << endl;
	cout << endl;

	system("pause");
	return 0;
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
