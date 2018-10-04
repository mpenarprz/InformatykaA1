#include "stdafx.h"
#include <iostream>
#include <string>

/*****
W tej sekcji zamieszczam przegląd i przykłady użycia elementów języka.
*****/

/*
Kilka typów podstawowych (tzw. prymitywów), do czego służą i jak sprawdzić ich rozmiar
*/
void types() {
	// int, long, long long - typy całkowite różniące się rozmiarem
	// float, double - typy ułamkowe różniące się rozmiarem
	// bool - flaga określąca prawda/fałsz (true/false)
	// char - określający znak w kodowaniu (dom. systemowym)

	// Przykład deklaracji
	int shorter;
	// Przykład przypisania
	shorter = 1;
	// Przykład inicjalizacji
	int shorter_2 = 10;
	long long longer = 999;

	//Przykłąd operatora sizeof 
	std::cout << "Size of INT: " << sizeof(shorter_2) << std::endl;
	std::cout << "Size of Long: " << sizeof(longer) << std::endl;
}

// Funkcja licząca 2x + 1 
// wprowadzimy 2 to oczekujemy 5
// wprowadzimy 6 to oczekujemy 13
// wywołanie np.: std::cout << f(2) << std::endl;
int f(int x) {
	return 2 * x + 1;
}

/*
Skróty operacji:
*/
void shortcuts() {
	int i = 0;

	/* Inkrementacja */
	i = i + 1;
	//Można skrócić do:
	i++;
	//Lub
	++i;

	/* operacje na zmiennej */
	i = i + 12;
	i = i * 24;
	i = i / 10;
	i = i - 100;
	//Skraca się do:
	i += 12;
	i *= 24;
	i /= 10;
	i -= 100;

	// Operacja KONKATENACJI (złączenia łańcucha)
	std::string s = "abbc";
	s += "baba";
	//s to teraz abbcbaba

}

/*
Przykład wykonywania instrukcji w pętli for
*/
void testFor(int start, int stop) {
	std::cout << "Odliczamy od: " << start << " do " << stop << std::endl;
	for (int i = start; i < stop; ++i) {
		std::cout << i << std::endl;
	}
}

/*
Przykład wykonywania instrukcji w pętli for
*/
void testFor_2(int krok) {
	std::cout << "Odliczamy od: 0 do 100 z krokiem: " << krok << std::endl;
	for (int i = 0; i < 100; i += krok) {
		std::cout << i << std::endl;
	}
}

/*
Przykład wykonywania instrukcji w pętli while
*/
void whileLoop() {
	std::cout << "Odliczamy od: 0 do 100" << std::endl;
	int i = 0;
	//Jak warunek jest spełniony to ciało pętli się wykonuje
	while (i < 100) {
		std::cout << i << std::endl;
		i++;
	}
}

/*
Przykład wykonywania instrukcji w pętli do-while
*/
void doWhileLoop() {
	std::cout << "Odliczamy od: 0 do 100" << std::endl;
	int i = 0;

	do {
		std::cout << i << std::endl;
		i++;
	} while (i < 100); //Jak warunek jest spełniony to ciało pętli się powtarza
}

/*
Przykład instrukcji warunkowej sprawdzajacej czy liczba jest dodatnia
*/
const char * positive(int x) {
	if (x > 0) {
		return "TAK";
	}
	else {
		return "NIE";
	}
}

/*
Przykład operatora trójargumentowego - zwięzła forma zwracania wartości.
Efekt identyczny jak funkcja positive;
Operator trójargumentowy wykorzystujemy tylko do zwracania literałów lub zmiennych.
*/
const char * positive_2(int x) {
	return x > 0 ? "TAK" : "NIE";
}

/*
Przykład funkcji zliczającej znaki w tekście
wywołanie np.: int x = findChar("abba", 'a');
*/
int findChar(std::string input, char toCompare) {
	int count = 0;
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] == toCompare) {
			++count;
		}
	}
	return count;
}

/*
Przykład funkcji zliczającej znaki w tekście z użyciem operatora trójargumentowego: [test] ? [wartośc jak prawda] : [wartość jak fałsz] np. input[i] == toCompare ? 1 : 0
wywołanie np.: int x = findCharShorter("abba", 'a');
*/
int findCharShorter(std::string input, char toCompare) {
	int count = 0;
	//Sprawdzenie długości ciągu znaków input.length()
	for (int i = 0; i < input.length(); ++i) {
		count += input[i] == toCompare ? 1 : 0;
	}
	return count;
}

/*
Przykład funkcji zliczającej znaki w tekście z użyciem operatora trójargumentowego
Operująca na typie char *
wywołanie np.: int x = findCharShorter("abba", 'a');
*/
int findCharShorter(const char * input, char toCompare) {
	int count = 0;
	//Sprawdzenie długości ciągu znaków strlen(input)
	for (int i = 0; i < strlen(input); ++i) {
		count += input[i] == toCompare ? 1 : 0;
	}
	return count;
}



// Informacyjnie: Wskaźniki i adresacja pośrednia
void pt() {
	int x = 5;
	int * px = &x;


	std::cout << x << std::endl;
	std::cout << px << std::endl;

	(*px) = 6;
	std::cout << x << std::endl;
}


/************
Tu zamieszczam referencyjny dialog z użytkownikiem.
Załóżmy że chcemy zapytać użytkownika o imię, nazwisko oraz wiek.
Dodatkowo cynicznie chcemy skomentować wiek:
- jeśli użytkownik jest młody, tj. wiek < 20 lat to komunikat to 'That's cute... You're such a young person!"
- jeśli użytkownik jest w średnim wieku, tj. 20 <= wiek < 40 lat to komunikat to 'Oh... I though You're past 60's."
- jeśli użytkownik jest w średnim wieku, tj. 40 <= wiek to komunikat to "Have You considered writing the will?"
A jeszcze bardziej dodatkowo jako zabawny odzwierny chcemy poinformować użytkownika o tym jakie śmieszne jest jego nazwisko:
Otóż zwiera pewną liczbę liter 'a' oraz pewną liczbe liter 'e'. (Pożyczmy funkcję findCharShorter)


Musimy zagwarantować poprawność danych tj. wiek nie może być ujemny; imie i nazwisko niepuste.
Tu sprawdzenie jest minimalne
************/

int main()
{
	/*
	Deklarujemy potrzebne zmienne
	*/
	std::string name, surname;
	int age;

	std::cout << "Hai! Can you tell me Your name?" << std::endl;
	do {
		std::getline(std::cin, name);
		if (name.empty()) {
			std::cout << "I don't think it's proper name" << std::endl;
		}
	} while (name.empty());

	std::cout << "And the surname is.." << std::endl;
	do {
		std::getline(std::cin, surname);
		if (surname.empty()) {
			std::cout << "I don't think it's proper surname" << std::endl;
		}
	} while (surname.empty());

	std::cout << "Welcome " << name << " " << surname << std::endl << "I would like to ask for Your age" << std::endl;
	do {
		std::cin >> age; 
		if (age <= 0 || age > 120) {
			std::cout << "I don't think it's proper age" << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
		}
	} while (age <= 0 || age > 120);

	std::cout << (age < 20 ? "That's cute... You're such a young person!" : (age < 40 ? "Oh... I though You're past 60's." : "Have You considered writing the will?")) << std::endl;

	std::cout << "And one more thing.. Your surname is pretty damn funny because it has " << findCharShorter(surname, 'a') << " 'a' and " << findCharShorter(surname, 'e') << " 'e'.And that's a very rare thing!" << std::endl;

	return 0;
}

