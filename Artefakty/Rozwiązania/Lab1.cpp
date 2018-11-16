#include <iostream>
#include <string>

/*
	Zadanie 1
*/
bool zapoznalemSieZKartaPrzedmiotu() {
	return true;
}

/*
	Zadanie 2
*/
void paczkomaty() {
	/*
		Sekcja przygotowująca dane
	*/
	const int STUDENTS_COUNT = 87;						// Zapamiętujemy ile mamy studentów (opcjonalnie)
	double buckets[STUDENTS_COUNT];						// Deklarujemy tablice, tyle elementów ile mamy studentów
	for (int i = 0; i < STUDENTS_COUNT; ++i) {
		buckets[i] = 0;									// Zerujemy elementy tablicy
	}

	/*
		Rzeczywisty program
	*/
	int option, index;
	double amount;
	std::cout << "Hello, this is lame software"					<< std::endl;
	do {
		std::cout << "Please choose one of the following options:" << std::endl;
		std::cout << "\t0 : check the status of volunteer" << std::endl;
		std::cout << "\t1 : add the money for the volunteer" << std::endl;
		while (!(std::cin >> option));						// Wczytujemy dopóki nie ma błedu
		if (option == 0) {
			/*
				Pytamy o wolontariusza i wypisujemy dane
			*/
			std::cout << "State of which volunteer should be printed (0-" << STUDENTS_COUNT - 1 << ")?" << std::endl;
			while (!(std::cin >> index));					// Wczytujemy indeks wolontariusza dopóki nie ma błedu
			if (index >= 0 && index < STUDENTS_COUNT) {
				std::cout << "Volunteer no. " << index << " has collected " << buckets[index] << "$" << std::endl;
			}

		}
		else if (option == 1) {
			/*
			Pytamy o wolontariusza i modyfikujemy stan
			*/
			std::cout << "State of which volunteer should be modified (0-" << STUDENTS_COUNT - 1 << ")?" << std::endl;
			while (!(std::cin >> index));					// Wczytujemy indeks wolontariusza dopóki nie ma błedu
			if (index >= 0 && index < STUDENTS_COUNT) {
				std::cout << "How much?" << std::endl;
				while (!(std::cin >> amount));					// Wczytujemy ilość pieniędzy dopóki nie ma błedu
				buckets[index] += amount;						// Modyfikujemy
				std::cout << "Done!" << std::endl;
			}
		}
		else {
			std::cout << "OK. Goodbye!" << std::endl;
			return;
		}
	} while (true);
}

/*
	Zadanie 3
*/
/*
	Funkcja pomocnicza sprawdzająca czy od pozycji "position" występuje text forbidden
*/
bool check(std::string text, std::string forbidden, int position) {
	bool status = true;
	for (int i = 0; i < forbidden.length(); ++i) {
		status &= (i + position < text.length() && text[i + position] == forbidden[i]);
	}
	return status;
}

std::string sanitize(std::string text, std::string forbidden) {
	std::string output = "";
	for (int i = 0; i < text.length(); ++i) {
		if (check(text, forbidden, i)) {
			i += forbidden.length() - 1;
		}
		else {
			output += text[i];
		}
	}
	return output;
}

void main(){
	/*
		Odkomentować co tam chcecie:
		zapoznalemSieZKartaPrzedmiotu()
	*/
	/*
		Wywołanie paczkomatów:
		paczkomaty();
	*/

	/*
		Przypadki testowe dla zadania z sanitize:
		std::cout << sanitize("nobody is perfect", "is") << std::endl;
		std::cout << sanitize("abbabba", "bb") << std::endl;
		std::cout << sanitize("aabcbabccabc", "abc") << std::endl;
	*/
}
