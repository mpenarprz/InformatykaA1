
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct School
{
	string Patron;
	vector<Pupil> pupils; // Ładnie
	vector<Teacher> teachers; // Ładnie - nazewnictwo w jasny sposób daje znać co jest w środku
};
struct Pupil 
{
	string name, surname, sex; 
};
struct Teacher
{
	string name, surname, sex;
};


int n;
long double fib[100000];
int main()
{
	/*
	To nie jest funkcja / nie jest wektorem
	*/
	cout << "Podaj wyraz ciagu: ";
	cin >> n;
	fib[0] = 0;
	fib[1] = 1;
	for(int i=2; i<=n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	cout << endl <<" " <<n << " wyraz ciagu ma wartosc: " << fib[n]<< endl;
	
}