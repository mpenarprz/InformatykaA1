
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int liczba;
	vector<int> dane;
	do
	{
		cin >> liczba;
		if (liczba >= 0 && liczba <= 5000)
		{
			dane.push_back(liczba);
		}
	} while (liczba != -1);
	sort(dane.begin(), dane.end());			// Byłoby za łatwo. Konkretny algorytm.
	for (int i = 0; i < dane.size(); i++)
	{
		cout << dane[i] << endl;
	}
	return 0;
}