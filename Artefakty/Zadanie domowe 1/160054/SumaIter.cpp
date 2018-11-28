#include <iostream>
using namespace std;

int suma (int n);

int main() {
    int a;
        cin >> a ;	//Coś z wcięciami nie teges

        cout << suma(a);

        return 0;
}

int suma (int n ){
    int suma = 0;
    for (int i = 0; i <= n ; ++i) {		// A tu już ładne formatowanie, podejrzane.
        suma = suma + i;

    }

    return suma;
}