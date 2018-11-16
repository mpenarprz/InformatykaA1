#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Pupil {
        string Name, Surname, Sex;
};

struct Teacher {
        string Name, Surname, Sex;
};

struct School {
        string patron;
        vector <Pupil> pupil; // dobrze dobrany typ - nazewnictwo trochę mylące - sugeruje pojedyńczego ucznia. Jak byłoby "pupils" to byłoby klarownie.
        vector <Teacher> teacher; // dobrze dobrany typ - nazewnictwo trochę mylące - sugeruje pojedyńczego nauczyciela. Jak byłoby "teachers" to byłoby klarownie.
};






int main()
{
        vector <int> Fib;
        int n;
        cin >> n;
		/*
		A to nawet chciaałoby zadziałać i prawie realizowałoby zadanie 3, ale gdy:
		i == 0 to:
		suma = Fib[0] + Fib[-1] <- to nie jest poprawne
		*/
        for (int i = 0; i > n; i++) // warunek skłapany i > n zawsze jest niespełnione, albo zawsze jest spełnione - cały czas zwiększasz i (i++, czyli i = i + 1)
        {
                int suma = Fib[i] + Fib[i - 1];
				Fib.push_back(suma);

        }
		/*
		Poprawnie byłoby:
        vector <int> Fib;
		Fib.push_back(0); - pierwszy element
		Fib.push_back(1); - drugi element
		for (int i = 1; i < n; i++)
        {
                int suma = Fib[i] + Fib[i - 1];
				Fib.push_back(suma);
        }
		*/
        cout << Fib[n];
        return 0;
}


int n;
int Fib(int n)
{
        if (n == 0)
        {
                return 0;
        }
        else if (n == 1)
        {
                return 1;
        }
        else (n > 1)
        {
                return Fib[n - 1] + Fib[n - 2]; // To wygląda jak przepisane od kogoś np. od Klaudii - nie powinno się dać skompilować - jak byłby Fib(n - 1) + Fib(n - 2) to zadziałałoby
        }
}

int main()
{
        cin >> n;
        Fib(n);
        cout << Fib(n);

                return 0;
}



PN