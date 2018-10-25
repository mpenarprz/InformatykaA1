//Daniel Krzyzanowski 160843
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct Zwierze
{

	string species;
	string alias;
	
	/*
	Warte docenienia
	*/
	void dodaj_zwierze()
	{
		cout << "Dodawanie zwierzecia studenta do bazy: " << endl;
		cout << "Podaj gatunek: ";
		cin >> species;
		cout << "Podaj Alias: ";
		cin >> alias;

	}
};

struct Student
{

	string name;
	string surname;
	int age;
	Zwierze pet;

	/*
	Warte docenienia
	*/
	void dodaj_studenta()
	{
		cout << "Dodawanie nowego Studenta do bazy: " << endl;
		cout << "Podaj Imie: ";
		cin >> name;
		cout << "Podaj nazwisko: ";
		cin >> surname;
		cout << "Podaj wiek: ";
		cin >> age;
		pet.dodaj_zwierze();
	}
};

/*
Sprzedaję Ci tu info jeszcze raz. Załóżmy strukturę:
*/
struct Student2
{
	string name;
	string surname;
	int age;
	Zwierze pet;
}

/* To jest to samo co: */
struct Student2
{
	public: // Ten tzw. 'specyfikator dostępu' jest domyśly i można go pominąć
		string name;
		string surname;
		int age;
		Zwierze pet;
}

/*
To moje
*/

void find(Student * s, int n, string szukana){
	for (int i = 0; i < n; i++)
	{
		if (s[i].pet.alias == szukana) 
		{
			cout << "Szukane zwierze posiada student: " << s[i].name << " " << s[i].surname;
		}
	}
}
/*
Koniec moje
*/

int main()
{
	Student s[5];
	for (int i = 0; i <= 4; i++)
	{
		s[i].dodaj_studenta();
	}
	string szukana;
	cout << "Podaj szukane zwierze";
	cin >> szukana;
	
	/*
	To poniżej przerzucić do osobnej funkcji. Patrz wyżej
	*/
	for (int i = 0; i <= 4; i++)
	{
		if (s[i].pet.alias == szukana) 
		{
			cout << "Szukane zwierze posiada student: " << s[i].name << " " << s[i].surname;
		}
	}
	/*
	I wywołać
	*/
	find(s, 5, szukana);
	return 0;
}
