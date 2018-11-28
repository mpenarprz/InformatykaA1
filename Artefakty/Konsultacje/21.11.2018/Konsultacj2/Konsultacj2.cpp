// Konsultacj2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int wSwiecieIteracyjnym(int n)
{
	long liczba = 1;
	for (int i=1; i<=n ; i++)
	{
		liczba = liczba * i;
	}
	return liczba;
}

// wSwiecieRekursji(n) to wiem y że jest = n!
// wSwiecieREkursji(n -1) oznacza n-1!
// n! = n * (n-1)!
// czyli wywołanie: wSwiecieRekursji(n) = n *   wSwiecieREkursji(n - 1)
int wSwiecieRekursji(int n) {
	// int x = n == 0 ? 1 : n * wSwiecieRekursji(n - 1);
	return  n == 0 ? 1 : n * wSwiecieRekursji(n - 1); // [warunek] ? [zwrotka jesli prawda] : [zwrotka jestli fałsz]
}

int fibonnaci(int x) {
	return x <= 0 ? 0 : (x == 1 ? 1 : fibonnaci(x - 1) + fibonnaci(x - 2));
}

void reverse(string & text, int x) {
	if (text.length() > x) {
		reverse(text, x + 1);
	}
	cout << text[x];
}

void main()
{
	string x = "abcdefghh";
	reverse(x, 0);
	//daneosobowe c = {"daniel","kappa","738172",21};
	//auto d = daneosobowe{ "daniel","kappa","738172",21 };
	//wypisz(c);

	///*cout << c.jestemDorosly() << endl;
	//cout << pelnoletni(c) << endl;

	//cout << b.jestemDorosly() << endl;
	//cout << pelnoletni(b) << endl;*/

	//vector<int> vec = { 1,2,34,5,6,66,55 };
	//vector<daneosobowe> vec2 = {
	//	daneosobowe{ "jakub","jakub","000000",99 },
	//	c,
	//	b
	//};

	//for (int i = 0; i < vec2.size(); ++i) {
	//	wypisz(vec2[i]);
	//}

	////var template
	//int test = 1;
	//long test3 = 50;

	//auto test2 = 1;
	//auto test4 = 50L;

	//for (auto v : vec2) {
	//	wypisz(v);
	//	v.jestemDorosly();
	//}


}
