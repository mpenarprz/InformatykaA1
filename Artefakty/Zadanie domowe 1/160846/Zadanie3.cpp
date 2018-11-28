// Zadanie3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int liczba;
	vector <int> vec; // potrzebna biblioteka <vector>
	/*
	Nieprawda, niepotrzebna :P
	*/
	
	cout << "Podaj liczby: " << endl;
	
	do {

		cin >> liczba;

		if (liczba != -1) {

			if(liczba<5000 && liczba>0) vec.push_back(liczba); //dodawanie elementu na koniec tablicy
		}

	} while (liczba != -1);

	sort(vec.begin(), vec.end()); //sortowanie rosnąco, potrzebna biblioteka <algorithm>
	/*
	Nieprawda, niepotrzebna.
	*/
	
	cout << endl;
	cout << "Posortowana tablica: " << endl;

	for (int i = 0; i < vec.size(); i++) { //wyswietlenie posortowanych elementow tablicy
		cout << vec[i] << " ";
	}

	system("pause");
	return 0;
}
/*
Tu jest ultymatywny komentarz: jeśli stosujesz klasę vector, to nie potrzebujesz mieć ograniczenia: if(liczba<5000 && liczba>0)
Równie dobrze możesz sortować dowolny zakres liczb za pomocą: sort(vec.begin(), vec.end());

na domiar złego: sort() z <algorithm> ma złożoność obliczeniową O(N logN)... a ja by chciał ten proces wykonanać szybciej O(n).

Tu: "strzeliłeś z armaty do wróbla" - użyłeś nieproporcjonalnie potężnego narzędzia (które zawiera pewien narzut obliczeniowy) do wykonania prostej czynności.
Tak jakbyś obierał ziemniaki piłą mechaniczna.

Potrzebuje w tym zadaniu konkretnego algorytmu sortującego, a nie tylko wywołania funkcji :P
*/




// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
