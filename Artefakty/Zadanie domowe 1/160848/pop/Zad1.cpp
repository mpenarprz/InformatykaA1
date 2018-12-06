#include <iostream>
#include <string>

using namespace std;

int licznik(int n)
{
	int suma = 0;
	for (int i = 1; i <= n; i++)
	{
		suma += i;  // Można skrócić: suma += i;
	}
	return suma; 
}

/*
tu jest brainf**k i nie wiem czemu to działa...
jestem po naprawde długiej dyskusji na temat dlaczego to nie powinno działać, a jednak działa...
ogólna zasada jest taka mówi że każda ścieżka w programie powinna kończyć się return.
U Ciebie w funkcji rekursja:
brakuje returna w miejscach A LUB B

Nie ograniam C++ :P
*/
int rekursja(int n, int suma =0)
{
	if (n == 0) {
		return suma;
	}
	else {
		suma += n;
		n--;
		rekursja(n, suma);
		//A: return rekursja(n, suma);
	}
	//B reutrn ?; <- tu return daje błędny wynik dla operacji sumowania, ale przepuszcza kompilację.
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
	 int n;
	 cin >> n ;
	 cout << "suma to " << licznik(n) << endl;
	 cout << "suma to: " << rekursja(n) << endl;
	 
     // Dodanie cout << "suma to " << licznik(n); // Pokaże błędny wynik
	 system("pause"); 
    
	
}