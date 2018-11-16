
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pupil;
struct Teacher;

struct School
{
	string patron;
	vector<Pupil> quantityP; // Obetnę za nazewnictwo - quantityP sugeruje że pod zmienną jest jakaś ilość/liczba
	vector<Teacher> quantityT; // Obetnę za nazewnictwo - quantityP sugeruje że pod zmienną jest jakaś ilość/liczba
};

struct Pupil
{
	string first_name;
	string surname;
	char sex;
};

struct Teacher
{
	string first_name;
	string surname;
	char sex;
};

int fib(int n)
{
	int a = 0, b = 1, c;
	if (n == 0)
		return a;
	for (int i = 2; i <= n; i++) 
	{
		c = a + b;
		a = b;
		b = c;
	}
	return b; // Chyba jakoś tak, chociaż nie widać tego na pierwszy rzut oka że dla n == 1 zwróci dobrą wartość
}

int main()
{
	cout << fib(12);
}