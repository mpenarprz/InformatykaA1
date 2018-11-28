#include <iostream>
#include <string>
#include <algorithm> // Nie można z tego skorzystać - stwierdzenie
#include <vector> // Nie można z tego skorzystać - podpowiedź


using namespace std;

vector <int> piramida;

int main()
{
	int n;
	cin >> n;

	while (n != -1)
	{

		if (n >= 0 && n <= 5000) // Zakres upraszcza problem
			piramida.push_back(n);

		cin >> n;
	}
	
	sort(piramida.begin(), piramida.end()); // Byłoby za łatwo. Potrzebuje implementacji algorytmu sortowania.
	
	for (int i = 0; i < piramida.size(); i++) {
		
		cout << piramida[i];
		if (i + 1 < piramida.size())
			cout << ", ";
		
	}


	
	
	system("pause");
	return 0;
}