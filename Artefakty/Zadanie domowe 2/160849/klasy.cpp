#include <iostream>
#include <vector>

using namespace std;

/*
O jaki niewyjustowany kod!
*/
class Osoba{
protected:
string nazwisko;
string imie;
int plec;
int wiek;
int pesel;

public:
    void wyswietl()
    {
        cout<<nazwisko<<imie<<plec<<wiek<<pesel<<endl;
    }
	
	/*
	Nice
	*/
    void hello(){
    cout<<"Witam. Nazywam sie "<<nazwisko<<" "<<imie<<endl;
    }
/*
Tak.
Można dodawć wartości domyślne w parametrach, ale jest to problemtyczne z powodów wybiegających poza materiał Informatyki 1.
Na razie odradzam korzystanie z wartości domyślnych i raczej robić jawne przeciążanie:
czyli jeden konstruktor:
Osoba(string naz, string im, int pl, int wi, int pes);
I jak zależy Ci na jakiś domyślnym obiekcie, to wywołać jeden konstruktor z drugiego:
Osoba() : Osoba("Kowalski", "Jan", 1, 28, 90010123456)

*/
Osoba(string naz="Kowalski", string im="Jan", int pl=1, int wi=28, int pes=90010123456)
{
nazwisko=naz;
imie=im;
plec=pl;
wiek=wi;
pesel=pes;
}
};

/*
Ten kod nie powinen móc się skompilować
..... ale się kompiluje.... z powodu "problemów wybiegających poza materiał Informatyki 1."
*/
class Nauczyciel:public Osoba //klasa Nauczyciel dziedziczy publicznie z klasy Osoba
{
string przedmioty;
string tytul;

public:
/*
Nice
*/
void hello(){
    cout<<"Witam. Nazywam sie "<<nazwisko<<" "<<imie<<". Jestem "<<tytul<<" i chetnie wykladam "<<przedmioty<<endl;
}
/*
Ten sam zarzut co dla Osoby.
*/
Nauczyciel(string nazn="Nowak", string imn="Janusz", int pln=1, int wn=38, int pesn=80010123456,string prz="matematyka", string tyt="mgr")
{
nazwisko=nazn;
imie=imn;
plec=pln;
wiek=wn;
pesel=pesn;
przedmioty=prz;
tytul=tyt;
}
};

/*
Ten kod nie powinen móc się skompilować
..... ale się kompiluje.... z powodu "problemów wybiegających poza materiał Informatyki 1."
*/
class Uczen:public Osoba
{
    int klasa;
    int semestr;
    string profil;

public:
void hello(){
cout<<"Witam, jestem "<<imie<<" i lubie kebaby"<<endl;
}
Uczen(string nazu="Nowak", string imu="Janek", int pu=1, int wiu=18, int pesu=00010123456, int kl=3, int sem=1, string prof="mechatronika")
{
nazwisko=nazu;
imie=imu;
plec=pu;
wiek=wiu;
pesel=pesu;
klasa=kl;
semestr=sem;
profil=prof;
}
};

int main()
{
   Osoba s1;
   s1.hello();
   Nauczyciel n1;
   n1.hello();
   Uczen u1;
   u1.hello();

    return 0;
}

/***************
To ja wkleje w autoformatter ten kod:
*****************/
class Osoba {
protected:
	string nazwisko;
	string imie;
	int plec;
	int wiek;
	int pesel;

public:
	void wyswietl()
	{
		cout << nazwisko << imie << plec << wiek << pesel << endl;
	}

	void hello() {
		cout << "Witam. Nazywam sie " << nazwisko << " " << imie << endl;
	}
	
	Osoba(string naz = "Kowalski", string im = "Jan", int pl = 1, int wi = 28, int pes = 90010123456)
	{
		nazwisko = naz;
		imie = im;
		plec = pl;
		wiek = wi;
		pesel = pes;
	}
};

class Nauczyciel :public Osoba
{
	string przedmioty;
	string tytul;

public:

	void hello() {
		cout << "Witam. Nazywam sie " << nazwisko << " " << imie << ". Jestem " << tytul << " i chetnie wykladam " << przedmioty << endl;
	}
	Nauczyciel(string nazn = "Nowak", string imn = "Janusz", int pln = 1, int wn = 38, int pesn = 80010123456, string prz = "matematyka", string tyt = "mgr")
	{
		nazwisko = nazn;
		imie = imn;
		plec = pln;
		wiek = wn;
		pesel = pesn;
		przedmioty = prz;
		tytul = tyt;
	}
};

class Uczen :public Osoba
{
	int klasa;
	int semestr;
	string profil;

public:
	void hello() {
		cout << "Witam, jestem " << imie << " i lubie kebaby" << endl;
	}
	Uczen(string nazu = "Nowak", string imu = "Janek", int pu = 1, int wiu = 18, int pesu = 00010123456, int kl = 3, int sem = 1, string prof = "mechatronika")
	{
		nazwisko = nazu;
		imie = imu;
		plec = pu;
		wiek = wiu;
		pesel = pesu;
		klasa = kl;
		semestr = sem;
		profil = prof;
	}
};

int main()
{
	Osoba s1;
	s1.hello();
	Nauczyciel n1;
	n1.hello();
	Uczen u1;
	u1.hello();

	return 0;
}

