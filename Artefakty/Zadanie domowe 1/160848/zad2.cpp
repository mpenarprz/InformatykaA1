#include <iostream>
#include <string>

using namespace std;
int unsigned n;
int wynik = 1;

int silnia(int n)
{
	if (n < 2)
	{
		return wynik;
	}
	else if (n > 1)
	{
		wynik = n * silnia(n - 1);
		return wynik;
	}
}		

/*
Takie same uwagi jak poprzednio
*/	


/*
A gdzie jest iteracyjna wersja? :P
*/
	
int main()
{
	cin >> n;
    cout << "n!=" << silnia(n) << endl;
	// Dodanie cout << "n!=" << silnia(n) << endl; pokaże błedny wynik
	system ("pause");
}
