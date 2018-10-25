#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct animal
    {
        string Gatunek;
        string Alias;
    };

struct x
    {
        string Imie;
        string Nazwisko;
        string Wiek;
        animal Zwierzak;
    };

int main()
{
    x student[3];

    cout<<"Wprowadz dane. \n";

	/*
	Wprowadzanie mnie mało interesuje TBH.
	*/
    for(short i=0; i<3; i++)
    {
        cout<<"Podaj imie";
        cin>>student[i].Imie;
        cout<<"Podaj nazwisko";
        cin>>student[i].Nazwisko;
        cout<<"Podaj wiek";
        cin>>student[i].Wiek;
        cout<<"Podaj gatunek zwierzaka";
        cin>>student[i].Zwierzak.Gatunek;
        cout<<"Podaj Alias zwierzaka";
        cin>>student[i].Zwierzak.Alias;

    }
    cout<<endl<<"Oto rezultat wprowadzonych danych: "<<endl;
	
	/*
	To wyświetla wszystkich. A ja chce tylko tych którzy mają kota.
	*/
    for(short licz=0; licz<3; licz++)
    {
        cout<<"Student"<<licz+1<<"Imie: "<<student[licz].Imie<<" Nazwisko: "<<student[licz].Nazwisko<<"Wiek: "<<student[licz].Wiek<<"Zwierzak: "<<student[licz].Zwierzak.Gatunek<<"  "<<student[licz].Zwierzak.Alias<<endl;
    }
    getch();

    return 0;
}

/*
Nie tak formatujemy program. Wzorcowe formatowanie:
*/
int main()
{
    x student[3];
    cout << "Wprowadz dane. \n";
    for(short i = 0; i < 3; i++)
    {
        cout << "Podaj imie";
        cin >> student[i].Imie;
        cout << "Podaj nazwisko";
        cin >> student[i].Nazwisko;
        cout << "Podaj wiek";
        cin >> student[i].Wiek;
        cout << "Podaj gatunek zwierzaka";
        cin >> student[i].Zwierzak.Gatunek;
        cout << "Podaj Alias zwierzaka";
        cin >> student[i].Zwierzak.Alias;

    }
    cout << endl << "Oto rezultat wprowadzonych danych: " << endl;
	
    for(short licz = 0; licz < 3; licz++)
    {
        cout << "Student" << licz+1 
			<< "Imie: " << student[licz].Imie
			<< "Nazwisko: " << student[licz].Nazwisko 
			<< "Wiek: " << student[licz].Wiek
			<< "Zwierzak: " << student[licz].Zwierzak.Gatunek << "  " << student[licz].Zwierzak.Alias << endl;
    }
    getch();

    return 0;
}