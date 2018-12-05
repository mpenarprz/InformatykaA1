#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Osoba
{
	//
public:
	string nazwisko;
	string imie;
	char plec;

protected:
	long pesel;
public:
	Osoba (string nazwisko, string imie, char plec, long pesel) {
		/*
		Pięknie
		*/
		this->nazwisko = nazwisko;			
		this->imie = imie;
		this->plec = plec;
		this->pesel = pesel;
	}

	/*
	Na przyszłość:
	Osiągniecie polimorficznego wywołania funkcji - tj. zależnego od typu obiektu w pamięci głównej sprowadza się do słowa kluczowego
	virutal
	
	virtual void hello();
	*/
	void hello() {
		Osoba pierwsza("Nowak", "Karol", "m", 9283478);
			cout << nazwisko << " " << imie <<" "<< plec <<" "<< pesel;
	}
};


/*
Ta klasa nie powinna móc się skompilować, podczas tworzenie obiektu klasy Nauczyciel trzeba też wykonstruować Osobę,
nigdzie nie widzie wywołania dla któregokolwiek konstruktora Osoby
*/
class Nauczyciel:public Osoba
{
	string przedmiot;
	string tytul_naukowy;
public:
	/*
	Ten watek wraca tu: przekazujesz pesel, a go nie ustawiasz....
	Mogłabyś pomyśleć: "hmm.. przecież to robię w konstruktorze: Osoba (string nazwisko, string imie, char plec, long pesel).... może go wykorzystam"
	I tak w rzeczywistości TRZEBA:
	
	Konstruktor dla Nauczyciela powinien wyglądać:
	Nauczyciel(string nazwisko, string imie, char plec, long pesel, string przedmiot, string tytul_naukowy) : Osoba(nazwisko, imie, plec, pesel) {  // Co oznacza "Wykonstruuj obiekt nauczyciel przy pomocy tego konkretnego konstrukora Osoby
		this->przedmiot = przedmiot;
		this->tytul_naukowy = tytul_naukowy;
	}
	*/
	Nauczyciel(string nazwisko, string imie, char plec, long pesel, string przedmiot, string tytul_naukowy){
		this->nazwisko = nazwisko;
		this->imie = imie;
		//this->plec = plec;
		this->przedmiot = przedmiot;
		//this->tytul_naukowy = tytul_naukowy; // czemu wykomentowane?
	}
	/*
	Szkoda że nie ma definicji hello() :{
	*/
};

/*
Ta klasa nie powinna móc się skompilować
*/
class Uczen:public Osoba
{
	string klasa;
	char semestr;
	string profil;
public:
	/*
	Tu też można reużyć konstruktor
	*/
	Uczen(string imie, string nazwisko, string klasa)
	{
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->klasa = klasa;
	}
	/*
	Szkoda że nie ma definicji hello() :{
	*/
};
void main() {
	
	
	Osoba.hello();
	//Osoba("Gdyk", "imie", 'k', 00000).check();
	system("pause");
}