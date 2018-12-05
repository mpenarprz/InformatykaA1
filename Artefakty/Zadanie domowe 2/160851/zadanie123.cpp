
//ZADANIE 1.

#include "pch.h"
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


unsigned int factorial(int number)
{
	if (number < 2) return number;
	return number * factorial(number - 1);
}

/*
Looks pro
*/
float sinusTaylor(float x, unsigned int k) {

	return k < 1 ? x : (sinusTaylor(x, k - 1) + (pow(-1, k)) / factorial(2 * k + 1) * pow(x, (2 * k + 1)));
}

int main() {
	unsigned int k;
	float x;
	cout << "Enter x variable: ";
	cin >> x;
	cout << "Enter number of expression: ";
	cin >> k;
	cout << sinusTaylor(x, k);

	return 0;
}


//ZADANIE 3.

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class person {

protected:
	const long long pesel;

public:
	string name, surname;
	string gender;

	person(string _name, string _surname, string _gender) {
		_name = name; // Przepisanie na odwrót
		_surname = surname; // Przepisanie na odwrót
		_gender = undefind; // Przepisanie na odwrót + Nie widze czegoś, albo to się nie skompiluje
		// W parametrze przekazujesz _name.
		// W środku klasy masz name.
		// Chcesz osiągnąć name = _name;
	}
	
	/*
		Pod spodem i na górze jest konstruktor o takiej samej sygnaturze... to sie nie skompiluje
	*/
	person(string _name, string _surname, string gender) : person(_name, _surname, undefind) {}


	/*
	Ale polimorfizm jest :P
	*/
	virtual void hello() {
		cout << "Hello, I am " << name << " " << surname << endl;
	}
};

class teacher : person {
public:
	string academic_title;
	vector <string> subjects;

	/*
	Tu przepisujesz już poprawnie z _subjects do subjects
	+
	ładnie wywołujesz konstruktor z person
	*/
	teacher(string _name, string _surname, string _gender, vector <string> _subjects) : person(_name, _surname, _gender) {
		for (int i = 0; i < _subjects.size(); i++) {
			subjects.push_back(subjects[i]);
		}
	}

	virtual void hello() {
		cout << "Good afternoon, I am " << name << " " << surname << ", and I am lecturing ";
		for (int i = 0; i < subjects.size(); i++) {
			cout << subjects[i] << ", ";
		}
	}
};

class student : person {
	string  semestr, major;
	int year_of_school;

	/*
	Jak wcześniej
	*/
	student(string _name, string _surname, string _gender, int year_of_school, string _semestr, string _major) : person(_name, _surname, _gender) {}

	void hello() {
		cout << "Hello, I am " << name << " " << surname << " and I like kebabs from Dara Kebab." << endl;

	};
/*
Albo zjadłem nawias, albo brakuje
}
*/




	vector <person> Persons;

	/*
	Tego nie oceniam, ale jestem zafrapowany, bo ta funkcja nic nie robi, albo zapętla się w nieskończoność.
	Bo idziesz do pierwszego elementu i wkopiowujesz go na koniec.
	Idziesz do kolejnego elementu ;P i tak w kółko.
	*/
	void AllOfPersons() {
		

		for (int i = 0; i < Persons.size(); i++) {
			Persons.push_back(Persons[i]);

		}
	}

	void helloAllPersons() {
		for (int i = 0; i < Persons.size(); i++) {
			cout << "Hello, I am " << Persons[i] << endl;
		}
	}



	int main(){


		helloAllPersons();

		return 0;
	}

	*/


ZADANIE 2. 
#include "pch.h"
#include<iostream>

/*
Brakuje tylko komentarza co się dzieje z pamięcią y po usunięciu x.
Ładnie to można pokazać na obrazku :(
*/
void main() {
	char smth[10];           //1 char ma 1 bajt, więc tablica 10 charów ma 10 bajtów
	int * x = new int(1);    // wskaźnik ma 4 bajty w arc 32 bity
	long * y = new long(5);   // wskaźnik ma 4 bajty w arc 32 bity
	delete x;                 // Kasujemy x (-4 bajty)
	std::cout << "hey" << std::endl; // cout nie potrezbuje pamięci
	// Razem 14 bajtów
	
	/*
	Nieprawda.. do TEJ linijki na stosie masz 18 bajtów... Czegoś nie policzyłeś
	*/

}


