#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> wpisane;

int main()
{
	int n = 0;

	while (n != -1)
	{
		cin >> n;
		if (n >= 0 && n <= 5000)
			wpisane.push_back(n);
	}

	sort(wpisane.begin(), wpisane.end());	//Nie używamy #include <algorithm>... chodzi o algorytm sortowania sam w sobie

    for (int i = 0; i < wpisane.size(); i++)
	{
		cout << wpisane[i] << " ";

	}



	return 0;

}