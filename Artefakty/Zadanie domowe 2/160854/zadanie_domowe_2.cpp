#include "pch.h"
#include <iostream>
#include <math.h>
#include <vector>
/*
unsigned int silnia(unsigned int z) {
	return z <= 1 ? 1 : z * silnia(z - 1);
}

double taylor(double x, unsigned int n) { 
	return n < 1 ? x : (taylor(x, n - 1) + (pow(-1, n)) / silnia(2 * n + 1) * pow(x, (2 * n + 1)));
}

int main() {
	unsigned int n;
	double x;
	std::cout << "podaj x: ";
	std::cin >> x;
	std::cout << "podaj liczbe wyrazow: ";
	std::cin >> n;
	std::cout << taylor(x, n);
}
*/

/*
Nic dodać nic ując do Taylora
*/

class osoba {
/*
Ciekawe decyzje projektowe odnośnie zasięgu zmiennych. Doceniam. Dokładam punkty.
Faktycznie pesel to coś czym nie chcemy dzielić się ze światem
*/
protected:
	long long pesel;
public:
	std::string nazwisko, imie;
	int plec;

	/*
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Po co pusty konstruktor? !!!!!!!!!!!!!!!!!!!!!!!!!!
	*/
	osoba() {}
	osoba(std::string _nazwisko, std::string _imie, int _plec) {
		_nazwisko = nazwisko;
		_imie = imie;
		_plec = plec;
	}
	/*
	Super-elegancko z tym fragmentem:  : osoba(_nazwisko, _imie, 2)
	*/
	osoba(std::string _nazwisko, std::string _imie) : osoba(_nazwisko, _imie, 2) {

	}
	/*
	Wirtualna! Super!
	*/
	virtual void hello() {
		std::cout << "Witam, nazywam sie " << nazwisko << " " << imie << std::endl;

	}
};

class nauczyciel : osoba {
public:
	std::string tytul;
	std::vector<std::string> przedmioty;
	
	/*
	Alternatywną składanią konstruktora (z reużyciem konstruktora osoba):
	nauczyciel(std::string _nazwisko, std::string _imie, int plec, std::vector<std::string> _przedmioty) : Osoba(_nazwisko, _imie, plec) {
		for (int i = 0; i < _przedmioty.size(); i++){
			przedmioty.push_back(przedmioty[i]);
		}
	}
	W takim konstruktorze, wiemy że jedno z pól jest wyjątkowe (_przedmioty), pozostałe 3 służą wykonstruowaniu podstawowego obiektu 
	*/
	nauczyciel(std::string _nazwisko, std::string _imie, std::vector<std::string> _przedmioty) {
		_nazwisko = nazwisko;
		_imie = imie;
		for (int i = 0; i < _przedmioty.size(); i++) {
			przedmioty.push_back(_przedmioty[i]);
		}
	}
	nauczyciel(std::string _nazwisko, std::string _imie, std::string _tytul) {
		_nazwisko = nazwisko;
		_imie = imie;
		_tytul = tytul;
	}
	virtual void hello() {
		std::cout << "Witam, nazywam sie " << nazwisko << " " << imie << "jestem " << tytul << "i chetnie wykladam ";
		for (int i = 0; i < przedmioty.size(); i++) {
			std::cout << przedmioty[i] << ", ";
		}
	}
};

class uczen : osoba {
	std::string klasa, semestr, profil;

	/*
	To samo jak przy nauczycielu
	*/
	uczen(std::string _nazwisko, std::string _imie, std::string _klasa, std::string _profil) {
		_nazwisko = nazwisko;
		_imie = imie;
		_klasa = klasa;
		_profil = profil;
	}
	uczen(std::string _nazwisko, std::string _imie, std::string _klasa) : uczen(_nazwisko, _imie, _klasa, "Mat-Fiz") {}
	virtual void hello() {
		std::cout << "Witam jestem " << imie << " i lubie kebaby";
	}
};
