#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

//Zadanie 1
long long silnia(int n) {
	if (n > 1) {
		return n * silnia(n - 1);
	}
	else {
		return 1;
	}
}

/*
Wygląda git
*/
double sinusTaylor(double x, int n) {
	if (n > 0) {
		return (sinusTaylor(x, n - 1) + (pow(-1, n) / silnia(2 * n + 1) * pow(x, (2 * n + 1))));
	}
	else {
		return x;
	}
}

//Zadanie 3
class Osoba {
protected:
	std::string _nazwisko;
	std::string _imie;
	int _plec;
	int _pesel;

public:
	/*
	Ten jest niespodziewany. Myślę że Nauczyciel i Uczen nie chcieli Ci się skonstruować i dlatego "leniwie" poluzowałeś program.
	*/
	Osoba() {

	}
	/*
	Dobrze że konstruktor jest
	*/
	Osoba(std::string imie, std::string nazwisko, int plec, int pesel) {
		_imie = imie;
		_nazwisko = nazwisko;
		_plec = plec;
		_pesel = pesel;
	}
	/*
	Jak masz dużo pól, to istnieje alternatywna składania inicjowania w C++. Wywoływanie konstruktorów poszczególnych pól:
	Osoba(std::string imie, std::string nazwisko, int plec, int pesel) : _imie(imie), _nazwisko(nazwisko),_plec(plec), _pesel(pesel) {}
	Niczym się nie różni - ale jest częściej wykorzystywana do "ustawiania" wartości pól
	*/
	virtual void hello() {
		std::cout << "Witam, nazywam sie " << _nazwisko << " " << _imie << std::endl;
	}
};

class Nauczyciel : public Osoba {
private:
	std::vector<std::string> _przedmioty;
	std::string _tytul;
public:
	/*
	Tu masz straszny "bloat"
	*/
	Nauczyciel(std::string imie, std::string nazwisko, int plec, int pesel, std::vector<std::string> przedmioty, std::string tytul) {
		_imie = imie;
		_nazwisko = nazwisko;
		_plec = plec;
		_pesel = pesel;
		for (int i = 0; i < przedmioty.size(); i++){
			_przedmioty.push_back(przedmioty[i]);
		}
		_tytul = tytul;
	}
	/*
	Alternatywną składanią konstruktora (z reużyciem konstruktora Osoby):
	Nauczyciel(std::string imie, std::string nazwisko, int plec, int pesel, std::vector<std::string> przedmioty, std::string tytul) : Osoba(imie, nazwisko, plec, pesel), _tytul(tytul) {
		for (int i = 0; i < przedmioty.size(); i++){
			_przedmioty.push_back(przedmioty[i]);
		}
	}
	W takim konstruktorze, wiemy że jedno z pól jest wyjątkowe (_przedmioty)
	*/
	void hello() {
		std::cout << "Witam, nazywam sie " << _nazwisko << " " << _imie << ", jestem " << _tytul << " i chetnie wykladam";
		for(int i = 0; i < _przedmioty.size(); i++){
			std::cout << " " << _przedmioty[i];
		}
		std::cout << std::endl;
	}
};

class Uczen : public Osoba {
	std::string _klasa;
	bool _semestr;
	std::string _profil;
public:
	/*
	Tak samo, straszny bloat
	*/
	Uczen(std::string imie, std::string nazwisko, int plec, int pesel, std::string klasa, bool semestr, std::string profil) {
		_imie = imie;
		_nazwisko = nazwisko;
		_plec = plec;
		_pesel = pesel;
		_klasa = klasa;
		_semestr = semestr;
		_profil = profil;
	}
	/*
	Można skrócić do:
	Uczen(std::string imie, std::string nazwisko, int plec, int pesel, std::string klasa, bool semestr, std::string profil) : Osoba(imie, nazwisko, plec, pesel), _klasa(klasa), _semestr(semestr), _profil(profil) {}
	W takim konstruktorze, wiemy że pola są inicjowane "jak leci"
	*/
	void hello() {
		std::cout << "Witam, jestem " << _imie << " i lubie kebaby" << std::endl;
	}
};

/*
Bardzo ładnie rozwiązane zadanie
*/

int main()
{
	std::vector<std::string> przedmioty = { "przeceny","znizki","okazje","wyprzedaze","darmowe" };
	std::vector<Osoba*> ludzie;
	ludzie.push_back(new Uczen("Jan", "Kowalski", 0, 1234567890, "pierwsza",false,"Gastronom"));
	ludzie.push_back(new Nauczyciel("Janusz", "Oszczedny", 0, 9187654321, przedmioty, "profesorek"));
	ludzie.push_back(new Osoba("i cala reszte", "Odpowiedz na Wielkie pytanie o zycie, wszechswiat", 42, 4242424224));
	for (Osoba* czlowiek : ludzie) {
		czlowiek->hello();
	}
	return 0;
}
