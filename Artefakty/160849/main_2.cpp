#include <iostream>

using namespace std;

string wyraz[26]; // tablica 26 ci�g�w znak�w. CI�G�W. 26!
// chodzi�o Ci pewnie o:
// string wyraz;
int key, i;

/*
Brak cia�a funkcji. To jest jedynie deklaracja wyprzedzaj�ca... oznacza ona �e....
*/
string cipher(std::string input, int key); // Od tego miejsca w kodzie wszyscy poni�ej mog� wywo�a� cipher(string, int);

int main()
{
	/*
	Szkaradne formatowanie p�tli. Patrz ni�ej
	*/
    for(i=0; i<26; i++)
{
    cout<<"wpisz wyraz: ";
    cin>>wyraz[i];

    cout<<"O ile ma by� przesuniety: ";
    cin>>key;

    cipher("wyraz",key);

    cout<<"Odwrocony wyraz: "<<i+key<<endl;
}
    return 0;
}

/*
Tak powinno wygl�da�:
	for(i = 0; i < 26; i++)
	{
		cout<<"wpisz wyraz: ";
		cin>>wyraz[i];

		cout<<"O ile ma by� przesuniety: ";
		cin>>key;

		cipher("wyraz",key);

		cout<<"Odwrocony wyraz: "<<i+key<<endl;
	}
*/