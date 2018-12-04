// Zadanie_domowe_2_160843.cpp

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Zadanie 1

long long silnia(int s) 
{
	if (s > 1) 
	{
		return s * silnia(s - 1);
	}
	// A co to za dziura tu?
	// W tym miejscu zapomniałem już o tym że byłem w If'ie
	else if(s==1)
	{
		return 1;
	}

	else if (s == 0)
	{
		return 1;
	}

	else
	{
		cout << "Blad" << endl;
		/*
		To się nie skompiluje.
		*/
	}
}

long double sinus(long double x, int k)
{
	if (0 < k) 
	{
		return (sinus(x, k - 1) + (pow(-1, k) / silnia(2 * k + 1) * pow(x, (2 * k + 1)))); // o jeden nawias za dużo
	}
	else 
	{
		return x;
	}
}

//Zadanie 2

/*
void main()
{								// 0 bajtów
	char smth[10];				// 10 bajtów
	int * x = new int(1);		// 10 + 4
	long * y = new long(5);		// 14 + 4
	delete x;					// 18 - 4
	cout << "hej" << endl;		// 14
}
*/

//Zadanie 3

class Osoba {

protected:
	string o_nazwisko;
	string o_imie;
	string o_plec;
	int o_PESEL;

public:
	
	Osoba(string imie, string nazwisko, string plec, int PESEL) 
	{
		o_imie = imie;
		o_nazwisko = nazwisko;
		o_plec = plec;
		o_PESEL = PESEL;
	}

	/*
	Problem 1) Skąd ten konstruktor?
	*/
	Osoba(){}
};

class Nauczyciel : public Osoba 
{
private:
	vector<string> n_przedmioty;
	string n_tytul;

public:
	/*
	Problem 1) Ciąg dalszy
	Skoro Nauczyciel to też Osoba, to musi jakoś powstawać. Można pominąć przepisania do pól Osoby i skorzystać z tego że w linijkach 78-82 to robisz:
	Nauczyciel(string imie, string nazwisko, int plec, int pesel, vector<string> przedmioty, string tytul) : Osoba(imie, nazwisko, plec, pesel), n_tytul(tytul) {
		for (int i = 0; i < przedmioty.size(); i++){
			n_przedmioty.push_back(przedmioty[i]);
		}
	}
	*/
	
	Nauczyciel(string imie, string nazwisko, string plec, int PESEL, vector<string> przedmioty, string tytul)
	{
		o_imie = imie;
		o_nazwisko = nazwisko;
		o_plec = plec;
		o_PESEL = PESEL;
		for (int i = 0; i < przedmioty.size(); i++) {
			n_przedmioty.push_back(przedmioty[i]);
		}
		n_tytul = tytul;
	}
};

class Uczen : public Osoba {
	string u_klasa;
	bool u_semestr;
	string u_profil;

public:
	/*
	Problem 1) Ciąg dalszy
	Tu też można skrócić
	*/
	Uczen(string imie,string nazwisko, int plec, int PESEL, string klasa, bool semestr, string profil) {
		o_imie = imie;
		o_nazwisko = nazwisko;
		o_plec = plec;
		o_PESEL = PESEL;
		u_klasa = klasa;
		u_semestr = semestr;
		u_profil = profil;
	}
	
};


int main()
{
	return 0;
}