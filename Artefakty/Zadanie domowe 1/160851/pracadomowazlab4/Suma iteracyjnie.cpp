#include "pch.h"
#include <iostream>


using namespace std;



int main() 
{

	int suma = 0, n;

	

	cout << "Podaj ilosc liczb: " << endl;
	cin >> n;

	for (int i = 0; i <= n; i++) 
	 {
			suma = suma + i; //Jako funkcję proszę - tu obcinam punkty
	 }

	cout << suma << endl;
	
	return 0;
}


