// Exercise 1

#include "pch.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

/*
Zawsze jest strach jak ktoś wywoła silnia(-1)
*/
long long silnia(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return n * silnia(n - 1);
}

/*
Czemu x = 3.14?
Ta funkcja nie jest bardzo przydatna 
*/
long double taylor(int n)
{
	double x = 3.14;
	if (n == 0)
	{
		return x;
	}
	return (pow(-1, n)/silnia(2*n+1))*pow(x, 2*n+1) + taylor(n - 1);
}

int main()
{
	for (int i = 0; i < 11; i++)
	{
		cout << taylor(i) << endl;
	}
	for (int i = 0; i < 24; i++)
	{
		cout << silnia(i) << endl;
	}
	cout << pow(3.14, 13);
}