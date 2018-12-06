#include <iostream>
#include <string>

using namespace std;

/*
Wooo...  Legalny count-sort!
*/
int main()
{
	int n;
	cin >> n;
	int tab[5001];
	for (int i = 0; i <= 5000; i++) {
		tab[i] = 0;
	}

	while (n != -1) {
		if (n >= 0 && n <= 5000) {
			tab[n]++;
		}
		cin >> n;
	}
	
	for (int i = 0; i <= 5000; i++) {
		if (tab[i] > 0) {
			cout << i << ", ";
			tab[i]--;
			i--;
		}
	}


	
	system("pause");
	return 0;
}