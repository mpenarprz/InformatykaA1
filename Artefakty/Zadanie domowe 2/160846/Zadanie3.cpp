// Zadanie3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>

#include <vector>
#include <string>


using namespace std;


class Osoba {

protected:
	string imie;
	string nazwisko;
	int plec; //	0 - k, 1 - m
	int pesel;


public:

	Osoba() {}; //	konstruktor domyślny
	/*
	Po co konstruktor domyślny?
	*/
	
	Osoba(string imie1, string nazwisko1, int plec1, int pesel1) {
		imie = imie1;
		nazwisko = nazwisko1;
		plec = plec1;
		pesel = pesel1;
	}

	/*
	Żeby osiągnać polimorfizm można opatrzeć metodę słowem virtual:
	virtual void hello()
	*/
	void hello() {
		cout << "Witam, nazywam sie " << " " << nazwisko << " " << imie << endl;
	}

};


class Nauczyciel : public Osoba {

private:
	vector<string> przedmioty_nauczania;
	string tytul_naukowy;


public:

	/*
	To można zrobić lepiej.
	W linjkach 30-34 masz już napisanie ustawianie imienia, nazwiska, płci i peselu.
	Można wywołać konstruktor klasy nadrzędnej:
	Nauczyciel(string imie1, string nazwisko1, int plec1, int pesel1, vector<string> przedmioty_nauczania1, string tytul_naukowy1) : Osoba(imie1, nazwisko1, plec1, pesel1) {
		tytul_naukowy = tytul_naukowy1;
		for (int i = 0; i < przedmioty_nauczania1.size(); i++){
			przedmioty_nauczania.push_back(przedmioty_nauczania1[i]);
		}
	}
	*/
	Nauczyciel(string imie1, string nazwisko1, int plec1, int pesel1, vector<string>przedmioty_nauczania1, string tytul_naukowy1) {
		imie = imie1;
		nazwisko = nazwisko1;
		plec = plec1;
		pesel = pesel1;
		for (int i = 0; i < przedmioty_nauczania1.size(); i++) {
			przedmioty_nauczania.push_back(przedmioty_nauczania1[i]);
		}
		tytul_naukowy = tytul_naukowy1;
	}

	void hello() {
		cout << "Witam, nazywam sie " << nazwisko << " " << imie << " jestem " << tytul_naukowy << " i chetnie wykladam: ";
		for (int i = 0; i < przedmioty_nauczania.size(); i++) {
			cout << przedmioty_nauczania[i] << ", ";
		}
		cout << endl;
	}

};



class Uczen : public Osoba {

private:
	int klasa;
	int semestr; //	0 - zimowy, 1 - letni
	string profil;


public:

	/*
	Tak jak dla nauczyciela
	*/
	Uczen(string imie1, string nazwisko1, int plec1, int pesel1, int klasa1, int semestr1, string profil1) {
		imie = imie1;
		nazwisko = nazwisko1;
		plec = plec1;
		pesel = pesel1;
		klasa = klasa1;
		semestr = semestr1;
		profil = profil1;
	}


	void hello() {
		cout << "Witam, jestem " << imie << " i lubie kebaby" << endl;
	}

};



int main()
{
	vector<string> przedmioty_nauczania;
	przedmioty_nauczania = { "metrologie", "informatyke" };

	Osoba o1("Adam", "Nowak", 1, 86072475832);
	Nauczyciel n1("Dariusz", "Malinowski", 1, 73103038594, przedmioty_nauczania, "profesorem");
	Uczen u1("Marek", "Szybki", 1, 99062676576, 3, 0, "Informatyka");

	o1.hello();
	cout << endl;

	n1.hello();
	cout << endl;

	u1.hello();
	cout << endl;
	cout << endl;


	system("pause");
	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
