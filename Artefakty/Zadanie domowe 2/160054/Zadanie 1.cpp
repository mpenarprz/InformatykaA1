#include <iostream>
#include "cmath"

int Silnia(int n){
    return n == 0 ? 0 : n == 1 ? 1 : n == 2 ? 2 : Silnia(n - 1) * n;
}

int sinTaylor (int x, int n){
    if (n > 0){
        return sinTaylor(x, n - 1) + (pow(-1, n) / Silnia(2 * n + 1) * pow(x, (2*n +1)));
    }
	// Jestem fanem pominięcia tutaj else i od razu zwrócenia x.
    return x;

}

/*
Największy zarzut to niekonsekwentne stylowanie: 
* (2*n +1) - brak spacji tu po + 1
* funkcje raz za małych liter, raz z dużych
To moje największe zarzuty
*/
