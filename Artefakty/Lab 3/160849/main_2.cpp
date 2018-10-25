#include <iostream>

using namespace std;

string wyraz[26]; // tablica 26 ci¹gów znaków. CI¥GÓW. 26!
// chodzi³o Ci pewnie o:
// string wyraz;
int key, i;

/*
Brak cia³a funkcji. To jest jedynie deklaracja wyprzedzaj¹ca... oznacza ona ¿e....
*/
string cipher(std::string input, int key); // Od tego miejsca w kodzie wszyscy poni¿ej mog¹ wywo³aæ cipher(string, int);

int main()
{
	/*
	Szkaradne formatowanie pêtli. Patrz ni¿ej
	*/
    for(i=0; i<26; i++)
{
    cout<<"wpisz wyraz: ";
    cin>>wyraz[i];

    cout<<"O ile ma byæ przesuniety: ";
    cin>>key;

    cipher("wyraz",key);

    cout<<"Odwrocony wyraz: "<<i+key<<endl;
}
    return 0;
}

/*
Tak powinno wygl¹daæ:
	for(i = 0; i < 26; i++)
	{
		cout<<"wpisz wyraz: ";
		cin>>wyraz[i];

		cout<<"O ile ma byæ przesuniety: ";
		cin>>key;

		cipher("wyraz",key);

		cout<<"Odwrocony wyraz: "<<i+key<<endl;
	}
*/