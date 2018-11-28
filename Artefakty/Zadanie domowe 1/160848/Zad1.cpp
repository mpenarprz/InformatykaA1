#include <iostream>
#include <string>

using namespace std;

int suma=0; // Zmienna globalna?
int n; 

int licznik(int n)
{
	for (int i = 0; i <= n; i++)
	{
		suma = suma + i;  // Można skrócić: suma += i;
	}
	return suma; 
}
/*
Staraj się nie deklarować zmiennych poza funkcjami (tzw. globalnych)
Raczej tak:
int licznik(int n)
{
	int suma = 0;
	for (int i = 0; i <= n; i++)
	{
		suma = suma + i; 
	}
	return suma; 
}

Zmienna globalna cały czas jest obecna w programie. U Ciebie:
int main(){
	 cout << licznik(1) << endl;
	 cout << licznik(2) << endl;
	 cout << licznik(3) << endl;
}
Powoduje błędne działanie :O
*/
	

/*
A gdzie jest rekursywna wersja? :P
*/	

int main()
{
	 cin >> n ;
     cout << "suma to " << licznik(n);
     // Dodanie cout << "suma to " << licznik(n); // Pokaże błędny wynik
	 system("pause"); 
    
	
}