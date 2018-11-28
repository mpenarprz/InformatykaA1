#include <iostream>

using namespace std;

int silnia (int n);

int main()
{
    int a;

    cin >> a;
    cout << silnia(a);

    return 0;
}

int silnia (int n){
    int silnia = 1;
    for (int i = 1; i <= n; i++)
    {
        silnia = silnia * i; // O jak brzydko sformatowane nawiasy
    }
    return silnia;}
	
// Przy okazji można skrócić zapis silnia = silnia * i
//Albo tak:
int silnia (int n)
{
	int silnia = 1;
	for (int i = 1; i <= n; i++)
	{
		silnia *= i; 
	}
	return silnia;
}

//Albo tak:
int silnia (int n){
	int silnia = 1;
	for (int i = 1; i <= n; i++){
		silnia *= i; 
	}
	return silnia;
}