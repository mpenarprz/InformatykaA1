#include"pch.h"
#include <iostream>

using namespace std;

int Suma(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return Suma(n-1) + n;

}

int main()
{
	int n;

	cout << "Podaj liczbe poczatkowych wyrazow sumy: ";
	cin >> n;

	cout << Suma(n);

	return 0;
}