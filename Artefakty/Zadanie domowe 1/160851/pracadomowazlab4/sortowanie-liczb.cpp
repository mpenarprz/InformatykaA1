#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> wpisane;

int main()
{
	int n;

	for (;;)
	{
		cin >> n;
		if (n >= 0 && n <= 5000)
			wpisane.push_back(n);
		else if (n == -1) {
			for (int i = 0; i < wpisane.size(); i++)
			{
				sort(wpisane.begin(), wpisane.end());	
				cout << wpisane[i] << " ";

			}
		}
	}

	
	return 0;

}


