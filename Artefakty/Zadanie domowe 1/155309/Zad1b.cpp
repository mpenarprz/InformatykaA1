
#include "pch.h"
#include <iostream>

//suma n liczb rekursywnie

int sumaLiczb(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return n + sumaLiczb(n - 1);
}

/*
Clean code
*/

int main()
{
	std::cout << sumaLiczb(5);
}