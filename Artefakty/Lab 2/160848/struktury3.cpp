#include <iostream>
#include <string>
using namespace std;

/*
	Musimy konsekwentnie stosować nazewnictwo, albo z dużej Animal, albo z małej uczen
*/
struct animal
{
	string gatunek;
	string alias;

};

struct Uczen
{
	string imie;
	string nazwisko;
	int age;	// Wiek jest tylko dodatni, więc można skusić się na typ 'unsigned int'
	animal pet;
};

/*
Jakbyś chciała zrobić krócej to:
START
*/
struct Animal
{
	string gatunek, alias;
};

struct Uczen
{
	string imie, nazwisko;
	unsigned int age;	
	animal pet;
};
/*
STOP
*/


int main()
{
	Uczen studenci[6] = { // kompilator powinen zaakceptować: 'Uczen studenci[]'
			{"Klaudia", "Majkut", 20, {"kot", "filemon"}},
			{"Klaudia2", "Majkut2", 20, {"pies", "filemon2"}},
			{"Klaudia3", "Majkut3", 20, {"kot", "filemon2"}},
			{"Klaudia4", "Majkut4", 20, {"zolw", "filemon2"}},
			{"Klaudia5", "Majkut5", 20, {"ttt", "filemon2"}},
			{"Klaudia6", "Majkut6", 20, {"kot", "filemon2"}}
	};
	string sprawdzane; 

	cout << "jakie zwierze chcesz sprawdzic? " << endl; 
	cin >> sprawdzane;

	/*
	To trzeba przerzucić do osobnej funkcji
	*/
	for (int i = 0; i < 6; i++)
	{
		if (studenci[i].pet.gatunek == sprawdzane)
			cout << studenci[i].imie << " " << studenci[i].nazwisko << endl; 
	}
	system("pause"); 

}