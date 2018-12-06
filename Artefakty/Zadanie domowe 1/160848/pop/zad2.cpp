#include <iostream>
#include <string>

using namespace std;


int silnia(int n, int wynik = 1)
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
int iteracja(int n) {
	int wynik = 1;
	for (int i = 1; i <= n; i++) {
		wynik *= i;
	}
	return wynik;
}
	
int main()
{
	int unsigned n;
	cin >> n;
    cout << "n!=" << silnia(n) << endl;
	cout << "n!=" << iteracja(n) << endl;
	// Dodanie cout << "n!=" << silnia(n) << endl; pokaże błedny wynik
	system ("pause");
}
