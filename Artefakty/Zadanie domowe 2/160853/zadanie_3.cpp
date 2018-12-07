#include "pch.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Osoba {
protected:
	string imie;
	string nazwisko;
	string plec;
	int pesel;

public:

	Osoba(string imie, string nazwisko, string plec, int pesel){
		/*
		Very very nice!
		Użycie this = pro
		*/
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->plec = plec;
		this->pesel = pesel;
	}
	
	/*
	Sexy virtual
	*/
	virtual void hello() {
		cout << "Witam, nazywam sie " << nazwisko << " " << imie;
	}


};

class Nauczyciel : public Osoba {
private:
	string tytulNaukowy;
	vector<string> przedmioty;

public:
	/*
	Do tego momentu widziałem już wszystko co chciałem. Jest git.
	
	Oprócz małego bzdetu, ale siedzę cicho.
	*/
	
	Nauczyciel(string imie, string nazwisko, string plec, int pesel, string tytulNaukowy, vector<string> przedmioty) : Osoba(imie, nazwisko, plec, pesel) {
		this->tytulNaukowy = tytulNaukowy;
		for (int i = 0; i < przedmioty.size(); i++) {
			this->przedmioty.push_back(przedmioty[i]);
		}
	}
	virtual void hello() {
		cout << "Witam, nazywam sie" << nazwisko << " " << imie << ", jestem " << tytulNaukowy << " i chetnie wykladam: ";
		for (int i = 0; i < przedmioty.size(); i++) {
			cout << przedmioty[i] << ", ";
		}
	}
};

class Uczen : public Osoba {
private:
	string klasa;
	int semestr;
	string profil;
	
public:
/*
Dobra, kłamałem - będe pisał.
Masz błąd w konstruktorze poniżej. Przekazujesz profil, a ustawiasz pole w klasie na sztywno. :P
*/
	Uczen(string imie, string nazwisko, string plec, int pesel, string klasa, int semestr) : Osoba(imie, nazwisko, plec, pesel) {
		this->klasa = klasa;
		this->semestr = semestr;
		this->profil = "AiR";
	}
	Uczen(string imie, string nazwisko, string plec, int pesel, string klasa, int semestr, string profil) : Osoba(imie, nazwisko, plec, pesel) {
		this->klasa = klasa;
		this->semestr = semestr;
	}

	virtual void hello() {
		cout << "Witam, jestem " << imie << " i lubie kebaby";
	}
};




int main()
{
	vector<string> przedmioty;
	przedmioty = { "Informatyka", "Matematyka" };
	vector<Osoba *> zbior_osob;
	zbior_osob.push_back(new Nauczyciel("Janusz", "Kowalski", "mezczyzna", 999999999, "profesor", przedmioty));
	zbior_osob.push_back(new Osoba("Marcin", "Nowak", "mezczyzna", 55555555555));
	zbior_osob.push_back(new Uczen("Janina", "Burczymucha", "kobieta", 11111111111, "Informatyczna", 3));


	for (int i = 0; i < zbior_osob.size(); i++)
	{
		zbior_osob[i]->hello(); cout << endl;
	}


	

	return 0;
}
