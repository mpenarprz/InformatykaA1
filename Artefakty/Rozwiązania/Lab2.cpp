#include <iostream>
#include <string>
#include <vector>

/*
	Zadanie 1
*/
int a = 10;		// Inicjalizacja
int b;			// Deklaracja
int c[999];		// Deklaracja tablicy

/*
	Zadanie 2
*/
struct Animal {
	std::string species, alias;
}; 

struct Student {
	std::string name, surname;
	unsigned int age;
	Animal pet; // Lub też Animal * pet;
};

void findStudents(Student students[], int numberOfStudents, std::string species) {
	Student current;
	for (int i = 0; i < numberOfStudents; ++i) {
		current = students[i];
		if (current.pet.species == species) {
			std::cout << current.name << " " << current.surname << std::endl;
		}
	}
}

/*
Zadanie 3
*/
/*
	Wykorzystamy funkcje pomocniczą
*/
std::string cipherByOne(std::string text) {
	for (int i = 0; i < text.length(); ++i) {
		text[i]++;						// Modyfikujemy wartość
		if (text[i] > 'z') {			// Sprawdzamy czy znak nie jest większy niż 'z'
			text[i] = 'a';				// Jeśli jest to zawijamy na 'a'
		}
	}
	return text;
}

std::string cipher(std::string text, int key) {
	std::string output = text;
	for (int i = 0; i < key; ++i) {
		output = cipherByOne(output);	// Wywołujemy funkcje pomocniczą tyle razy ile wynosi nasz klucz
	}
	return output;
}


void main(){
	std::cout << "Test funkcji:" << std::endl;
	Student students[] = {
		Student{ "maciej"	, "abacki"		, 20, Animal{ "kot"	, "bonbon" } },
		Student{ "tadeusz"	, "drozd"		, 45, Animal{ "pies", "reksio" } },
		Student{ "weronika"	, "kowalska"	, 28, Animal{ "kot"	, "guffy" } }
	};
	findStudents(students, sizeof(students)/sizeof(Student), "kot");

	std::cout << "Test szyfrowania:" << std::endl;
	std::vector<std::string> toCipher = { "abba", "z", "kot" };
	for (std::string word : toCipher) {
		for (int key = 0; key < 27; ++key) {
			std::cout << "Szyfruje: " << word  << " uzywajac klucza o dlugosci " << key << " = " << cipher(word, key) << std::endl;
		}
	}
}
