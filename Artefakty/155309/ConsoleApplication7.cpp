#include "pch.h"
#include <iostream>
#include <string>

/*
Proszę nie używać using namespace .... 
w kodzie produkcyjnym ....
*/
using namespace std; 

struct Animal
{
	string spiecies;
	string abbr; // tu powinen być alias
};

struct Student
{
	string name;
	string surname;
	/*
	Bardzo ładnie że wykorzystałeś unsigned int
	*/
	unsigned int age;
	Animal pet;
};

/*
Ha ha ha! Wybrałeś trudniejszą sygnaturę funkcji findStudents()
*/
/*string findStudents(Student students[], string species)
{
	return students;
}*/

string cipher(string input, int key)
{
	for (int i = 0; i < input.length(); i++) // Dobrze
	{
		input[i] = input[i] + key; // Bardzo dobrze. Można skrócić do: input[i] += key;
		if(input[i] > 122)
		{
			input[i] = 96 + key; // to skaszaniłeś. Wyjaśnienie pod spodem
		}
	}
	return input;
}
/*
	Załóżmy key = 2 i ciąg "Y".
	"Y" + 1 = "Z"
	"Z" + 1 = "A"
	czyli 
	"Y" + 2 = "A"
	(int)("Y" + 2) wychodzi za 122
	i nadpisujesz input[i] = 96 + 2 = "B".
	
	Nie kompensujesz wartości key po wyjściu za margines.
*/
