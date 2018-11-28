
#include "pch.h"
#include <iostream>

//silnia rekursywnie

int silnia(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return n * silnia(n - 1);
}
/*
Clean code
*/

int main()
{
	std::cout << silnia(8);
}
