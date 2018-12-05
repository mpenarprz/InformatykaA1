#include <iostream>

using namespace std;

/*
Nieźle, nawet jak użytkownik popełni błąd i wpisze silnia(-1) to program będzie defensywnie działał
*/
 int silnia(int n){
    if(n>1) return n*silnia(n-1);
    else return 1;
}

/*
Tu jest jakiś mały niepokój...
warunek n > 0 jest chyba za mocny i w rzeczywistości liczysz szereg z  "N + 2" wyrazów Taylora, a nie z "N"
*/
float sin(float x, int n)
{
	// Imo n > 1
    if (n > 0) {
		return (sin(x, n - 1) + (pow(-1, n) / silnia(2 * n + 1) * pow(x, (2 * n + 1))));
	}
	else {
		return x;
	}
}

int main(){
    return 0;
}
