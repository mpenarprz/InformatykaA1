
#include "pch.h"
#include <iostream>

//suma n liczb iteracyjnie

int sumaLiczb(int n)
{
	int liczba = 0;
	for (int i = 1; i <= n; i++)
	{
		liczba = liczba + i;	//Można być pro i skrócić liczba += i;
	}
	return liczba;
}

int main()
{
	std::cout << sumaLiczb(5);
}