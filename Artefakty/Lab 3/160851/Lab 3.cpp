#include "pch.h"

#include <iostream>

#include <string>

 

using namespace std;

 

struct Animal

{

string Gatunek;

string Alias;

};

 

struct Student

{

string Name;

    string Surname;

unsigned int Age; // Mała optymalizacja, ale warta podziękowania: unsigned 

Animal Pet;

};

 

int main()

{

 

 

Student Student1;

Student1.Name = "Przemek";

Student1.Surname = "Nadlonek";

Student1.Age = 20;

Student1.Pet = "Kita";

 

cout << "Podaj zwierzaka: " << endl;

cin >> Animal.Pet; // To się nie skompiluje

 

 

 

return 0;

}