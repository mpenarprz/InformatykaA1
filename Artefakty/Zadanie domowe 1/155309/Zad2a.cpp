
#include "pch.h"
#include <iostream>

//silnia iteracyjnie

int silnia(int n)
{
	int liczba = 1;
	for (int i = 1; i <= n; i++)
	{
		liczba = liczba * i; //Można być pro i skrócić liczba *= i;
	}
	return liczba;
}

int main()
{
	std::cout << silnia(6);
}