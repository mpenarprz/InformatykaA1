
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>


/*
Piękny kod.
Ładnie dobrany typy parametrów / wartości zwracanych
*/
long long silnia(unsigned int n)
{
	if(n == 0)
	{
		return 1;
	}
	return n * silnia(n - 1);
}

/*
Piękny kod.
Ładnie dobrany typy parametrów i wartości zwracanych
*/
long double sin(unsigned int x, unsigned int n)
{
	if n == 0 
	{
		return x;
	}
	return (pow(-1, n) / silnia(2 * n + 1)) * pow(x, 2 * n + 1) + sin(n - 1);
}

/*
Pod spodem jest lekka kasza jeśli chodzi o formatowanie
*/
class Osoba
{
protected: string imie, nazwisko, plec, PESEL;

/*
Mało mówiące nazwy parametrów, ale C++ promuje takie podejście
*/
public: Osoba(string i,n,p,PE)
{
	imie = i;
	nazwisko = n;
	plec = p;
	PESEL = PE;
}
/*
Nice
*/
		void hello()
		{
			cout << "Witam nazywam sie " << nazwisko << " " << imie << endl;
		}

};
class Nauczyciel : public Osoba
{
private: vector <string> przedmioty; 
		 string tytul;
		 
/*
Ładnie wywołny konstruktor z konstruktora:
Nauczyciel(string i, n, p, PE, vector <string> prz, string t) : Osoba(string i, n, p, PE)
Good job.
*/
public: Nauczyciel(string i, n, p, PE, vector <string> prz, string t) : Osoba(string i, n, p, PE) {
	for (int i = 0; i < prz.size; i++)
	{
		prz.push_back(prz[i]);
		tytul = t;
	}
}
		void hello()
		{
			cout << "Witam nazywam sie" << nazwisko << " " << imie << "jestem " << tytul << "i chetnie wykladam" << przedmioty << endl;
		}
};


class Uczen : public Osoba
{
private:
	string klasa;
	bool semestr;
	string profil;
public: Uczen(string i, n, p, PE, kl, bool se, string pro) : Osoba(string i, n, p, PE)
{
	klasa = kl;
	semestr = se;
	profil = pro;

}
		void hello()
		{
			cout << "Witam, jestem " << imie << " i lubie kebaby" << endl;
		}

};

/*
Bardzo ładnie
*/

int main()
{
	vector <Osoba> zbior;
	for (int i = 0, i < zbior.size; i++)
	{
		zbior.push_back(zbior[i]);
		zbior[i].hello();
	}


    
}

